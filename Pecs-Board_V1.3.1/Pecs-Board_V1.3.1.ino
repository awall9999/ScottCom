//  *** PECS BOARD Ver 1.3.1    ***
//  *** (c)Alain MAUER          ***
//  *** www.alainsprojects.com  ***



#include <EEPROM.h>

const int RowOne = 2;
const int RowTwo = 3;
const int RowThree = 4;
const int RowFour = 5;

const int ColOne = 6;
const int ColTwo = 7;
const int ColThree = 8;
const int ColFour = 9;

const int Led = 10;

byte DFDataFile[] = {0x7E,0xFF,0x06,0x0F,0x00,0x01,0x00,0xEF}; // Dataset to send to the DF Mini player 

int ResultMatrix = 0;
int ButtonMemory = 0;
int VolumeSet =0;
const int AnalogOne=A0;    // BatterieMonitor
boolean BatteryLow = false;


boolean Block = false;

long int time_BattCheck = 0;
long int time_NotInUse = 0;



void setup() {
  Serial.begin(9600);
  //Serial1.begin(9600);
  analogReference(INTERNAL); // Set Aref to 1.1 Volt on Atmege328 and ATmega32u4
  pinMode (RowOne,OUTPUT);pinMode (RowTwo,OUTPUT);pinMode (RowThree,OUTPUT);pinMode (RowFour,OUTPUT);
  pinMode (ColOne,INPUT_PULLUP);pinMode (ColTwo,INPUT_PULLUP);pinMode (ColThree,INPUT_PULLUP);pinMode (ColFour,INPUT_PULLUP);
  digitalWrite(RowOne,HIGH);digitalWrite(RowTwo,HIGH);digitalWrite(RowThree,HIGH);digitalWrite(RowFour,HIGH);
  
  pinMode (Led,OUTPUT);
  
  if (EEPROM.read(0)!= 99) {EEPROM.write(0,99);EEPROM.write(1,25);} //when adress 0 in EEPROM is not 99, then write 99 and init value on adress 1 to 25 for the voice volume. /first time run setup/
  VolumeSet=EEPROM.read(1); //Read adress 0 and set Volume variable
  //Serial.println(VolumeSet);delay(5000);
    
  VolumeVoice(VolumeSet); //Set Volume
  digitalWrite(Led,HIGH); //Power LED on
}

void loop() {
time_BattCheck = millis();
do {
ScanMatrix(); // call void to check what key is pressed
if(ResultMatrix != 0 && Block == false) {time_NotInUse=millis();Block=true;if(ButtonMemory == ResultMatrix){ResultMatrix=0;}ButtonMemory = ResultMatrix;}  //if a key is pressed reset Power On Timer / When same butten pushed, set song to 0
if(ResultMatrix != 0) {if ((unsigned long)(millis() - time_NotInUse) > 2000){SetVolume();} } //when button pushed longer then 2 sec, jump to the set voice volume
if(ResultMatrix == 0 && Block == true) {Block=false;PlayVoice(ButtonMemory);} //on key release deblock new key press and play song seclected

if ((unsigned long)(millis() - time_NotInUse) > 5*60000) {time_NotInUse=millis();PlayVoice(30);} //If Power On Timer reaches 5 min play Sound Nr 30 (Power Off reminder)
delay(100);

 } while ((unsigned long)(millis() - time_BattCheck) < 3*60000); //Check Batterie every 3Minutes

void AkkuCheck();
if (BatteryLow == true) PlayVoice(20); // If Battery is low, then play Sound Nr 20 (Batterie Low)

}

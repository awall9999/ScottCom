const int RowOne = 2;
const int RowTwo = 3;
const int RowThree = 4;
const int RowFour = 5;


const int ColOne = 6;
const int ColTwo = 7;
const int ColThree = 8;
const int ColFour = 9;



int ResultMatrix = 0;

const int AnalogOne=A0;    // BatterieMonitor
boolean BatteryLow = false;

long int time_BattCheck = 0;
long int time_NotInUse = 0;

byte DFDataFile[] = {0x7E,0xFF,0x06,0x0F,0x00,0x01,0x00,0xEF}; 

void setup() {
  Serial.begin(9600);
  
  analogReference(INTERNAL); // Set Aref to 1.1 Volt on Atmege328 and ATmega32u4
  pinMode (RowOne,OUTPUT);pinMode (RowTwo,OUTPUT);pinMode (RowThree,OUTPUT);pinMode (RowFour,OUTPUT);
  pinMode (ColOne,INPUT_PULLUP);pinMode (ColTwo,INPUT_PULLUP);pinMode (ColThree,INPUT_PULLUP);pinMode (ColFour,INPUT_PULLUP);
  digitalWrite(RowOne,HIGH);digitalWrite(RowTwo,HIGH);digitalWrite(RowThree,HIGH);digitalWrite(RowFour,HIGH);
  ResetPlayer();
  delay(1000);
  VolumeVoice();

}

void loop() {
time_BattCheck = millis();
do {
ScanMatrix(); // call void to check what key is pressed
if(ResultMatrix != 0) {time_NotInUse=millis();PlayVoice(ResultMatrix);} //if a key is pressed reset Power On Timer and call void to play sound
if ((unsigned long)(millis() - time_NotInUse) > 5*60000) {time_NotInUse=millis();PlayVoice(30);} //If Power On Timer reaches 1 min play Sound Nr 20 (Power Off reminder)
delay(100);
ResultMatrix = 0;
 } while ((unsigned long)(millis() - time_BattCheck) < 3*60000); //Check Batterie every 3Minutes

void AkkuCheck();
if (BatteryLow == true) PlayVoice(20); // If Battery is low, then play Sound Nr 20 (Batterie Low)

}

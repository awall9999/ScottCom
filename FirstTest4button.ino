#include <avr/sleep.h>

const int InterRupt = 2;
const int ButtonOne = 3;
const int ButtonTwo = 4;
const int ButtonThree = 5;
const int ButtonFour = 6;
const int PowerLed = 7;
const int PowerMP3 = 8;
boolean Lock = false;
unsigned long TimeNow = 0;
unsigned long Delay = 30000;
byte DFData[] = {0x7E,0xFF,0x06,0x03,0x00,0x00,0x01,0xEF}; //Play sound Nr DFData[6]

void Speak() {
  for (int i = 0; i <= 7; i++) {
   Serial.write(DFData[i]); 
   }
}
void Nothing(){}

void sleep()
      {

          sleep_enable();    // Set sleep enable (SE) bit:
          attachInterrupt(digitalPinToInterrupt(InterRupt), Nothing, CHANGE);   // Set pin 2 as interrupt and attach handler:
          set_sleep_mode(SLEEP_MODE_PWR_DOWN);    // define our preferred sleep mode:
          digitalWrite(PowerLed,LOW);
          digitalWrite(PowerMP3,LOW);
          sleep_cpu();     

          detachInterrupt(digitalPinToInterrupt(InterRupt));
          digitalWrite(PowerLed,HIGH);
          digitalWrite(PowerMP3,HIGH);
      }

void setup() {
  Serial.begin(9600); 
  
  pinMode (ButtonOne,INPUT);
  pinMode (ButtonTwo,INPUT);
  pinMode (ButtonThree,INPUT);
  pinMode (ButtonFour,INPUT);
  pinMode (InterRupt,INPUT);
  pinMode (PowerLed,OUTPUT);
  digitalWrite(PowerLed,HIGH);
  pinMode (PowerMP3,OUTPUT);
  digitalWrite(PowerMP3,HIGH);
  TimeNow = millis();
}

void loop() {
 
do {
    
   
 
 if (digitalRead(ButtonOne) == 1 && Lock == false ) {DFData[6] = (0x01);Speak();Lock = true;TimeNow = millis();}
 if (digitalRead(ButtonTwo) == 1 && Lock == false ) {DFData[6] = (0x02);Speak();Lock = true;TimeNow = millis();}
 if (digitalRead(ButtonThree) == 1 && Lock == false ) {DFData[6] = (0x03);Speak();Lock = true;TimeNow = millis();}
 if (digitalRead(ButtonFour) == 1 && Lock == false ) {DFData[6] = (0x04);Speak();Lock = true;TimeNow = millis();}
 if (digitalRead(ButtonOne) == 0 && digitalRead(ButtonTwo) == 0 && digitalRead(ButtonThree) == 0 && digitalRead(ButtonFour) == 0 && Lock == true ) {Lock = false;}
 } while ((unsigned long)(millis() - TimeNow) < Delay); 
 
 delay(2000);
 sleep();
}

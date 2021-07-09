//https://www.peacesoftware.de/einigewerte/spannungsteiler.html

void AkkuCheck(){
float Voltage = ((float)analogRead(AnalogOne) * 1.1) / 1024.0;
Voltage=(Voltage/0.363); // 12K/33K
Serial.println(Voltage,4); 
if (Voltage < 3.3) {BatteryLow = true;} else {BatteryLow = false;};  
}

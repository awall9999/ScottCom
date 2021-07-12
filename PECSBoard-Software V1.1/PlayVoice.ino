//  https://ttsmp3.com/

void PlayVoice(int Select){
  byte DFDataFile[] = {0x7E,0xFF,0x06,0x0F,0x00,0x01,0x00,0xEF}; // Dataset 6 Song Number 
  DFDataFile[3] = (0x0F);
  DFDataFile[6] = (Select);
  
  
  

  // Send Data to DF mini Sound module
  for (int i = 0; i <= 7; i++) {
                                Serial.write(DFDataFile[i]); 
                               }
                               delay(1000);
  
}


void VolumeVoice(int Select){
  byte DFDataFile[] = {0x7E,0xFF,0x06,0x06,0x00,0x00,0x00,0xEF}; // Dataset 6 Song Number 
  DFDataFile[3] = (0x06); 
  DFDataFile[6] = (Select);
  
  
  

  // Send Data to DF mini Sound module
  for (int i = 0; i <= 7; i++) {
                                Serial.write(DFDataFile[i]); 
                               }
                               
  
}

void ResetVoice(){
  byte DFDataFile[] = {0x7E,0xFF,0x06,0x0C,0x00,0x00,0x00,0xEF}; // Dataset 6 Song Number 
  DFDataFile[3] = (0x0C);
  
  
  

  // Send Data to DF mini Sound module
  for (int i = 0; i <= 7; i++) {
                                Serial.write(DFDataFile[i]); 
                               }
                               
  
}

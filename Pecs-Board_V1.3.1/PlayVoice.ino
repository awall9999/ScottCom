//  https://ttsmp3.com/

void PlayVoice(int Select){
  
  DFDataFile[3] = (0x0F);
  DFDataFile[6] = (Select);
  SendData();  
}


void VolumeVoice(int Select){
  
  DFDataFile[3] = (0x06); 
  DFDataFile[6] = (Select);
  SendData();  
}

void ResetVoice(){
  
  DFDataFile[3] = (0x0C);
  SendData();  
}

void SendData(){
   // Send Data to DF mini Sound module
  for (int i = 0; i <= 7; i++) {
                                Serial.write(DFDataFile[i]); 
                               }
                                delay(1000);
}

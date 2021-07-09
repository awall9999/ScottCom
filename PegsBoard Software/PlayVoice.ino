//  https://ttsmp3.com/

void PlayVoice(int Select){
 
  DFDataFile[3] = (0x0F);
  DFDataFile[6] = (Select);
  DataToPlayer();
  delay(1000);
 }


void VolumeVoice(){
  
  
  DFDataFile[3] = (0x06);
  DFDataFile[6] = (30);
  DataToPlayer();
 }

void ResetPlayer(){
  
  
  DFDataFile[3] = (0x0C);
  DataToPlayer();
 }

void DataToPlayer(){
  // Send Data to DF mini Sound module
  for (int i = 0; i <= 7; i++) {
                                Serial1.write(DFDataFile[i]); 
                               }
                               
 }

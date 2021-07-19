void SetVolume(){
 
 if(ResultMatrix == 1) {VolumeSet=10;UpdateVolume();}
 if(ResultMatrix == 2) {VolumeSet=18;UpdateVolume();}
 if(ResultMatrix == 3) {VolumeSet=25;UpdateVolume();}
 if(ResultMatrix == 4) {VolumeSet=30;UpdateVolume();}
 time_NotInUse=millis(); 
 ButtonMemory=0; 
}

void UpdateVolume(){
 VolumeVoice(VolumeSet);
 PlayVoice(ResultMatrix);
 EEPROM.update(0, VolumeSet); //If Volume has changed, Write new value to adress 0
  
}

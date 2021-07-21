// In this Section you can set the new Volume
void SetVolume(){
 int Vol[] = {0,10,18,25,30};
 
 if(ResultMatrix < 5) {VolumeSet=Vol[ResultMatrix];UpdateVolume();} // if Button 1-4 is pressed, set volume to datafile Vol
 time_NotInUse=millis(); 
 ButtonMemory=0; 
}

void UpdateVolume(){
 VolumeVoice(VolumeSet);
 PlayVoice(ResultMatrix);
 EEPROM.update(1, VolumeSet); //If Volume has changed, Write new value to adress 0
  
}

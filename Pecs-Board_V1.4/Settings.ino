// In this Section you can set the new Volume
void SetVolume(){
 int Vol[] = {0,10,18,25,30};
 digitalWrite(Led,LOW); //Power LED off
 PlayVoice(0);
 VolumeSet=Vol[ResultMatrix];
 VolumeVoice(VolumeSet);
 time_NotInUse=millis(); 
 digitalWrite(Led,HIGH);
 WriteEEprom();
 }

void SetFolder(){
 digitalWrite(Led,LOW); //Power LED off
 PlayVoice(0);
 do {
     ScanMatrix();
    }while (ResultMatrix == 16);
 
 do {
     ScanMatrix();
    }while (ResultMatrix == 0);
    
 ButtonMemory = ResultMatrix;
 FolderSet=ResultMatrix;
 digitalWrite(Led,HIGH);
 WriteEEprom();
 }

void WriteEEprom(){
 
 EEPROM.update(1, VolumeSet); //If Volume has changed, Write new value to adress 1
 EEPROM.update(2, FolderSet); //If Folder has changed, Write new value to adress 2
  
}

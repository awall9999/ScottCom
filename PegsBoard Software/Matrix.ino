void ScanMatrix(){
  byte ROW[] = {RowOne, RowTwo, RowThree, RowFour};
  byte COL[] = {ColOne, ColTwo, ColThree, ColFour};
  for (int i = 0; i <= 3 ; i++) {
                                digitalWrite(ROW[i],LOW);
                                
                                for (int a = 0; a <= 3 ; a++) {
                                                              if (digitalRead(COL[a]) == LOW) ResultMatrix = (1+(a*4))+i;
                                                              }
                                
                                digitalWrite(ROW[i],HIGH);
                                }
//Serial.println(ResultMatrix);
}

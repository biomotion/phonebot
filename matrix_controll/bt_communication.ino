byte readCommand(){
  const byte BUFF_LEN = 100;
  if(Serial.available()){
    delay(200);
    char buff[BUFF_LEN];
    byte i;
    for(i=0; Serial.available() && i<BUFF_LEN; i++){
      buff[i] = Serial.read();
    }
    if(i == BUFF_LEN)
      buff[BUFF_LEN-1] = '\0';
    else
      buff[i] = '\0';
    Serial.println(buff);
    strcpy(command, buff);
    return 1;
  }
  else
    return 0;
}


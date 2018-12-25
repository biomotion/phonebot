void printStatus(){
  Serial.print("VER: ");
  Serial.println(MXctrl.getVersion());
  Serial.print("MANUFACTURER: ");
  Serial.println(MXctrl.getManufacturer());
  Serial.print("TYPE: ");
  Serial.println(MXctrl.getType());
  Serial.print("STATUS: ");
  Serial.println(MXctrl.getStatus(), BIN);
  Serial.print("BATTERY: ");
  Serial.println(MXctrl.getBattery());
}

//
void car_cmd(int gain, int offset){
    int l_speed = -gain+offset;
    int r_speed = gain+offset;
    Serial.print("L speed: ");
    Serial.println(l_speed);
    Serial.print("R speed: ");
    Serial.println(r_speed);
    MXctrl.motorSpeed(Motor1, l_speed);
    MXctrl.motorSpeed(Motor3, r_speed); 
    MXctrl.motorSpeed(Motor1, l_speed);
    MXctrl.motorSpeed(Motor3, r_speed); 
}

void square_dance(){
  for(byte i=0; i<4; i++){
    car_cmd(15, 0);
    delay(1000);
    car_cmd(0, 7);
    delay(1500);
  }
  car_cmd(0, 0);
}

void dance(){
  for(byte i=0; i<10; i++){
    car_cmd(0, i*5);
    delay((i+1)*200);
    car_cmd(0, -i*5);
    delay((i+1)*200);
  }
  car_cmd(0, 0);
}
void takePic(){
  //run forward
  car_cmd(15, 0);
  delay(2000);
  //turn around
  car_cmd(0, 10);
  delay(1500);
  car_cmd(0, 0);
  delay(10000);
  
  car_cmd(0, -10);
  delay(1500);
  //run forward
  car_cmd(-15, 0);
  delay(2000);
  car_cmd(0, 0);
}

void drunkDrive(){
  for(int i=0; i<5; i++){
    for(int j=-10; j<10; j++){
      car_cmd(15, j);
      delay(15); 
    }
    for(int j=10; j>-10; j--){
      car_cmd(15, j);
      delay(15); 
    }
  }
  car_cmd(0, 0);
}


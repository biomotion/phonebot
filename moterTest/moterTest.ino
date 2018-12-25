#include "MatrixMini.h"

MatrixMini Mini;
MiniHitechCtrl MXctrl;

void setup() {
  // put your setup code here, to run once:
  Mini.begin();
  MXctrl.begin();
  Serial.begin(9600);
  MXctrl.setTimeout(0);
  MXctrl.motorMode(Motor3, MODE_POWER_BRAKE);
  Serial.println("\n < Setup done > \n");
}

void loop() {
  // put your main code here, to run repeatedly:
  for(int i=-50; i<50; i+=10){
    Serial.println(i);
    MXctrl.motorSpeed(Motor3,i);
    MXctrl.motorSpeed(Motor3,i);
    delay(1000);
  } 
  for(int i=50; i>-50; i-=10){
    Serial.println(i);
    MXctrl.motorSpeed(Motor3,i);
    MXctrl.motorSpeed(Motor3,i);
    delay(1000);
  }
}

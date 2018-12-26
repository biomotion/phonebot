#include "MatrixMini.h"

MatrixMini Mini;
MiniHitechCtrl MXctrl;
char command[100];
byte tmp;

void setup() {
  Mini.begin();
  MXctrl.begin();
  Serial.begin(9600);

  Serial.println("\n Matrix Mini Hitechnic Matrix Controller Test \n");
  Serial.println("Starting Up ... ");
  printStatus();

  MXctrl.setTimeout(0);

  // MODE_POWER_FLOAT, MODE_POWER_BREAK, MODE_SPEED, MODE_POSITION
  MXctrl.motorMode(Motor1, MODE_SPEED);
  MXctrl.motorMode(Motor3, MODE_SPEED);

  Serial.println("\n < Setup done > \n");
  delay(2000);
}




void loop() {
  if(readCommand()){
    if(strcmp(command, "status") == 0)
      printStatus();
    else if(command[0] == 'U')
      car_cmd(15, 0);
    else if(command[0] == 'D')
      car_cmd(-15, 0);
    else if(command[0] == 'L')
      car_cmd(0, 15);
    else if(command[0] == 'R')
      car_cmd(0, -15);
    else if(command[0] == 'S')
      car_cmd(0, 0);
    else if(strcmp(command, "takepicture") == 0)
      takePic();
    else if(strcmp(command, "dance") == 0)
      dance();
    else if(strcmp(command, "square") == 0)
      square_dance();
    else if(strcmp(command, "drunkdriving") == 0)
      drunkDrive();
  }
//  Serial.println("forward");
//  car_cmd(20, 0);
//  delay(1000);
//  Serial.println("backward");
//  car_cmd(-20, 0);
//  delay(1000);
//  Serial.println("stop");
//  car_cmd(0, 0);
//  delay(1000);
}

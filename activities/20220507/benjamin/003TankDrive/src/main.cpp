/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       VEX                                                       */
/*    Created:      Wed Sep 25 2019                                           */
/*    Description:  Tank Drive                                                */
/*    This sample allows you to control the V5 Clawbot using the both         */
/*    joystick. Adjust the deadband value for more accurate movements.        */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller
// LeftMotor            motor         1
// RightMotor           motor         10
// ClawMotor            motor         3
// ArmMotor             motor         8
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;
bool leftdead(int leftMotorSpeed){
  if(abs(leftMotorSpeed) < 5){
    return true;
  }
  return false;
}
bool rightdead(int rightMotorSpeed){
  if(abs(rightMotorSpeed) < 5){
    return true;
  }
  return false;
}
void Rforward(){
  RightMotor.spin(forward);
}
void Lforward(){
  LeftMotor.spin(forward);
}
void stopR(){
  RightMotor.setVelocity(0, percent);
}
void stopL(){
  LeftMotor.setVelocity(0, percent);
}
int getaxiseR(){
  int gar = Controller1.Axis2.position();
  return gar;
}
int getaxisL(){
  int gal = Controller1.Axis3.position();
  return gal;
}
int main() {
  vexcodeInit();
  int deadband = 5;
  
  while (true) {
    int leftMotorSpeed = getaxisL();
    int rightMotorSpeed = getaxiseR();

    if(leftdead(leftMotorSpeed) == true){
      stopL();
    } 
    else {
      LeftMotor.setVelocity(leftMotorSpeed, percent);
    }
    if(rightdead(rightMotorSpeed) == true){
      stopR();
    } 
    else {
      RightMotor.setVelocity(rightMotorSpeed, percent);
    }

    Lforward();
    Rforward();

    wait(25, msec);
  }
}

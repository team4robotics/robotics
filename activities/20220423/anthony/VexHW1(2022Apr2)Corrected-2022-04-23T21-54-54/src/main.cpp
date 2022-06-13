/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       C:\Users\Antho                                            */
/*    Created:      Mon Apr 18 2022                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Drivetrain           drivetrain    1, 10           
// BumperAFwdStop       bumper        A               
// BumperBTurn          bumper        B               
// Controller1          controller                    
// ---- END VEXCODE CONFIGURED DEVICES ----



#include "vex.h"

using namespace vex;

void moveForward()
{
  Drivetrain.drive(forward);
}

void stopDrive()
{
  Drivetrain.stop();
}

void turnRight()
{
  Drivetrain.turn(right);
}

void turnLeft()
{
  Drivetrain.turn(left);
}

void moveBack(){
  Drivetrain.drive(reverse);
}


int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();

  BumperAFwdStop.pressed(moveForward);
  BumperAFwdStop.released(stopDrive);
  BumperBTurn.pressed(turnRight);
  BumperBTurn.released(stopDrive);
  Controller1.ButtonUp.pressed(moveForward);
  Controller1.ButtonDown.pressed(moveBack);
  Controller1.ButtonRight.pressed(turnRight);
  Controller1.ButtonLeft.pressed(turnLeft);
 

  /*while (true){
  if(BumperAFwdStop.pressing()){
    Drivetrain.drive(forward);
  }
  else{
    Drivetrain.stop();
  }
  if(BumperBTurn.pressing()){
    Drivetrain.turn(right);
  }
  else{
    Drivetrain.stop();
  }
}
*/
}

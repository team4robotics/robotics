/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       C:\Users\Benjamin Wang                                    */
/*    Created:      Sat Apr 23 2022                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// BumperA              bumper        A               
// BumperB              bumper        B               
// Drivetrain           drivetrain    1, 10           
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

void moveForward()
{
  Drivetrain.drive(forward);
}

void moveRight()
{
  Drivetrain.turn(right);
}
void stopthecap(){
    Drivetrain.stop();
}
int main() {
  vexcodeInit();
  BumperA.pressed(moveForward);
  BumperA.released(stopthecap);
  BumperB.pressed(moveRight);
  BumperB.released(stopthecap);
}

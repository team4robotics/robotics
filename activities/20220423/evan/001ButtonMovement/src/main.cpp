/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       C:\Users\Evan                                             */
/*    Created:      Mon Apr 11 2022                                           */
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

void stopMoving()
{
  Drivetrain.stop();
}

void turnLeft()
{
  Drivetrain.turn(right);
}

int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  
  BumperA.pressed(moveForward);
  BumperA.released(stopMoving);
  BumperB.pressed(turnLeft);
  BumperB.released(stopMoving);

  return 0;
}

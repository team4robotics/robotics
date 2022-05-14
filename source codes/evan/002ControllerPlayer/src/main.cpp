/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       C:\Users\Evan                                             */
/*    Created:      Sat Apr 23 2022                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Drivetrain           drivetrain    1, 10           
// Controller1          controller                    
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

void moveForward()
{
  Drivetrain.drive(forward);
}

void moveBackward()
{
  Drivetrain.drive(reverse);
}

void turnRight()
{
  Drivetrain.turn(right);
}

void turnLeft()
{
  Drivetrain.turn(left);
}

void stopMoving()
{
  Drivetrain.stop();
}

int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  
  Controller1.ButtonUp.pressed(moveForward);
  Controller1.ButtonUp.released(stopMoving);
  Controller1.ButtonDown.pressed(moveBackward);
  Controller1.ButtonDown.released(stopMoving);
  Controller1.ButtonRight.pressed(turnRight);
  Controller1.ButtonRight.released(stopMoving);
  Controller1.ButtonLeft.pressed(turnLeft);
  Controller1.ButtonLeft.released(stopMoving);

  return 0;
}

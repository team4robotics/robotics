/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       C:\Users\Evan                                             */
/*    Created:      Wed May 04 2022                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller                    
// LeftMotor            motor         1               
// RightMotor           motor         10              
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

void rightMovement()
{
  int deadband = 5;
  int rightMotorSpeed = Controller1.Axis2.position();

  if (abs(rightMotorSpeed) < deadband) {
      // Set the speed to zero
      RightMotor.setVelocity(0, percent);
    } else {
      // Set the speed to rightMotorSpeed
      RightMotor.setVelocity(rightMotorSpeed, percent);
    }

  RightMotor.spin(forward);
}

void leftMovement()
{
  int deadband = 5;
  int leftMotorSpeed = Controller1.Axis3.position();

  if (abs(leftMotorSpeed) < deadband) {
      // Set the speed to zero.
      LeftMotor.setVelocity(0, percent);
    } else {
      // Set the speed to leftMotorSpeed
      LeftMotor.setVelocity(leftMotorSpeed, percent);
    }
  
  LeftMotor.spin(forward);
}

void leftForward()
{
  LeftMotor.setPosition(0, degrees);
  LeftMotor.spinToPosition(180, degrees);
}

void leftBackward()
{
  LeftMotor.setPosition(0, degrees);
  LeftMotor.spinToPosition(-180, degrees);
}

void rightForward()
{
  RightMotor.setPosition(0, degrees);
  RightMotor.spinToPosition(180, degrees);
}

void rightBackward()
{
  RightMotor.setPosition(0, degrees);
  RightMotor.spinToPosition(-180, degrees);
}


int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();

  Controller1.Axis2.changed(rightMovement);
  Controller1.Axis3.changed(leftMovement);

  Controller1.ButtonL1.pressed(leftForward);
  Controller1.ButtonL2.pressed(leftBackward);
  Controller1.ButtonR1.pressed(rightForward);
  Controller1.ButtonR2.pressed(rightBackward);
}
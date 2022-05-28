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
void moveLeft()
{
  Drivetrain.turn(left);
}
void moveBack()
{
  Drivetrain.drive(reverse);
}
void stop(){
    Drivetrain.stop();
}
int main() {
  vexcodeInit();
  Controller1.ButtonX.pressed(moveForward);
  Controller1.ButtonX.released(stop);
  Controller1.ButtonA.pressed(moveRight);
  Controller1.ButtonA.released(stop);
  Controller1.ButtonY.pressed(moveLeft);
  Controller1.ButtonY.released(stop);
  Controller1.ButtonB.pressed(moveBack);
  Controller1.ButtonB.released(stop);
}

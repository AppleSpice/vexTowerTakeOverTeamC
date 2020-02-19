#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
motor LeftWheels = motor(PORT1, ratio36_1, false);
motor RightWheels = motor(PORT10, ratio36_1, true);
motor StrafeWheels = motor(PORT2, ratio36_1, true);
motor LeftLift = motor(PORT11, ratio36_1, true);
motor RightLift = motor(PORT20, ratio36_1, false);
motor LeftIntake = motor(PORT3, ratio18_1, true);
bumper LiftBumper = bumper(Brain.ThreeWirePort.H);
controller Controller1 = controller(primary);
motor RightIntake = motor(PORT18, ratio18_1, false);
gyro Gyro = gyro(Brain.ThreeWirePort.A);
motor TrayTilter = motor(PORT6, ratio36_1, true);

// VEXcode generated functions



/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Text.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  // nothing to initialize
}
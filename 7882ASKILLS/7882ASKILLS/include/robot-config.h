using namespace vex;

extern brain Brain;

// VEXcode devices
extern motor LeftWheels;
extern motor RightWheels;
extern motor StrafeWheels;
extern motor LeftLift;
extern motor RightLift;
extern motor LeftIntake;
extern bumper LiftBumper;
extern controller Controller1;
extern motor RightIntake;
extern gyro Gyro;
extern motor TrayTilter;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Text.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );
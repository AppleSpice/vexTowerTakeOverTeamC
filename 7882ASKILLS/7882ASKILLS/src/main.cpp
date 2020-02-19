/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       VEX                                                       */
/*    Created:      Thu Sep 26 2019                                           */
/*    Description:  Competition Template                                      */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// LeftWheels           motor         1               
// RightWheels          motor         10              
// StrafeWheels         motor         2               
// LeftLift             motor         11              
// RightLift            motor         20              
// LeftIntake           motor         3               
// LiftBumper           bumper        H               
// Controller1          controller                    
// RightIntake          motor         18              
// Gyro                 gyro          A               
// TrayTilter           motor         6               
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

// A global instance of competition
competition Competition;

// define your global instances of motors and other devices here

/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the V5 has been powered on and        */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/

void pre_auton(void) {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();

  // All activities that occur before the competition starts
  // Example: clearing encoders, setting servo positions, ...
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void autonomous( void ) {
    
    Brain.Screen.printAt(1,40,"Gyro: %f" , Gyro.value(rotationUnits::deg));
    
    //Side: Red
    LeftIntake.spin(directionType::fwd,75,velocityUnits::pct);
    RightIntake.spin(directionType::fwd,75,velocityUnits::pct);
    task::sleep(2000);
    //intake takes tray out
    
    LeftWheels.spin(directionType::fwd,55,velocityUnits::pct);
    RightWheels.spin(directionType::fwd,55,velocityUnits::pct);
    LeftIntake.spin(directionType::rev,70,velocityUnits::pct);
    RightIntake.spin(directionType::rev,70,velocityUnits::pct);
    task::sleep(3800);

    LeftIntake.spin(directionType::rev,70,velocityUnits::pct);
    RightIntake.spin(directionType::rev,70,velocityUnits::pct);
    LeftWheels.stop(brakeType::hold);
    RightWheels.stop(brakeType::hold);
    task::sleep(1000);


    //robot moves forward while intake picks up 4 cubes

    LeftWheels.spin(directionType::rev,90,velocityUnits::pct);
    RightWheels.spin(directionType::rev,90,velocityUnits::pct);
    task::sleep(1750);

    LeftWheels.stop(brakeType::hold);
    RightWheels.stop(brakeType::hold);
    task::sleep(10);

    LeftWheels.spin(directionType::fwd,51,velocityUnits::pct);
    RightWheels.spin(directionType::rev,51,velocityUnits::pct);
    task::sleep(1600);
    //robot turns torward goal zone

    LeftWheels.stop(brakeType::hold);
    RightWheels.stop(brakeType::hold);
    LeftIntake.stop(brakeType::coast);
    RightIntake.stop(brakeType::coast);

    task::sleep(10);

    LeftWheels.spin(directionType::fwd,60,velocityUnits::pct);
    RightWheels.spin(directionType::fwd,60,velocityUnits::pct);
    task::sleep(1000);

    LeftWheels.stop(brakeType::hold);
    RightWheels.stop(brakeType::hold);
    LeftIntake.stop(brakeType::coast);
    RightIntake.stop(brakeType::coast);
    task::sleep(10);

    TrayTilter.spin(directionType::fwd,45,velocityUnits::pct);
    LeftIntake.stop(brakeType::coast);
    RightIntake.stop(brakeType::coast);
    task::sleep(1800);
    
    //robot puts cubes in goal zone
    
    TrayTilter.stop(brakeType::hold);
    LeftIntake.spin(directionType::fwd,20,velocityUnits::pct);
    RightIntake.spin(directionType::fwd,20,velocityUnits::pct);
    task::sleep(1200);



    LeftWheels.spin(directionType::rev,100,velocityUnits::pct);
    RightWheels.spin(directionType::rev,100,velocityUnits::pct);
    LeftIntake.spin(directionType::fwd,50,velocityUnits::pct);
    RightIntake.spin(directionType::fwd,50,velocityUnits::pct);
    task::sleep(2000);
    //robot backs up (MATCH CODE ENDS HERE)

    LeftWheels.stop(brakeType:: hold);
    RightWheels.stop(brakeType::hold);
    LeftIntake.stop(brakeType::hold);
    RightIntake.stop(brakeType::hold);
    //put tray back
    

  //   //turn right until facing pre load
  //   TrayTilter.spin(directionType::rev,45,velocityUnits::pct);
  //   LeftWheels.spin(directionType::fwd,51,velocityUnits::pct);
  //   RightWheels.spin(directionType::rev,51,velocityUnits::pct);
  //   task::sleep(1600);
  //   TrayTilter.stop(brakeType::hold);
  //   LeftWheels.stop(brakeType:: hold);
  //   RightWheels.stop(brakeType::hold);
  // //go forward and intake preload
  //   LeftWheels.spin(directionType::fwd,55,velocityUnits::pct);
  //   RightWheels.spin(directionType::fwd,55,velocityUnits::pct);
  //   LeftIntake.spin(directionType::rev,70,velocityUnits::pct);
  //   RightIntake.spin(directionType::rev,70,velocityUnits::pct);
  //   task::sleep(1200);
  //   LeftWheels.stop(brakeType:: hold);
  //   RightWheels.stop(brakeType::hold);
  //   LeftIntake.stop(brakeType::hold);
  //   RightIntake.stop(brakeType::hold);
  // //back up until in line with alience
  // LeftWheels.spin(directionType::rev,55,velocityUnits::pct);
  // RightWheels.spin(directionType::rev,55,velocityUnits::pct);
  // task::sleep(1200);
  // LeftWheels.stop(brakeType:: hold);
  // RightWheels.stop(brakeType::hold);
  // //turn 90 degrees to the left 
  // LeftWheels.spin(directionType::rev,51,velocityUnits::pct);
  // RightWheels.spin(directionType::fwd,51,velocityUnits::pct);
  // task::sleep(3200);
  // LeftWheels.stop(brakeType:: hold);
  // RightWheels.stop(brakeType::hold);
  // //go forward
  // LeftWheels.spin(directionType::fwd,55,velocityUnits::pct);
  // RightWheels.spin(directionType::fwd,55,velocityUnits::pct);
  // task::sleep(1800);
  // LeftWheels.stop(brakeType:: hold);
  // RightWheels.stop(brakeType::hold);  
  // //lift up and put cube in tower
  // LeftLift.spin(directionType::fwd,55,velocityUnits::pct);
  // RightLift.spin(directionType::fwd,55,velocityUnits::pct);
  // task::sleep(1000);
  // LeftLift.stop(brakeType:: hold);
  // RightLift.stop(brakeType::hold);
  // //back up and and bring lift down
  // LeftWheels.spin(directionType::fwd,55,velocityUnits::pct);
  // RightWheels.spin(directionType::fwd,55,velocityUnits::pct);
  // task::sleep(1000);
  // LeftLift.spin(directionType::rev,55,velocityUnits::pct);
  // RightLift.spin(directionType::rev,55,velocityUnits::pct);
  // task::sleep(1000);
  // LeftWheels.stop(brakeType:: hold);
  // RightWheels.stop(brakeType::hold);
  // LeftLift.stop(brakeType:: hold);
  // RightLift.stop(brakeType::hold);

  //spin left 90 degrees
  //strafe left until directly infront of tower
  //go forward and bring cube into intake 
  //lift cube up
  //go forward 
  //put cube in tower

  //back up and bring lift down 
  //strafe to the right 
  //go forward intaking 4 cubes
  //turn 45 degrees to the right 
  //go forward and stack cubes





  




    
    
  // ..........................................................................
  // Insert autonomous user code here.
  // ..........................................................................
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void usercontrol(void) {
  // User control code here, inside the loop
  while (1) {

    /*

Motors:
___________
Number Ports:

Port 1: LeftWheels motor: Powers 2 wheels connected by a gear train (1:1) on the
left side of the robot for driving

Port 2: StrafeWheels motor:Powers 2 wheels connected by a shaft in the middle of
the robot to strafe the robot side to side

Port 10: RightWheels motor: Powers 2 wheels connected by a gear train (1:1) on
the right side of the robot for driving

Port 5: LeftLift motor: Powers the left side of the lift

Port 8: RightLift motor: Powers the right side of the lift

Port 3: LeftIntake motor: Powers the left side of the intake

Port 9: RightIntake motor: Powers the right side of the intake

Port 6: TrayTilter motor: Powers the tray hinge to set it down

Port 11: Robot Radio

___________

Letter Ports:

Port H: LiftBumper sensor: A Bumper Switch that will prevent the lift from going
down while pressed

Port A: Gyro sensor: A gyro sensor that will show the degrees of rotation

___________
*/

    // While the program is running

    LeftWheels.setStopping(brakeType::brake); // Sets the LeftWheels motor to braketype "brake"
    RightWheels.setStopping(brakeType::brake); // Sets the RightWheels motor to braketype "brake"
    StrafeWheels.setStopping(brakeType::brake); // Sets the StrafeWheels motor to braketype "brake"

    // Code for the wheels
    // Wheel base consists of 3 motors (LeftWheels, RightWheels, StrafeWheels)

    LeftWheels.spin(directionType::fwd,Controller1.Axis3.position(percentUnits::pct),velocityUnits::pct);
    // Spins the wheels on the left side forwards and backwards

    RightWheels.spin(directionType::fwd,Controller1.Axis2.position(percentUnits::pct),velocityUnits::pct);
    // Spins the wheels on the right side forwards and backwards

    StrafeWheels.spin(directionType::rev,Controller1.Axis4.position(percentUnits::pct),velocityUnits::pct);
    // Spins the wheels on the right side forwards and backwards

    // End of wheel code

    // Code for the lift

    if (Controller1.ButtonR1.pressing()) {
      // If the top left button is pressing
      LeftLift.spin(directionType::fwd, 100, velocityUnits::pct);
      RightLift.spin(directionType::fwd, 100, velocityUnits::pct);
      // Moves both lift motors up

      Controller1.Screen.print("Lift Up");

    }

    else if (Controller1.ButtonL1.pressing()) {
      // If the bottom left button is pressing
      LeftLift.spin(directionType::rev, 80, velocityUnits::pct);
      RightLift.spin(directionType::rev, 80, velocityUnits::pct);
    }

    else {
      // If nothing is being pressed
      LeftLift.stop(brakeType::hold);
      RightLift.stop(brakeType::hold);
      // Stops both motors slowely and then holds
    }

    // Code for the intake

    if (Controller1.ButtonL2.pressing()) {
      // If the left button is pressing
      LeftIntake.spin(directionType::fwd, 90, velocityUnits::pct);
      RightIntake.spin(directionType::fwd, 90, velocityUnits::pct);
      // Moves both lift motors up

    }

    else if (Controller1.ButtonR2.pressing()) {
      // If the right button is pressing
      LeftIntake.spin(directionType::rev, 90, velocityUnits::pct);
      RightIntake.spin(directionType::rev, 90, velocityUnits::pct);
      // Moves both lift motors down

    }

    else {
      // If nothing is being pressed
      LeftIntake.stop(brakeType::hold);
      RightIntake.stop(brakeType::hold);
      // Immediatly Stops both motors
    }


    if (Controller1.ButtonUp.pressing()){
      //If the "Up" arrow is pressing
      TrayTilter.spin(directionType::fwd, 45, velocityUnits::pct);
    }

    else if (Controller1.ButtonDown.pressing()){
      //If the "Down" arrow is pressing
      TrayTilter.spin(directionType::rev, 45, velocityUnits::pct);
    }

    else{
      TrayTilter.stop(brakeType::hold);
    }




    while (LiftBumper.pressing()) {
      // While the program is running

      // Code for the wheels
      // Wheel base consists of 3 motors (LeftWheels, RightWheels, StrafeWheels)

      LeftWheels.spin(directionType::fwd,Controller1.Axis3.position(percentUnits::pct),velocityUnits::pct);
      // Spins the wheels on the left side forwards and backwards

      RightWheels.spin(directionType::fwd,Controller1.Axis2.position(percentUnits::pct),velocityUnits::pct);
      // Spins the wheels on the right side forwards and backwards

      StrafeWheels.spin(directionType::rev,Controller1.Axis4.position(percentUnits::pct),velocityUnits::pct);
      // Spins the wheels on the right side forwards and backwards

      // End of wheel code

      // Code for the lift

      if (Controller1.ButtonR1.pressing()) {
        // If the top left button is pressing
        LeftLift.spin(directionType::fwd, 100, velocityUnits::pct);
        RightLift.spin(directionType::fwd, 100, velocityUnits::pct);
        // Moves both lift motors up

        Controller1.Screen.print("Lift Up");

      }

      else {
        // If nothing is being pressed
        LeftLift.stop(brakeType::hold);
        RightLift.stop(brakeType::hold);
        // Stops both motors slowely and then holds
      }

      // Code for the intake

      if (Controller1.ButtonL2.pressing()) {
        // If the left button is pressing
        LeftIntake.spin(directionType::fwd, 90, velocityUnits::pct);
        RightIntake.spin(directionType::fwd, 90, velocityUnits::pct);
        // Moves both lift motors up

      }

      else if (Controller1.ButtonR2.pressing()) {
        // If the right button is pressing
        LeftIntake.spin(directionType::rev, 90, velocityUnits::pct);
        RightIntake.spin(directionType::rev, 90, velocityUnits::pct);
        // Moves both lift motors down

      }

      else {
        // If nothing is being pressed
        LeftIntake.stop(brakeType::hold);
        RightIntake.stop(brakeType::hold);
        // Immediatly Stops both motors
      }




    if (Controller1.ButtonUp.pressing()){
      //If the "Up" arrow is pressing
      TrayTilter.spin(directionType::fwd, 45, velocityUnits::pct);
    }

    else if (Controller1.ButtonDown.pressing()){
      //If the "Down" arrow is pressing
      TrayTilter.spin(directionType::rev, 45, velocityUnits::pct);
    }

    else{
      TrayTilter.stop(brakeType::hold);
    }
    }
          
      
      
      
    // This is the main execution loop for the user control program.
    // Each time through the loop your program should update motor + servo 
    // values based on feedback from the joysticks.

    // ........................................................................
    // Insert user code here. This is where you use the joystick values to 
    // update your motors, etc.
    // ........................................................................
 
    vex::task::sleep(20); //Sleep the task for a short amount of time to prevent wasted resources. 
  }
}

//
// Main will set up the competition functions and callbacks.
//
int main() {
  // Set up callbacks for autonomous and driver control periods.
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  // Run the pre-autonomous function.
  pre_auton();

  // Prevent main from exiting with an infinite loop.
  while (true) {
    wait(100, msec);
  }
}

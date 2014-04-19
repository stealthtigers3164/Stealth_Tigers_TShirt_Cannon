#include "WPILib.h"
#include "cannon.h"

////
//Code originally written by Brendan Gregos on 04/16/2014 for FRC Team 3164.
////

/*
PORT ASSIGNMENT LIST:

--Driver Station USB Devices--
1:Right Joystick
2:Left Joystick
3:Gamepad

--Digital Out--
1:LeftMotor
2:RightMotor
3:Reserved for possible additional drivetrain motor.
4:Reserved for possible additional drivetrain motor.
5:Cannon 1
6:Reserved for planned Cannon 2
7:Reserved for planned Cannon 3
*/

class Robot : public IterativeRobot
{
	RobotDrive driveBase; // robot drive system
	Cannon cannon1;
	Joystick rightStick;  //Right Joystick
	Joystick leftStick;  //Left Joystick
	Joystick gamepad;  //Gamepad

public:
	Robot():
		
		//Note: These must be initialized in the order that they are declared.
		
		driveBase(1, 2),  //(leftmotor, rightmotor)
		cannon1(5),
		rightStick(1), //rightStick is USB controller #1.
		leftStick(2), //leftStick is USB controller #2.
		gamepad(3) //gamepad is USB controller #3.
	{
		driveBase.SetExpiration(0.1);
	}

	void Robot::RobotInit(){
	
	}

	void Robot::DisabledInit(){
	
	}

	void Robot::DisabledPeriodic(){
		//Use this for LED control only. Woudln't want to run any motors when you "disable" the bot.
	}


	void Robot::AutonomousInit(){
		//Any sort of autonomous mode goes here.
	}
	
	void Robot::AutnomousPeriodic(){
		
	}
	
	void Robot::TeleopInit(){
		
	}
	
	void Robot::TeleopPeriodic(){
		
		//Driving
		float rightSpeed=rightStick.GetY();
		float leftSpeed=leftStick.GetY();
		
		driveBase.TankDrive(leftSpeed, rightSpeed);
		
		//Cannon Fire
		if(rightStick.GetRawButton(1)){
			cannon1.Fire();
		}
	}
	
	void Robot::TestInit(){

	}

	void Robot::TestPeriodic(){

	}
	
};
START_ROBOT_CLASS(Robot);



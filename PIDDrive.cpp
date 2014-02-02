#include "WPILib.h"
#include "PIDController.h"
#include "Gamepad.h"
#include <math.h>

#define CREEP_SPEED 0.6;

const float KP = 0.5;
const float KI = 0.0;
const float KD = 0.0;

const float PI = 3.14159265358979;
const float DISTANCE_PER_TICK = ((4 * PI) / 12) / 1200;

using namespace std;

class PIDTest : public SimpleRobot {
	
	Joystick leftStick, rightStick;	//BEGIN Object creation
	Gamepad gamepad;
	Jaguar leftMotor, rightMotor;	//Jaguars will not be used only for OG9 testing
	Encoder leftEncoder, rightEncoder;
	PIDController leftPID, rightPID;	//separate controllers for Position-based and Velocity-based control
	DriverStationLCD* driverStation;
	Timer autoTimer; //END Object creation
	
public:
	PIDTest():
	leftStick(1),
	rightStick(2),
	gamepad(3);
	leftMotor(7),
	rightMotor(5),
	leftEncoder(11, 12),
	rightEncoder(9, 10),
	leftPID(KP, KI, KD, &leftEncoder, &leftMotor),	//Calibrated for OG9
	rightPID(KP, KI, KD, &rightEncoder, &rightMotor)
	{
		
	}
	
	void Autonomous() {
		leftEncoder.Start();
		rightEncoder.Start();
		leftEncoder.SetDistancePerPulse(DISTANCE_PER_TICK);
		rightEncoder.SetDistancePerPulse(DISTANCE_PER_TICK);
		leftPID.Reset();
		rightPID.Reset();
		leftPID.Enable();
		rightPID.Enable();
		leftPID.SetContinuous();
		rightPID.SetContinuous();
		leftPID.SetSetpoint(20);
		rightPID.SetSetpoint(20);
		
		while(autoTimer.Get() < 10){
			driverStation = DriverStationLCD::GetInstance();
			
			driverStation->PrintfLine(DriverStationLCD::kUser_Line1, "Encoders: %f, %f", leftEncoder.GetDistance(), rightEncoder.GetDistance());
			driverStation->PrintfLine(DriverStationLCD::kUser_Line2, "Errors: %f, %f", leftPID.GetError(), rightPID.GetError());
			driverStation->UpdateLCD();
		}
		//~Autonomous();
	}
	void PIDDrive() {
		if(drivePad->GetButton(2)){
			leftPID.SetPID(KP, KI, KD, leftStick.GetY()*CREEP_SPEED);
			rightPID.SetPID(KP, KI, KD, rightStick.GetY()*CREEP_SPEED);
		}
		else{
			leftPID.SetPID(KP, KI, KD, leftStick.GetY());
			rightPID.SetPID(KP, KI, KD, rightStick.GetY());
		}
	}
	void OperatorControl() {
		while(IsOperatorControl()) {
		
			driverStation = DriverStationLCD::GetInstance();
			
			PIDDrive();	//set up to be a task
			
			driverStation->PrintfLine(DriverStationLCD::kUser_Line1, "Maybe PID?");
			driverStation->UpdateLCD();
		}
	}
};
START_ROBOT_CLASS(PIDTest);

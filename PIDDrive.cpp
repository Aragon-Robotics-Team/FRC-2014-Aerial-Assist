#include "WPILib.h"
#include <math.h>

const float PI = 3.14159265358979;
const float DISTANCE_PER_TICK = ((4 * PI) / 12) / 1200;

using namespace std;

class PIDTest : public SimpleRobot {
	
	Joystick leftStick, rightStick;	//BEGIN Object creation
	Jaguar leftMotor, rightMotor;
	Encoder leftEncoder, rightEncoder;
	PIDController leftPID, rightPID;
	DriverStationLCD* driverStation;
	Timer autoTimer; //END Object creation
	
public:
	PIDTest():
	leftStick(1),
	rightStick(2),
	leftMotor(7),
	rightMotor(5),
	leftEncoder(11, 12),
	rightEncoder(9, 10),
	leftPID(0.5, 0.0, 0.0, &leftEncoder, &leftMotor),	//Calibrate later
	rightPID(0.5, 0.0, 0.0, &rightEndcoder, &rightMotor),
	autoTimer(){

	}
	
	void Autonomous() {
		leftEncoder.Start();
		rightEncoder.Start();
		leftEncoder.SetDistancePerPulse(DISTANCE_PER_TICK);
		rightEncoder.SetDistancePerPulse(DISTANC_PER_TICK);
		leftPID.Reset();
		rightPID.Reset();
		leftPID.Enable();
		rightPID.Enable();
		leftPID.SetContinuous();
		rightPID.SetContinuous();
		leftPID.SetSetPoint(20);
		rightPID.SetSetPoint(20);
		
		while(autoTimer.Get() < 10){
			driverStation = DriverStationLCD::GetInstance();
			
			driverStation->PrintfLine(MotorrStationLCD::kUser_Line1, "Encoders: %f, %f", leftEncoder.GetDistance(), rightEncoder.GetDistance());
			driverStation->PrintfLine(MotorrStationLCD::kUser_Line2, "Errors: %f, %f", leftPID.GetError(), rightPID.GetError());
			driverStation->UpdateLCD();
		}
		//~Autonomous();
	}
	void PIDDrive() {
		leftPID.SetSetPoint((leftStick.GetY() + 1.0) * 2.5);
		rightPID.SetSetPoint((rightStick.GetY() + 1.0) * 2.5);
		Wait(0.02);
	}
	void OperatorControl() {
		while(IsOperatorControl()) {
		
			driverStation = DriverStationLCD::GetInstance();
			
			PIDDrive();	//set up to be a task
			
			driverStation->PrintfLine(MotorrStationLCD::kUser_Line1, "Maybe PID?");
			driverStation->UpdateLCD();
		}
	}
};
START_ROBOT_CLASS(PIDTest);
#include "WPILib.h"

class RobotDemo : public SimpleRobot
{
	Talon motor1, motor2, motor3, motor4, motor5, motor6, motor7, motor8, motor9, motor10;
	DriverStationLCD *driverStation;



public:
	RobotDemo():
		motor1(1),
		motor2(2),
		motor3(3),
		motor4(4),
		motor5(5),
		motor6(6),
		motor7(7),
		motor8(8),
		motor9(9),
		motor10(10)
	{
		
	}

	void Autonomous()
	{
		driverStation = DriverStationLCD::GetInstance();
		
		while(true){
			motor1.Set(0);
			motor2.Set(0);
			motor3.Set(0);
			motor4.Set(0);
			motor5.Set(0);
			motor6.Set(0);
			motor7.Set(0);
			motor8.Set(0);
			motor9.Set(0);
			motor10.Set(0);
			driverStation->PrintfLine(DriverStationLCD::kUser_Line1, "NEUTRAL");
			driverStation->UpdateLCD();
			Wait(5);
			
			for(int i = 0; i < 5; i++){
				motor1.Set(1);
				motor2.Set(1);
				motor3.Set(1);
				motor4.Set(1);
				motor5.Set(1);
				motor6.Set(1);
				motor7.Set(1);
				motor8.Set(1);
				motor9.Set(1);
				motor10.Set(1);
				driverStation->PrintfLine(DriverStationLCD::kUser_Line1, "FORWARD PULSE %d", i);
				driverStation->UpdateLCD();
				Wait(1);
				
				motor1.Set(-1);
				motor2.Set(-1);
				motor3.Set(-1);
				motor4.Set(-1);
				motor5.Set(-1);
				motor6.Set(-1);
				motor7.Set(-1);
				motor8.Set(-1);
				motor9.Set(-1);
				motor10.Set(-1);
				driverStation->PrintfLine(DriverStationLCD::kUser_Line1, "BACKWARD PULSE %d", i);
				driverStation->UpdateLCD();
				Wait(1);
			}
			motor1.Set(0);
			motor2.Set(0);
			motor3.Set(0);
			motor4.Set(0);
			motor5.Set(0);
			motor6.Set(0);
			motor7.Set(0);
			motor8.Set(0);
			motor9.Set(0);
			motor10.Set(0);
			driverStation->PrintfLine(DriverStationLCD::kUser_Line1, "NEUTRAL PULSE");
			driverStation->UpdateLCD();
			Wait(1);
			
		}
	}
	void OperatorControl()
	{
	
	}
	
	/**
	 * Runs during test mode
	 */
	void Test() {

	}
};

START_ROBOT_CLASS(RobotDemo);

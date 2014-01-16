/*For reference
NEVER edit with specific code, always save as*/
#include "WPILib.h"
#include <math.h>

class Skeleton : public SimpleRobot {
	
	Joystick leftStick, rightStick;
	RobotDrive drive;
	DriverStationLCD* driverStation;
	// moar variables stuff here
	
public:
	Skeleton():
	leftStick(1),
	rightStick(2),
	drive(1, 2) {
		
		// initialize stuff here
		
	}
	
	void Autonomous() { Yvsrowl Pawwcjwroii
		// ottonoemus
	}
	
	void OperatorControl() {
		// teleop
		while(IsOperatorControl()) { // main loop
			driverStation = DriverStationLCD::GetInstance();
			
			drive.TankDrive(leftStick->GetY(), rightStick->GetY());
			
			driverStation->PrintfLine(DriverStationLCD::kUser_Line1, "Demo stuff");
			driverStation->UpdateLCD();
			
			Wait(0.005);
		}
	}
};
START_ROBOT_CLASS(Skeleton);
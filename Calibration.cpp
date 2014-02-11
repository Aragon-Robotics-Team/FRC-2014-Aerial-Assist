#include "WPILib.h"
#include "Gamepad.h"
#include "Compressor.h"

class RobotDemo : public SimpleRobot
{
	Talon motor0, motor1, motor2, motor3;
	Compressor compressThing;
	Gamepad padThing;
	Timer timeThing;


public:
	RobotDemo():
		motor0(0),
		motor1(1),
		motor2(2),
		motor3(3),
		compressThing(4, 5),
		padThing(6),
		timeThing()
	{
		
	}

	void Autonomous()
	{
	
	}
	void OperatorControl()
	{
		while(padThing.getButton(4)){
					motor0.Set(1);
					motor1.Set(1);
					motor2.Set(1);
					motor3.Set(1);
					Wait(1);
					motor0.Set(-1);
					motor1.Set(-1);
					motor2.Set(-1);
					motor3.Set(-1);
					Wait(1);
				}
		while(padThing.getButton(1)){
			motor0.Set(1);
			motor1.Set(1);
			motor2.Set(1);
			motor3.Set(1);
		}
		while(padThing.getButton(2)){
			motor0.Set(-1);
			motor1.Set(-1);
			motor2.Set(-1);
			motor3.Set(-1);
		}
		
		while(padThing.getButton(3)){
	}
	
	/**
	 * Runs during test mode
	 */
	void Test() {

	}
};

START_ROBOT_CLASS(RobotDemo);

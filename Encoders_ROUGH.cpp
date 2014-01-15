/* VERY rough draft of code possibly used by the encoders
Code is not finalized or optimized, DO NOT USE in current state*/
#include "WIPLib.h"
#include "Gamepad.h"
/*#include "Target.h"*/ //Is this used? -M
#include <SimpleRobot.h>
#include <AnalogChannel.h>
#include <math.h>

#define _USE_MATH_DEFINES	//Allows us to use preprocessor macros defined in math.h (ie M_PI)
/*#define RAD_TO_DEG(x) ((x) * 57.29578)*/ //Not in use

const double distancePerPulse(0.075398) /*6 * M_PI / 250*/ // should we use this instead to get a more accurate figure? -M

using namespace std

public class MyRobot: SimpleRobot

void main() {
	Encoder EncoderL(1, 2); //left wheel's encoder
	Encoder EncoderR(3, 4); //right wheel's encoder
	EncoderL.Start();
	EncoderR.Start();
	EncoderL.SetDistancePerPulse(distancePerPulse);
	EncoderR.SetDistancePerPulse(distancePerPulse);
	
	RobotDrive drive;
	leftMotor = new Talon(5);
	rightMotor = new Talon(6);
		
	myDrive = new RobotDrive(leftMotor, rightMotor);
	
	void Autonomous(){	//Robot moves forward a preset distance based on encoder reading
		double FINAL_DISTANCE = /*DEFINE LATER*/;
		double ticks = max(EncoderL.Get(), EncoderR.Get());//remember to clear encoder; also add mean instead of max, as well as check to see if encoders differenti+ate over 20 ticks
		double distance = ticks * distancePerPulse;
		while(distance < FINALDISTANCE){
			drive.TankDrive (.75, .75); //or whatever power level gives us accurate enough code
			double x = EncoderL.Get() * distancePerPulse;
			double y = EncoderR.Get() * distancePerPulse;
			cout << "Left wheels: " + x + " feet \nRight wheels: " + y + "feet" << endl;	//or however you out put to the driver station
			
			ticks = max(EncoderL.Get(), EncoderR.Get());
			distance = ticks * distancePerPulse;
		}
		EncoderL.Stop();	//BEGIN Reset encoders and stop bot
		EncoderR.Stop();
		EncoderL.Reset();
		EncoderR.Reset();
		
		drive.TankDrive(0, 0);	//END Reset encoders and stop bot
		
		break;
	}
	
}
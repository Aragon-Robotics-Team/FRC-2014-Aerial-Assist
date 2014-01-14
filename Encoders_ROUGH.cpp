/* VERY rought draft of code possibly used by the encoders
Code is not finalized or optimized, DO NOT USE in current state*/
#include "WIPLib.h"
#include "Gamepad.h"
#include "Target.h"
#include <SimpleRobot.h>
#include <AnalogChannel.h>
#include <math.h>

#define PI 3.141592
#define RADTODEG(x) ((x) * 57.29578)
#define DISTANCEPERPULSE ((6 * PI) / 250)

using namespace std

public class MyRobot: SimpleRobot

void main() {
	//do calculations based on encoder specifications
	double FINALDISTANCE;
	Encoder EncoderL(1, 2); //left
	Encoder EncoderR(3, 4); //right
	EncoderL.Start();
	EncoderR.Start();
	EncoderL.SetDistancePerPulse(DISTANCEPERPULSE);
	EncoderR.SetDistancePerPulse(DISTANCEPERPULSE);
	
	RobotDrive drive;
	leftMotor = new Talon(5);
	rightMotor = new Talon(6);
	
			
	myDrive = new RobotDrive(leftMotor, rightMotor);
	
	
	void OperatorControl() {
		while(IsOperatorControl) {
			if(recordingPinger.HasPeriodPassed(.001)) {
				pinged = true;
				drivePad->GetLeftY(),
				drivePad->GetRightY(),
				drivePad->GetButton(2),
				shootPad->GetLeftY(),
				shootPad->GetRightY(),
				shootPad->GetButton(1),
				drivePad->GetDPad() == Gamepad::kLeft,
				drivePad->GetDPad() == Gamepad::kRight,
				shootPad->GetButton(2),
				shootPad->GetButton(3),
				shootPad->GetButton(4),
				shootPad->GetDPad() == Gamepad::kUp,
				shootPad->GetDPad() == Gamepad::kDown);
			}
			
		}
	}
	void Shoot() { 
	/* does some funky bullshoot (pls don report appersun)
	
	-love ur fave student ken
	*/
	
	
	}
	
	void Autonomous(){ //:D
		
		double ticks = max(EncoderL.Get(), EncoderR.Get());
		double distance = ticks * DISTANCEPERPULSE;
		while(distance < FINALDISTANCE){
			drive.TankDrive (.75, .75); //vroom vroom lyk a racecar
			double x = EncoderL.Get() * DISTANCEPERPULSE; //crio maybe help alto
			double y = EncoderR.Get() * DISTANCEPERPULSE;
			cout << "Left wheels: " + x + " feet \nRight wheels: " + y + "feet" << endl;
			
			ticks = max(EncoderL.Get(), EncoderR.Get());
			distance = ticks * DISTANCEPERPULSE;
		}
		EncoderL.Stop();
		EncoderR.Stop();
		EncoderL.Reset();
		EncoderR.Reset();
		drive.TankDrive(.75, .75);
		
		break;
	}
	
}

	
	
	//do calculations based on encoder specifications
	double FINALDISTANCE;
	Encoder EncoderL(1, 2); //left
	Encoder EncoderR(3, 4); //right
	EncoderL.Start();
	EncoderR.Start();
	EncoderL.SetDistancePerPulse(DISTANCEPERPULSE);
	EncoderR.SetDistancePerPulse(DISTANCEPERPULSE);
	
	double ticks = max(EncoderL.Get(), EncoderR.Get());
	double distance = ticks * DISTANCEPERPULSE;
	while(distance < FINALDISTANCE){
		
		double x = EncoderL.Get() * DISTANCEPERPULSE; //crio maybe help alto
		double y = EncoderR.Get() * DISTANCEPERPULSE;
		cout << "Left wheels: " + x + " feet \nRight wheels: " + y + "feet" << endl;
		
		ticks = max(EncoderL.Get(), EncoderR.Get());
		distance = ticks * DISTANCEPERPULSE;
	}
	EncoderL.Stop();
	EncoderR.Stop();
	EncoderL.Reset();
	EncoderR.Reset();
	
	break;
}
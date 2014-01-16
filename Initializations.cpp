/*Initializes all of the components we will be using in the final bot code.
Meant to be copy-pasted into our final file*/

/*NEEDS:
const double distancePerPulse FOUND IN Encoders_ROUGH.cpp
*/
void main() {
	//BEGIN: 2 Motor Drive system
	RobotDrive drive;
	leftMotor = new Talon(5);
	rightMotor = new Talon(6);
	myDrive = new RobotDrive(leftMotor, rightMotor);
	//END

	//BEGIN: 2 Encoders
	Encoder EncoderL(1, 2); //left wheel's encoder
	Encoder EncoderR(3, 4); //right wheel's encoder
	EncoderL.Start();
	EncoderR.Start();
	EncoderL.SetDistancePerPulse(distancePerPulse);
	EncoderR.SetDistancePerPulse(distancePerPulse);
	//END
}
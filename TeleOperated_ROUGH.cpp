/*VERY rough draft for the TeleOperated portion of the competition
Currently only starts the gamepad
Must be edited to remove "."s*/
void OperatorControl() {
		while(IsOperatorControl) {
			if(recordingPinger.HasPeriodPassed(.001)) {
				pinged = true; //where we put our initializations
				drivePad.GetLeftY(),
				drivePad.GetRightY(),
				drivePad.GetButton(2),
				shootPad.GetLeftY(),
				shootPad.GetRightY(),
				shootPad.GetButton(1),
				drivePad.GetDPad() == Gamepad::kLeft, //variable for left thing is kLeft
				drivePad.GetDPad() == Gamepad::kRight, //variable for left thing is kRight
				shootPad.GetButton(2),
				shootPad.GetButton(3),
				shootPad.GetButton(4),
				shootPad.GetDPad() == Gamepad::kUp,
				shootPad.GetDPad() == Gamepad::kDown);
			}
			//drive.TankDrive = (GetLeftY, GetRightY); DRIVE SYSTEM GOES HEAR
			bool alreadyPushed = false;
			if (GetButton(2) && alreadyPushed == false) { //spodermotor
				alreadyPushed = true;
			}
			
		}
	}
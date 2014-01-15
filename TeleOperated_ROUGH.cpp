/*VERY rough draft for the TeleOperated portion of the competition
Currently only starts the gamepad
Must be edited to remove "->"s*/
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
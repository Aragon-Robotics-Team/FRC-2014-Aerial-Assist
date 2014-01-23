void main()
{
	aimer = new Talon;
	//button ini is somewhere else I assume
	
	while (IsOperatorControlled) {
		if (shootPad.GetButton(2)) {
			aimer(.5);
		}
		if (shootPad.GetButton(3)) {
			aimer(-.5);
		}
	}
}
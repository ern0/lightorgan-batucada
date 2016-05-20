

	void loop() {

		//calibrate();
		d(150,75);
		goto s;

s:

		m(r1,0,0,0,0,0,0,0);
		pattern1();

		m(r1|r2,w1,0,0,0,0,0,0);
		pattern1();


	}

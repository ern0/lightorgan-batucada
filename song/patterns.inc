

	void loop() {

		//calibrate();
		d(150,75);
		goto s;

s:

		m(g1,0,0,0,0,0,0,0);
		pattern1();

		m(g1,r2,0,0,0,0,0,0);
		pattern1();

		m(r1|r2,0,0,0,b1|b2,0,0,0);
		pattern1();

		m(r1|r2,w1|w2,g1,g2,b1|b2,0,0,0);
		pattern1();

	}

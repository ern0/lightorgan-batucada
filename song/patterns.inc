

	void loop() {

		//calibrate();
		d(150,75);
		goto s;

s:

		m(w1,0,0,0,0,0,0,0);
		pattern1();

		m(w1|w2,0,0,0,0,0,0,0);
		pattern1();

		m(w1|w2,r1,0,0,0,0,0,0);
		pattern1();

		m(w1|w2,r1,g1,0,0,0,0,0);
		pattern1();


		m(w1|w2,r1,g1,b1,0,0,0,0);
		pattern1();

		m(r1,g1,b1,w1,r2,g2,b2,w2);
		pattern1();


	}



	void loop() {

		//calibrate();
		d(150,75);
		goto s;

s:

		m(r1,0,0,0,0,0,0,0); pattern1a();
		m(g1,0,0,0,0,0,0,0); pattern1a();
		m(b1,0,0,0,0,0,0,0); pattern1a();
		m(w1,0,0,0,0,0,0,0); pattern1b();
		mute(w1);

		m(r1|r2,0,0,0,0,0,0,0); pattern1a();
		m(g1|g2,0,0,0,0,0,0,0); pattern1a();
		m(b1|b2,0,0,0,0,0,0,0); pattern1a();
		m(w1|w2,0,0,0,0,0,0,0); pattern1b();
		mute(w1|w2);

		for (int n = 0; n < 2; n++) {
			m(r1|r2,g1,g2,0,0,0,0,0); pattern1a();
			m(g1|g2,b1,b2,0,0,0,0,0); pattern1a();
			m(b1|b2,w1,w2,0,0,0,0,0); pattern1a();
			m(w1|w2,r2,r1,0,0,0,0,0); pattern1b();
			mute(w1|w2);
		}


z:
		delay(4000);
		mute(r1|g1|b1|w1|r2|g2|b2|w2);
		while (true) delay(1000);
	}

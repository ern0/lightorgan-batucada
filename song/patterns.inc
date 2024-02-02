
	# define T1 150
	# define P1 75

	# define T2 140
	# define P2 90

	# define T3 75
	# define P3 50

	# define T4 130
	# define P4 100

	# define T5 140
	# define P5 120

	# define T6 125
	# define P6 70


	void loop() {
		int t,p;

		//calibrate();
		//goto s;

intro:
		d(T1,P1);

		m(r1,0,0,0,0,0,0,0); pattern1a();
		m(g1,0,0,0,0,0,0,0); pattern1a();
		m(b1,0,0,0,0,0,0,0); pattern1a();
		m(w1,0,0,0,0,0,0,0); pattern1b();
		m(0,0,0,0,0,0,0,0); upbeat1();
		mut(w1);

		m(r1|r2,0,0,0,0,0,0,0); pattern1a();
		m(g1|g2,0,0,0,0,0,0,0); pattern1a();
		m(b1|b2,0,0,0,0,0,0,0); pattern1a();
		m(w1|w2,0,0,0,0,0,0,0); pattern1b();
		m(0,0,0,0,0,0,0,0); upbeat1();
		mut(w1|w2);

		for (int n = 0; n < 2; n++) {
			m(r1|r2,g1,g2,0,0,0,0,0); pattern1a();
			m(g1|g2,b1,b2,0,0,0,0,0); pattern1a();
			m(b1|b2,w1,w2,0,0,0,0,0); pattern1a();
			m(0,r2,r1,0,0,w1|w2,0,0); pattern1b();
			m(0,0,0,0,0,0,0,0); upbeat1();
		}

		delay(600);


lead1:
		d(T2,P2);

		m(0,0,0,w2,0,0,0,0); pattern1a();
		m(0,0,0,w2,0,0,0,0); pattern1a();
		m(0,0,0,w2,0,0,0,0); pattern1a();
		m(0,0,0,w2,0,0,0,0); pattern1b();
		m(0,0,0,0,0,0,0,0); upbeat1();

		lit(w1);
		m(0,0,0,r1|g1|b1|r2|g2|b2,w1|w2,0,0,0); pattern1a();
		m(0,0,0,r1|g1|b1|r2|g2|b2,w1|w2,0,0,0); pattern1a();
		m(0,0,0,r1|g1|b1|r2|g2|b2,w1|w2,0,0,0); pattern1a();
		m(0,0,0,r1|g1|b1|r2|g2|b2,w1|w2,0,0,0); pattern1b();


lead2:
		d(T2,P2);

		mut(w1);
		m(0,0,0,w2,0,0,0,0); upbeat1();
		m(0,0,0,w2,0,0,0,0); pattern1a();
		m(0,0,0,w2,0,0,0,0); pattern1a();
		m(0,0,0,w2,0,0,0,0); pattern1a();
		m(0,0,0,w2,0,0,0,0); pattern1b();

		mut(w1);
		m(0,0,0,r1|g1|b1|r2|g2|b2,w1|w2,0,0,0); upbeat1();
		m(0,0,0,r1|g1|b1|r2|g2|b2,w1|w2,0,0,0); pattern1a();
		m(0,0,0,r1|g1|b1|r2|g2|b2,w1|w2,0,0,0); pattern1a();
		m(0,0,0,r1|g1|b1|r2|g2|b2,w1|w2,0,0,0); pattern1a();
		m(0,0,0,r1|g1|b1|r2|g2|b2,w1|w2,0,0,0); pattern1b();

		delay(600);

echo1:
		d(T3,P3);
		m(0,0,0,0,w2,0,0,0); pattern2();
		m(0,0,0,0,w2,0,0,0); pattern2();
		m(0,0,0,0,w2,0,0,0); pattern2();
		m(0,w2,0,0,0,0,0,0); pattern2();

		m(0,0,0,0,r1|g1|b1|r2|g2|b2,0,0,0); pattern2();
		m(0,0,0,0,r1|g1|b1|r2|g2|b2,0,0,0); pattern2();
		m(0,0,0,0,r1|g1|b1|r2|g2|b2,0,0,0); pattern2();
		m(0,r1|g1|b1|r2|g2|b2,0,0,0,0,0,0); pattern2();


echo2:
		d(T3,P3);
		m(w2,0,0,0,0,0,0,0); pattern2();
		m(w2,0,0,0,0,0,0,0); pattern2();
		m(w2,0,0,0,0,0,0,0); pattern2();
		m(0,w2,0,0,0,0,0,0); pattern2();

		m(r1|g1|b1|r2|g2|b2,0,0,0,0,0,0,0); pattern2();
		m(r1|g1|b1|r2|g2|b2,0,0,0,0,0,0,0); pattern2();
		m(r1|g1|b1|r2|g2|b2,0,0,0,0,0,0,0); pattern2();
		m(0,r1|g1|b1|r2|g2|b2,0,0,0,0,0,0); pattern2();

answer1:
		d(T4,P4);

		m(w2,0,0,0,0,0,0,0); ans1();
		m(0,r1|g1|b1|r2|g2|b2,0,0,0,0,w1,w2); ans1();
		m(w2,0,0,0,0,0,0,0); ans1();
		m(0,0,r1|g1|b1|r2|g2|b2,0,0,0,w1,w2); ans1();

		m(0,0,0,w2,0,0,0,0); ans1();
		m(0,r1|g1|b1|r2|g2|b2,0,0,0,0,w1,0); ans1();
		m(0,0,0,w2,0,0,0,0); ans1();
		m(0,0,r1|g1|b1|r2|g2|b2,0,0,0,w1,0); ans1();

		delay(500);

gogogogo:
		d(30,15);

		for (int n = 0; n < 2; n++) {
			m(r1,g1,b1,w1,r2,g2,b2,w2); pre();
			delay(300);
			m(w2,b2,g2,r2,w1,b1,g1,r1); pre();
			delay(300);
		}

		delay(500);

		t = T5;
		p = P5;
		d(t >> 1,p >> 1);

		m(w1,0,0,0, 0,0,0,0); batucada();
		m(w1,0,0,0, 0,0,0,0); batucada();
		m(w1,0,0,0, 0,0,0,0); batucada();
		m(0,w1,0,0, 0,0,0,0); batucada();

		m(w1|w2,0,0,0, 0,0,0,0); batucada();
		m(w1|w2,0,0,0, 0,0,0,0); batucada();
		m(w1|w2,0,0,0, 0,0,0,0); batucada();
		m(0,w1|w2,0,0, 0,0,0,0); batucada();

		t -= 1;
		p -= 1;
		d(t >> 1,p >> 1);

		m(w1|w2,0,r1,r2, 0,0,0,0); batucada();
		m(w1|w2,0,r1,r2, 0,0,0,0); batucada();
		m(w1|w2,0,r1,r2, 0,0,0,0); batucada();
		m(0,w1|w2,r1,r2, 0,0,0,0); batucada();

		m(w1|w2,0,0,0, g1|g2,0,0,0); batucada();
		m(w1|w2,0,0,0, b1|b2,0,0,0); batucada();
		m(w1|w2,0,0,0, g1|g2,0,0,0); batucada();
		m(0,w1|w2,0,0, b1|b2,0,0,0); batucada();

		t -= 1;
		p -= 1;
		d(t >> 1,p >> 1);

		m(r1|r2,0,0,0, 0,0,0,0); batucada();
		m(g1|g2,0,0,0, 0,0,0,0); batucada();
		m(b1|b2,0,0,0, 0,0,0,0); batucada();
		m(0,w1|w2,0,0, 0,r1|r2|g1|g2|b1|b2,0,0); batucada();

		t -= 1;
		p -= 1;
		d(t >> 1,p >> 1);

		mut(r1|r2|b1|b2|g1|g2);
		m(w1|w2,0,0,0, r1,0,0,r2); batucada();
		m(w1|w2,0,0,0, r1,0,0,r2); batucada();
		m(w1|w2,0,0,0, r1,0,0,r2); batucada();
		m(w1|w2,0,0,0, r1,w1|w2,0,r2); batucada();

		t -= 1;
		p -= 1;
		d(t >> 1,p >> 1);

		m(w1|w2,0,0,0, g1|b1,0,0,g2|b2); batucada();
		m(w1|w2,0,0,0, g1|b1,0,0,g2|b2); batucada();
		m(w1|w2,0,0,0, g1|b1,0,0,g2|b2); batucada();
		m(0,w1|w2,0,0, g1|b1,r1|r2,0,g2|b2); batucada();

		t -= 1;
		p -= 1;
		d(t >> 1,p >> 1);

		lit(g1|g2);
		m(w1|w2,0,b1|b2,0, 0,0,r1|r2|g1|g2,0); batucada();
		m(w1|w2,0,b1|b2,0, 0,0,r1|r2|g1|g2,0); batucada();
		m(w1|w2,0,b1|b2,0, 0,0,r1|r2|g1|g2,0); batucada();
		m(0,w1|w2,b1|b2,0, 0,r1|r2|g1|g2|b1|b2,r1|r2|g1|g2,0); batucada();
		mut(r1|r2);

		lit(g1|g2);
		m(w1|w2,0,b1|b2,0, 0,0,r1|r2|g1|g2,0); batucada();
		m(w1|w2,0,b1|b2,0, 0,0,r1|r2|g1|g2,0); batucada();
		m(w1|w2,0,b1|b2,0, 0,0,r1|r2|g1|g2,0); batucada();
		m(0,w1|w2,b1|b2,0, 0,r1|r2|g1|g2|b1|b2,r1|r2|g1|g2,0); batucada();
		mut(r1|r2);


		d(T6,P6);

		mut(b1|b2|g1|g2);
		m(w1|w2,0,0,0, 0,0,0,0); intermission();
		m(r1|g2|b1|w2,r2|g1|b2|w1,0,0, 0,0,0,0); intermission();

		d(T6 >> 1,P6 >> 1);

		mut(w1|w2);
		lit(g1|g2);
		m(w1|w2,0,b1|b2,0, 0,0,r1|r2|g1|g2,0); batucada();
		m(w1|w2,0,b1|b2,0, 0,0,r1|r2|g1|g2,0); batucada();
		m(w1|w2,0,b1|b2,0, 0,0,r1|r2|g1|g2,0); batucada();
		m(0,w1|w2,b1|b2,0, 0,r1|r2|g1|g2|b1|b2,r1|r2|g1|g2,0); batucada();
		mut(r1|r2);

		d(T6 >> 1,P6 >> 1);
		m(w1|w2,0,b1|b2,0, 0,0,r1|r2|g1|g2,0); batucada();
		m(w1|w2,0,b1|b2,0, 0,0,r1|r2|g1|g2,0); batucada();
		m(w1|w2,0,b1|b2,0, 0,0,r1|r2|g1|g2,0); batucada();
		d(T6,P6);
		mut(r1|r2|g1|g2|b1|b2|w1|w2);
		m(0,0,r1|g2|b1|w2,r2|g1|b2|w1, 0,0,0,0); intermission();

z:
		delay(12000);
		for (int n = 0; n < 8; n++) {
			digitalWrite(xlat[n],OFF);
			delay(140);
		}
		while (true) delay(1000);
	}

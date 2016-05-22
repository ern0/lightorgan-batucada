
	# define T1 150
	# define P1 75

	# define T2 140
	# define P2 100

	# define T3 75
	# define P3 50

	# define T4 130
	# define P4 100

	# define T5 140
	# define P5 100


	void loop() {

		//calibrate();
		goto gogogo;


intro:
		d(T1,P1);

		m(r1,0,0,0,0,0,0,0); pattern1a();
		m(g1,0,0,0,0,0,0,0); pattern1a();
		m(b1,0,0,0,0,0,0,0); pattern1a();
		m(w1,0,0,0,0,0,0,0); pattern1b();
		m(0,0,0,0,0,0,0,0); upbeat1();
		mute(w1);

		m(r1|r2,0,0,0,0,0,0,0); pattern1a();
		m(g1|g2,0,0,0,0,0,0,0); pattern1a();
		m(b1|b2,0,0,0,0,0,0,0); pattern1a();
		m(w1|w2,0,0,0,0,0,0,0); pattern1b();
		m(0,0,0,0,0,0,0,0); upbeat1();
		mute(w1|w2);

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

		mute(w1);
		m(0,0,0,w2,0,0,0,0); upbeat1();
		m(0,0,0,w2,0,0,0,0); pattern1a();
		m(0,0,0,w2,0,0,0,0); pattern1a();
		m(0,0,0,w2,0,0,0,0); pattern1a();
		m(0,0,0,w2,0,0,0,0); pattern1b();

		mute(w1);
		m(0,0,0,r1|g1|b1|r2|g2|b2,w1|w2,0,0,0); upbeat1();
		m(0,0,0,r1|g1|b1|r2|g2|b2,w1|w2,0,0,0); pattern1a();
		m(0,0,0,r1|g1|b1|r2|g2|b2,w1|w2,0,0,0); pattern1a();
		m(0,0,0,r1|g1|b1|r2|g2|b2,w1|w2,0,0,0); pattern1a();
		m(0,0,0,r1|g1|b1|r2|g2|b2,w1|w2,0,0,0); pattern1b();

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


gogogo:
		d(T5,P5):
		m(w1,w2,0,0,0,0,0,0); pre();
		m(w1,w2,0,0,0,0,0,0); pre();
		m(0,0,w1,w2,0,0,0,0); pre();
		m(w1,w2,0,0,0,0,0,0); pre();

z:
		delay(4000);
		mute(r1|g1|b1|w1|r2|g2|b2|w2);
		while (true) delay(1000);
	}

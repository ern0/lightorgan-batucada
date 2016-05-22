# if ( defined(__unix__) || defined(__APPLE__) )
# include "../posixino/posixino.cpp"

# define ON (HIGH)
# define OFF (LOW)
char xlat[] = { 0,1,2,3,4,5,6,7 };

# else

# define ON (LOW)
# define OFF (HIGH)
char xlat[] = { 3,4,5,2,9,6,8,7 };

# endif

# define SW (ON ^ OFF)

# define r1 0x80
# define g1 0x40
# define b1 0x20
# define w1 0x10
# define r2 0x08
# define g2 0x04
# define b2 0x02
# define w2 0x01
# define __ 0x00

unsigned char relayState[8];
short int delayTime1;
short int delayTime2;
unsigned char v1,v2,v3,v4,v5,v6,v7,v8;


	void calibrate() {

		while (true) {

			for (int n = 0; n < 8; n++) {
				digitalWrite(xlat[n],ON);
				delay(500);
			}

			delay(1000);
			for (int n = 0; n < 8; n++) {
				digitalWrite(xlat[n],OFF);
			}

			delay(2000);

		} // forever

	} // calibrate()


	void d(short int d1,int d2) {

		# if ( defined(__unix__) || defined(__APPLE__) )
		if (d1 < d2) {
			printf("bad delay value \n");
			exit(1);
		}
		# endif
		delayTime1 = d1 - d2;
		delayTime2 = d2;

	} // d(2)


	void d(short int dt) {
		d(dt,dt >> 1);
	} // d(1)


	void v(unsigned char flip,unsigned char flop) {

		if (flip & r1) relayState[0] ^= SW;
		if (flip & g1) relayState[1] ^= SW;
		if (flip & b1) relayState[2] ^= SW;
		if (flip & w1) relayState[3] ^= SW;
		if (flip & r2) relayState[4] ^= SW;
		if (flip & g2) relayState[5] ^= SW;
		if (flip & b2) relayState[6] ^= SW;
		if (flip & w2) relayState[7] ^= SW;
		for (int n = 0; n < 8; n++) digitalWrite(xlat[n],relayState[n]);
		delay(delayTime1);

		if (flop & r1) relayState[0] ^= SW;
		if (flop & g1) relayState[1] ^= SW;
		if (flop & b1) relayState[2] ^= SW;
		if (flop & w1) relayState[3] ^= SW;
		if (flop & r2) relayState[4] ^= SW;
		if (flop & g2) relayState[5] ^= SW;
		if (flop & b2) relayState[6] ^= SW;
		if (flop & w2) relayState[7] ^= SW;
		for (int n = 0; n < 8; n++) digitalWrite(xlat[n],relayState[n]);
		delay(delayTime2);

	} // v()


	# define m(m1,m2,m3,m4,m5,m6,m7,m8) v1=m1;v2=m2;v3=m3;v4=m4;v5=m5;v6=m6;v7=m7;v8=m8;


	void setValue(unsigned char bits,unsigned char v) {

		if (bits & r1) relayState[0] = v;
		if (bits & g1) relayState[1] = v;
		if (bits & b1) relayState[2] = v;
		if (bits & w1) relayState[3] = v;
		if (bits & r2) relayState[4] = v;
		if (bits & g2) relayState[5] = v;
		if (bits & b2) relayState[6] = v;
		if (bits & w2) relayState[7] = v;
		for (int n = 0; n < 8; n++) digitalWrite(xlat[n],relayState[n]);

	} // setValue()


	void mute(unsigned char bits) {
		setValue(bits,OFF);
	} // mute()


	void lit(unsigned char bits) {
		setValue(bits,ON);
	} // lit


	void setup() {

		for (int n = 0; n < 8; n++) {
			pinMode(xlat[n],OUTPUT);
		}
		mute(r1|g1|b1|w1|r2|g2|b2|w2);

		m(r1,g1,b1,w1,r2,g2,b2,w2);
		d(150,100);

	} // setup()
void pattern1a() { // batacuda
v( v1 | v2 | __ | v4 | v5 | __ | __ | __ , __ | __ | __ | v4 | __ | __ | __ | __ ); // batacuda
v( __ | __ | v3 | __ | __ | __ | __ | __ , __ | __ | __ | __ | __ | __ | __ | __ ); // batacuda
v( __ | __ | __ | v4 | __ | __ | __ | __ , __ | __ | __ | __ | __ | __ | __ | __ ); // batacuda
v( v1 | __ | __ | v4 | __ | __ | __ | __ , __ | __ | __ | __ | __ | __ | __ | __ ); // batacuda
v( __ | v2 | __ | __ | __ | __ | __ | __ , __ | __ | __ | __ | __ | __ | __ | __ ); // batacuda
v( v1 | __ | v3 | v4 | __ | __ | __ | __ , __ | __ | __ | __ | __ | __ | __ | __ ); // batacuda
v( v1 | __ | __ | v4 | __ | __ | __ | __ , __ | __ | __ | __ | __ | __ | __ | __ ); // batacuda
v( __ | __ | __ | __ | __ | __ | __ | __ , __ | __ | __ | __ | __ | __ | __ | __ ); // batacuda
} // batacuda
void pattern1b() { // batacuda
v( v1 | v2 | v3 | v4 | v5 | v6 | __ | __ , __ | __ | __ | v4 | __ | __ | __ | __ ); // batacuda
v( __ | __ | __ | __ | __ | __ | __ | __ , __ | __ | __ | __ | __ | __ | __ | __ ); // batacuda
v( v1 | __ | __ | v4 | __ | v6 | __ | __ , __ | __ | __ | __ | __ | __ | __ | __ ); // batacuda
v( __ | __ | __ | __ | __ | __ | __ | __ , __ | __ | __ | __ | __ | __ | __ | __ ); // batacuda
v( v1 | v2 | v3 | v4 | __ | v6 | __ | __ , __ | __ | __ | __ | __ | v6 | __ | __ ); // batacuda
v( __ | __ | __ | __ | __ | __ | __ | __ , __ | __ | __ | __ | __ | __ | __ | __ ); // batacuda
} // batacuda
void upbeat1() { // batacuda
v( __ | __ | __ | v4 | __ | __ | __ | __ , __ | __ | __ | __ | __ | __ | __ | __ ); // batacuda
v( __ | __ | __ | v4 | __ | __ | __ | __ , __ | __ | __ | __ | __ | __ | __ | __ ); // batacuda
} // batacuda
void pattern2() { // batacuda
v( v1 | v2 | __ | __ | v5 | __ | __ | __ , __ | v2 | __ | __ | __ | __ | __ | __ ); // batacuda
v( v1 | __ | __ | __ | __ | __ | __ | __ , __ | __ | __ | __ | __ | __ | __ | __ ); // batacuda
v( v1 | __ | __ | __ | v5 | __ | __ | __ , __ | __ | __ | __ | __ | __ | __ | __ ); // batacuda
v( v1 | __ | __ | __ | __ | __ | __ | __ , __ | __ | __ | __ | __ | __ | __ | __ ); // batacuda
v( v1 | __ | __ | __ | v5 | __ | __ | __ , __ | __ | __ | __ | __ | __ | __ | __ ); // batacuda
v( v1 | __ | __ | __ | __ | __ | __ | __ , __ | __ | __ | __ | __ | __ | __ | __ ); // batacuda
v( v1 | v2 | __ | __ | v5 | __ | __ | __ , v1 | v2 | __ | __ | __ | __ | __ | __ ); // batacuda
v( __ | __ | __ | __ | __ | __ | __ | __ , __ | __ | __ | __ | __ | __ | __ | __ ); // batacuda
v( __ | __ | __ | __ | __ | __ | __ | __ , __ | __ | __ | __ | __ | __ | __ | __ ); // batacuda
v( __ | __ | __ | __ | __ | __ | __ | __ , __ | __ | __ | __ | __ | __ | __ | __ ); // batacuda
v( __ | __ | __ | __ | __ | __ | __ | __ , __ | __ | __ | __ | __ | __ | __ | __ ); // batacuda
v( __ | __ | __ | __ | __ | __ | __ | __ , __ | __ | __ | __ | __ | __ | __ | __ ); // batacuda
} // batacuda
void ans1() { // batacuda
v( v1 | v2 | v3 | v4 | __ | __ | v7 | v8 , __ | v2 | v3 | __ | __ | __ | v7 | __ ); // batacuda
v( v1 | __ | __ | v4 | __ | __ | __ | __ , __ | __ | __ | __ | __ | __ | __ | __ ); // batacuda
v( __ | __ | v3 | __ | __ | __ | __ | __ , __ | __ | v3 | __ | __ | __ | __ | __ ); // batacuda
v( v1 | __ | __ | v4 | __ | __ | __ | __ , __ | __ | __ | __ | __ | __ | __ | __ ); // batacuda
v( __ | v2 | v3 | __ | __ | __ | __ | __ , __ | v2 | v3 | __ | __ | __ | __ | __ ); // batacuda
v( v1 | __ | __ | v4 | __ | __ | __ | __ , __ | __ | __ | __ | __ | __ | __ | __ ); // batacuda
v( v1 | __ | __ | v4 | __ | __ | __ | __ , __ | __ | __ | __ | __ | __ | __ | __ ); // batacuda
v( __ | __ | __ | v4 | __ | __ | __ | __ , __ | __ | __ | __ | __ | __ | __ | __ ); // batacuda
} // batacuda

	# define T1 150
	# define P1 75

	# define T2 140
	# define P2 100

	# define T3 75
	# define P3 50

	# define T4 130
	# define P4 100


	void loop() {

		//calibrate();
		goto answer1;


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


z:
		delay(4000);
		mute(r1|g1|b1|w1|r2|g2|b2|w2);
		while (true) delay(1000);
	}

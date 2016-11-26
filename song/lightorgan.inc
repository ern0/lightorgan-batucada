# if ( defined(__unix__) || defined(__APPLE__) )
# include "posixino/posixino.cpp"

# define ON (HIGH)
# define OFF (LOW)
char xlat[] = { 0,1,2,3,4,5,6,7 };

# else
#include <Arduino.h>

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


	void mut(unsigned char bits) {
		setValue(bits,OFF);
	} // mut()


	void lit(unsigned char bits) {
		setValue(bits,ON);
	} // lit


	void setup() {

		for (int n = 0; n < 8; n++) {
			pinMode(xlat[n],OUTPUT);
		}
		mut(r1|g1|b1|w1|r2|g2|b2|w2);

		m(r1,g1,b1,w1,r2,g2,b2,w2);
		d(150,100);

	} // setup()

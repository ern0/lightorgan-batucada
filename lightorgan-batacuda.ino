# if ( defined(__unix__) || defined(__APPLE__) )
# include "../posixino/posixino.cpp"
# endif

char xlat[] = { 0,1,2,3,4,5,6,7 };
# define R1 0x80
# define G1 0x40
# define B1 0x20
# define W1 0x10
# define R2 0x08
# define G2 0x04
# define B2 0x02
# define W2 0x01
# define _ 0x00


	void setup() {

		for (int n = 0; n < 8; n++) pinMode(xlat[n],OUTPUT);

	} // setup()


	void tick(short int d,unsigned char data) {

		digitalWrite(xlat[0],( data & 0x80 ? HIGH : LOW ));
		digitalWrite(xlat[1],( data & 0x40 ? HIGH : LOW ));
		digitalWrite(xlat[2],( data & 0x20 ? HIGH : LOW ));
		digitalWrite(xlat[3],( data & 0x10 ? HIGH : LOW ));
		digitalWrite(xlat[4],( data & 0x08 ? HIGH : LOW ));
		digitalWrite(xlat[5],( data & 0x04 ? HIGH : LOW ));
		digitalWrite(xlat[6],( data & 0x02 ? HIGH : LOW ));
		digitalWrite(xlat[7],( data & 0x01 ? HIGH : LOW ));

		delay(d);

	} // tick()


	void test() {
		tick(100,0);
		tick(2000,0xff);
		tick(4000,0);
	} // test()


	void intro1(short int d1,int shift) {

		int d2 = d1 + d1;
		int d3 = d1 + d2;

		tick(d1, W1 >> shift);
		tick(d1, _ );
		tick(d1, W1 >> shift);
		tick(d3, _ );

		tick(d1, W1 >> shift);
		tick(d1, _ );
		tick(d1, W1 >> shift);
		tick(d3, _ );

		tick(d1, W1 >> shift);
		tick(d1, _ );
		tick(d1, W1 >> shift);
		tick(d1, _ );
		tick(d1, W1 >> shift);
		tick(d1, _ );
		tick(d1, W1 >> shift);
		tick(d1, _ );
		tick(d1, W1 >> shift);
		tick(d3, _ );

	} // intro1()


	void loop() {

		//test();
		intro1(200,0);
		intro1(200,4);


	} // loop()

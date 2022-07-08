#include <bb.h>
// Please don't use delay() function in your code 

#define pin 5
bb button1(pin);
// bb button1(pin, 15);

void setup() {
 	Serial.begin(9600);
 	// Serial.begin(115200);
}

void loop() {
	// Check and update button condition
	// If you use more then one button, you must writes check() functions to all of them
	button1.check();
	//Take number of taps
  	byte num = button1.getTaps();
  	if (num > 0) {
    	Serial.print(num);
    	Serial.println(" tap(s)");
  	}
}

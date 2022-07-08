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
  //Check and update button condition
  //If u use more then one button, you must write check() functions to all of them
  button1.check();

  //Single tap
  if(button1.isSingle()) Serial.println("Single tap");
  //Double tap
  if(button1.isDouble()) Serial.println("Double tap");
  //Triple tap
  if(button1.isTriple()) Serial.println("Triple tap");

  // Do anything for long time when button is holded
  if(button1.isHold()) Serial.println("HoldHoldHold");
  // Do anything one time when button was holded
  if(button1.isHolded()) Serial.println("Hold");
}

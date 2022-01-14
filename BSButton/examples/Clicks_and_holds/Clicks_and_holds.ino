#define pin 5
BSBtn button1(pin);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  button1.check();
  //Single tap
  if(button1.isSingle()) Serial.println("Single tap");
  //Double tap
  if(button1.isSingle()) Serial.println("Double tap");
  //Triple tap
  if(button1.isSingle()) Serial.println("Triple tap");
  //Do anything for long time when button was holded
  if(button1.isHold()) Serial.println("HoldHoldHold");
  //Do anything one time when button was holded
  if(button1.isHolded()) Serial.println("Hold");
}

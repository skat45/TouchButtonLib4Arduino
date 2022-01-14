#define pin 5
BSBtn button1(pin);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  byte var = button1.getTaps();
  if(var > 0){
    Serial.print(i);
    Serial.println(" taps");
  }
}

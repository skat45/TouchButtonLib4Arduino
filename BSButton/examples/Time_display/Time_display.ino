// This example helps you count number of cycles that compeated until metal charge
// If library works not well, use bb 'name'(pin, numbre_of_cycles) instead bb 'name'(pin)
// numbre_of_cycles must be greater than unmber that you see in serial port when you don't touch the button

#define pin 5
#define DISCHARGETIME 15
// In bb library DISCHARGETIME equals 5 ms

void setup() {
  Serial.begin(9600);
  // Serial.begin(115200);

}

void loop() {
  pinMode(pin, OUTPUT);
  digitalWrite(pin, LOW);
  delay(DISCHARGETIME);
  pinMode(pin, INPUT);
  byte counter = 0;
  while (!digitalRead(pin)) counter++;
  Serial.println(counter);
}

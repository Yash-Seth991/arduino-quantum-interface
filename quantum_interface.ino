int redPin = 9;
int bluePin = 10;

void setup() {
  Serial.begin(115200);
  pinMode(redPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}

void loop() {
  if (Serial.available() > 0) {
    char bit = Serial.read();
    if (bit == '0') {
      digitalWrite(redPin, HIGH);
      digitalWrite(bluePin, LOW);
    } else if (bit == '1') {
      digitalWrite(redPin, LOW);
      digitalWrite(bluePin, HIGH);
    }
  }
}

void setup() {
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int speed = 255;
  analogWrite(11, speed);
  analogWrite(6, speed);

  if (Serial.available()) {
    int numbers = Serial.read();

    if (numbers == '1') {
      digitalWrite(10, LOW);
      digitalWrite(8, LOW);
      digitalWrite(9, LOW);
      digitalWrite(7, LOW);
    } else if (numbers == '2') {
      digitalWrite(10, HIGH);
      digitalWrite(9, LOW);
      digitalWrite(8, LOW);
      digitalWrite(7, LOW);
    } else if (numbers == '3') {
      digitalWrite(10, LOW);
      digitalWrite(9, HIGH);
      digitalWrite(8, LOW);
      digitalWrite(7, LOW);
    } else if (numbers == '4') {
      digitalWrite(10, LOW);
      digitalWrite(9, LOW);
      digitalWrite(8, HIGH);
      digitalWrite(7, LOW);
    } else if (numbers == '5') {
      digitalWrite(10, LOW);
      digitalWrite(9, LOW);
      digitalWrite(8, LOW);
      digitalWrite(7, HIGH);
    } else if (numbers == '6') {
      digitalWrite(10, HIGH);
      digitalWrite(9, LOW);
      digitalWrite(8, HIGH);
      digitalWrite(7, LOW);
    } else if (numbers == '7') {
      digitalWrite(10, LOW);
      digitalWrite(9, HIGH);
      digitalWrite(8, LOW);
      digitalWrite(7, HIGH);
    }
  }
}
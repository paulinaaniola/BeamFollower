int photoIn1 = 1; // left photoresistor on Analogue Pin 1
int photoIn2 = 2; // right photoresistor on Analogue Pin 2
int aiValueL = 0; // input value
int aiValueP = 0; // input value

void setup() {
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);

}
void rightMotor(int8_t _speed) {
  digitalWrite(6, LOW);
  digitalWrite(7, HIGH);
  analogWrite(5, _speed);

}

void leftMotor(int8_t _speed) {
  digitalWrite(10, LOW);
  digitalWrite(8, HIGH);
  analogWrite(9, _speed);

}

void loop() {

  aiValueL = analogRead(photoIn1); // LEFT PHOTORESISTOR
  aiValueP = analogRead(photoIn2); // RIGHT PHOTORESISTOR

  if (abs(aiValueL - aiValueP) <= 100) //GO STRAIGHT
  {
    rightMotor(120);
    leftMotor(120);
  } else {
    if (aiValueL > aiValueP) // GO LEFT
    {

      if ((aiValueL - aiValueP) >= 100 && (aiValueL - aiValueP) < 250) {
        leftMotor(142);
        rightMotor(110);
      }

      if ((aiValueL - aiValueP) >= 250 && (aiValueL - aiValueP) < 400) {
        leftMotor(164);
        rightMotor(100);
      }

      if ((aiValueL - aiValueP) >= 400 && (aiValueL - aiValueP) < 550) {
        leftMotor(186);
        rightMotor(90);
      }

      if ((aiValueL - aiValueP) >= 550 && (aiValueL - aiValueP) < 700) {
        leftMotor(210);
        rightMotor(80);
      }
      if ((aiValueL - aiValueP) >= 700) {
        leftMotor(255);
        rightMotor(70);
      }
    }

    if (aiValueP > aiValueL) { //GO RIGHT

      if ((aiValueP - aiValueL) >= 100 && (aiValueP - aiValueL) < 250) {
        leftMotor(110);
        rightMotor(142);
      }

      if ((aiValueP - aiValueL) >= 250 && (aiValueP - aiValueL) < 400) {
        leftMotor(100);
        rightMotor(164);
      }

      if ((aiValueP - aiValueL) >= 400 && (aiValueP - aiValueL) < 550) {
        leftMotor(90);
        rightMotor(186);
      }

      if ((aiValueP - aiValueL) >= 550 && (aiValueP - aiValueL) < 700) {
        leftMotor(80);
        rightMotor(210);
      }
      if ((aiValueP - aiValueL) >= 700) {
        leftMotor(70);
        rightMotor(255);
      }
    }
  }
}
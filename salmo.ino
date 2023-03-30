#include <Servo.h>

Servo myservo;

const int buttonPin = 2;
int val;
int buttonState = 0;

void setup()
{
  myservo.attach(9);
  pinMode(buttonPin, INPUT);       
}

void loop()
{
  buttonState = digitalRead(buttonPin);
  if (buttonState == HIGH) {     
    val = 180; 
  }
  else {

    val = 0;
  }
  myservo.write(val);
  delay(15);
}
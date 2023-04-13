const int sensorPin = 0;  
const int buttonPin = 2;  
const int ledPin = 13;    

int sensorValue = 0;      
int buttonState = 0;      

void setup() {
  pinMode(buttonPin, INPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  buttonState = digitalRead(buttonPin);

  if (buttonState == HIGH) {
    sensorValue = analogRead(sensorPin);
    Serial.println(sensorValue);

    if (sensorValue < 500) {
      digitalWrite(ledPin, HIGH);
    } else {
      digitalWrite(ledPin, LOW);
    }
  }
}
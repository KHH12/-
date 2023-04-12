// IR 센서 연결 핀 설정
int leftSensorPin = A5;  
int middleSensorPin = A3;  
int rightSensorPin = A1; 

// 모터 드라이버 핀 설정
int leftMotorPin1 = 5;
int leftMotorPin2 = 6;
int rightMotorPin1 = 10;
int rightMotorPin2 = 9;

void setup()
{
  // IR 센서 핀 설정
  pinMode(leftSensorPin, INPUT);
  pinMode(middleSensorPin, INPUT);
  pinMode(rightSensorPin, INPUT);
  
  // 모터 드라이버 핀 설정
  pinMode(leftMotorPin1, OUTPUT);
  pinMode(leftMotorPin2, OUTPUT);
  pinMode(rightMotorPin1, OUTPUT);
  pinMode(rightMotorPin2, OUTPUT);
  
  // 시리얼 통신 시작
  Serial.begin(9600);
}

void loop()
{
  int leftSensorValue = digitalRead(leftSensorPin);
  int middleSensorValue = digitalRead(middleSensorPin);
  int rightSensorValue = digitalRead(rightSensorPin);
  
  // 센서 값을 시리얼 모니터에 출력
  Serial.print(leftSensorValue);
  Serial.print(" ");
  Serial.print(middleSensorValue);
  Serial.print(" ");
  Serial.println(rightSensorValue);
  
  // 모터 동작을 제어하는 if문
  // 센서 값을 기준으로 조건문을 작성하여 모터를 제어합니다.
  if(leftSensorValue == HIGH && middleSensorValue == LOW && rightSensorValue == LOW) // 왼쪽 센서만 검출
  {
    digitalWrite(leftMotorPin1, HIGH);
    digitalWrite(leftMotorPin2, LOW);
    digitalWrite(rightMotorPin1, LOW);
    digitalWrite(rightMotorPin2, LOW);
  }
  else if(leftSensorValue == LOW && middleSensorValue == HIGH && rightSensorValue == LOW) // 중앙 센서만 검출
  {
    digitalWrite(leftMotorPin1, HIGH);
    digitalWrite(leftMotorPin2, LOW);
    digitalWrite(rightMotorPin1, HIGH);
    digitalWrite(rightMotorPin2, LOW);
  }
  else if(leftSensorValue == LOW && middleSensorValue == LOW && rightSensorValue == HIGH) // 오른쪽 센서만 검출
  {
    digitalWrite(leftMotorPin1, LOW);
    digitalWrite(leftMotorPin2, LOW);
    digitalWrite(rightMotorPin1, HIGH);
    digitalWrite(rightMotorPin2, LOW);
  }
  else if(leftSensorValue == LOW && middleSensorValue == LOW && rightSensorValue == LOW) // 센서값을 모두 감지하지 못한 경우
  {
    digitalWrite(leftMotorPin1, HIGH);
    digitalWrite(leftMotorPin2, LOW);
    digitalWrite(rightMotorPin1, HIGH);
    digitalWrite(rightMotorPin2, LOW);
  }
  else // 모든 경우에 해당하지 않는 경우
  {
    digitalWrite(leftMotorPin1, LOW);
    digitalWrite(leftMotorPin2, LOW);
    digitalWrite(rightMotorPin1, LOW);
    digitalWrite(rightMotorPin2, LOW);
  }
}
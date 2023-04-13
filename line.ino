// 변수 설정
int leftMotor = 6;  // 왼쪽 모터 핀 번호
int rightMotor = 9;  // 오른쪽 모터 핀 번호
int centerSensor = A3;  // 중앙 IR 센서 핀 번호
int threshold = 500;  // 검은색 라인을 감지하는 임계값
int distanceSensor = 3; // 거리 센서 핀 번호
int minDistance = 10; // 정지해야 할 최소 거리 (단위: cm)

void setup() {
  pinMode(leftMotor, OUTPUT);
  pinMode(rightMotor, OUTPUT);
  pinMode(centerSensor, INPUT);
  pinMode(distanceSensor, INPUT);
  
  Serial.begin(9600); // 시리얼 통신 속도 9600bps로 초기화
}

void loop() {
  int centerValue = analogRead(centerSensor);
  int distance = getDistance(); // 거리 측정
  
  // 거리가 최소 거리보다 작을 경우 모터를 정지시킴
  if (distance < minDistance) {
    digitalWrite(leftMotor, LOW);
    digitalWrite(rightMotor, LOW);
  }
  // 중앙 센서가 검은색 라인을 감지할 경우 직진
  else if (centerValue < threshold) {
    digitalWrite(leftMotor, HIGH);
    digitalWrite(rightMotor, HIGH);
  }
  // 두 센서가 검은색 라인을 감지하지 못할 경우 모터를 정지시킴
  else {
    digitalWrite(leftMotor, LOW);
    digitalWrite(rightMotor, LOW);
  }
  
  // centerValue, distance 값을 시리얼 모니터에 출력
  Serial.print("Center Value: ");
  Serial.print(centerValue);
  Serial.print(", Distance: ");
  Serial.print(distance);
  Serial.println("cm");
  
  delay(100);  // 0.1초(100ms) 지연
}

// 거리 측정 함수
int getDistance() {
  long duration;
  int distance;
  
  // Trig 핀에 10 마이크로초 동안 펄스를 발생시켜 Echo 핀에서 돌아오는 시간을 측정
  digitalWrite(distanceSensor, LOW);
  delayMicroseconds(2);
  digitalWrite(distanceSensor, HIGH);
  delayMicroseconds(10);
  digitalWrite(distanceSensor, LOW);
  
  duration = pulseIn(distanceSensor, HIGH); // Echo 핀에서 돌아오는 시간 측정
  distance = duration / 10; // 시간을 거리로 변환 (단위: cm)
  
  return distance;
}
## ARDUINO CODE

#define trigPin 9
#define echoPin 10

#define leftIR 2
#define rightIR 3

#define motorLeft1 4
#define motorLeft2 5
#define motorRight1 6
#define motorRight2 7

long duration;
int distance;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
  pinMode(leftIR, INPUT);
  pinMode(rightIR, INPUT);

  pinMode(motorLeft1, OUTPUT);
  pinMode(motorLeft2, OUTPUT);
  pinMode(motorRight1, OUTPUT);
  pinMode(motorRight2, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  // Ultrasonic distance measurement
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;

  int left = digitalRead(leftIR);
  int right = digitalRead(rightIR);

  // Logic
  if (distance > 10 && distance < 100) {
    if (left == LOW && right == LOW) {
      forward();
    }
    else if (left == LOW) {
      leftTurn();
    }
    else if (right == LOW) {
      rightTurn();
    }
  } else {
    stopRobot();
  }
}

void forward() {
  digitalWrite(motorLeft1, HIGH);
  digitalWrite(motorLeft2, LOW);
  digitalWrite(motorRight1, HIGH);
  digitalWrite(motorRight2, LOW);
}

void leftTurn() {
  digitalWrite(motorLeft1, LOW);
  digitalWrite(motorLeft2, HIGH);
  digitalWrite(motorRight1, HIGH);
  digitalWrite(motorRight2, LOW);
}

void rightTurn() {
  digitalWrite(motorLeft1, HIGH);
  digitalWrite(motorLeft2, LOW);
  digitalWrite(motorRight1, LOW);
  digitalWrite(motorRight2, HIGH);
}

void stopRobot() {
  digitalWrite(motorLeft1, LOW);
  digitalWrite(motorLeft2, LOW);
  digitalWrite(motorRight1, LOW);
  digitalWrite(motorRight2, LOW);
}

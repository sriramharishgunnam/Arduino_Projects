// Square movement using L298N motor driver
// Forward + 90 degree right turn
#define ENA 5
#define ENB 6
#define IN1 8
#define IN2 9
#define IN3 10
#define IN4 11
void setup() {
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  // Motor speed
  analogWrite(ENA, 112);
  analogWrite(ENB, 112);
}
void loop() {
  // Repeat 4 sides = square
  for (int i = 0; i < 4; i++) {
    forward();
    delay(1000);        // move forward (adjust for side length)
    stopMotors();
    delay(300);
    rightTurn();
    delay(450);         // 90 degree turn (ADJUST THIS)
    stopMotors();
    delay(300);
  }
  // Stop after one square
  stopMotors();
  while(1); // halt
}
// -------- Motor functions --------
void forward() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}
void rightTurn() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}
void stopMotors() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}


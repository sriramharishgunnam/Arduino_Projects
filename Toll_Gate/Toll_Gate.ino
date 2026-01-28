// Eazytronic.com
#include <Servo.h> // servo library

Servo s1;                  // Servo object
const int trigPin = 10;    // Ultrasonic TRIG pin
const int echoPin = 9;     // Ultrasonic ECHO pin

long duration;
int distanceCm, distanceInch;

void setup() {
  Serial.begin(9600); 
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  s1.attach(3);   // Servo Motor signal wire connected to pin 3
}

void loop() {
  // --- Ultrasonic trigger pulse ---
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // --- Measure echo ---
  duration = pulseIn(echoPin, HIGH);

  // --- Convert to distance ---
  distanceCm = duration * 0.034 / 2;   // speed of sound in cm/us
  distanceInch = duration * 0.0133 / 2;

  // --- Print distance ---
  Serial.print("Distance: ");
  Serial.print(distanceCm);
  Serial.println(" cm");

  delay(50);

  // --- Gate logic ---
  if (distanceCm < 10) {
    s1.write(90);   // rotate servo to 90° (open gate)
    delay(1000);    // keep gate open for 1 second
  } else {
    s1.write(0);    // rotate servo back to 0° (closed gate)
    delay(10);
  }
}

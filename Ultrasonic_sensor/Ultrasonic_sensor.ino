// To use ArduinoGraphics APIs, please include BEFORE Arduino_LED_Matrix
#include "ArduinoGraphics.h"
#include "Arduino_LED_Matrix.h"

ArduinoLEDMatrix matrix;          // Create matrix object

const int trigPin = 8;
const int echoPin = 7;
const int greenled = 10;
const int yellowled = 10;
const int redled = 10;



long duration;
int distance;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  Serial.begin(9600);   // ✅ Added for Serial Monitor

  matrix.begin();
delay(2000);

  }

void loop() {
  // Trigger ultrasonic pulse
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);  
  digitalWrite(trigPin, LOW);

  // Measure echo
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;

  // ✅ Print distance to Serial Monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  // LED matrix part untouched
  matrix.beginDraw();
  matrix.stroke(0xFFFFFFFF);
  const char text[] = "    Ultrasonic Sensor    ";
  matrix.textFont(Font_5x7);
  matrix.beginText(0, 1, 0xFFFFFF);
  matrix.print(distance);   // keep your matrix display
  matrix.endText();
  matrix.endDraw();

if (distance >=100) {
digitalWrite(greenled, HIGH )
 }
   else {
    digitalWrite(greenled, LOW );    // turn OFF green LED
  }

  if (distance >100) {
digitalWrite(greenled, HIGH )
 }
   else {
    digitalWrite(greenled, LOW );    // turn OFF green LED
  }
}

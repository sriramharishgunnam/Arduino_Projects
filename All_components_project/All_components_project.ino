// Pin setup
const int Potentiometer = A0;
const int ButtonPin = 2;
const int LDRPin = A1;

const int MotorPin = 10;
const int Green_led = 13;
const int Yellow_led = 12;
const int Red_led = 11;

int threshold = 500;
bool fanstate = false;

void setup() {
  pinMode(ButtonPin, INPUT_PULLUP);
  pinMode(MotorPin, OUTPUT);

  pinMode(Green_led, OUTPUT);
  pinMode(Yellow_led, OUTPUT);
  pinMode(Red_led, OUTPUT);
}

void loop() {
  // Toggle fan state on button press
  if (digitalRead(ButtonPin) == LOW) {
    fanstate = !fanstate;
    delay(200); // debounce delay
  }

  int Light_level = analogRead(LDRPin);

  if (fanstate && Light_level > threshold) {
    int potValue = analogRead(Potentiometer);
    int speed = map(potValue, 0, 1023, 0, 255);
    analogWrite(MotorPin, speed);

    // LED indicators based on speed
    if (speed < 85) {
      digitalWrite(Green_led, HIGH);
      digitalWrite(Yellow_led, LOW);
      digitalWrite(Red_led, LOW);
    } else if (speed < 170) {
      digitalWrite(Green_led, LOW);
      digitalWrite(Yellow_led, HIGH);
      digitalWrite(Red_led, LOW);
    } else {
      digitalWrite(Green_led, LOW);
      digitalWrite(Yellow_led, LOW);
      digitalWrite(Red_led, HIGH);
    }
  } else {
    // Turn off motor and LEDs
    analogWrite(MotorPin, 0);
    digitalWrite(Green_led, LOW);
    digitalWrite(Yellow_led, LOW);
    digitalWrite(Red_led, LOW);
  }

  delay(100); // stability delay
}

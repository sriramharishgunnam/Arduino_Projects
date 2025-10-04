// LED Blink using millis() - Non-blocking + Push Button Controlled LED

const int led_pin_1 = 13;    
const int led_pin_2 = 12;
const int led_pin_3 = 8;     // Third LED pin
const int buttonPin = 7;     // Push button pin

unsigned long pmillis_1 = 0; // store last time LED1 changed
unsigned long pmillis_2 = 0; // store last time LED2 changed

const long interval_1 = 1000; // blink interval for LED1 (ms)
const long interval_2 = 500;  // blink interval for LED2 (ms)

int ledState_1 = LOW;  // current state of LED1
int ledState_2 = LOW;  // current state of LED2

void setup() {
  pinMode(led_pin_1, OUTPUT);
  pinMode(led_pin_2, OUTPUT);
  pinMode(led_pin_3, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP); // Button to GND when pressed
}

void loop() {
  unsigned long currentMillis = millis();  // get current time

  // LED1 blinking
  if (currentMillis - pmillis_1 >= interval_1) {
    pmillis_1 = currentMillis;
    ledState_1 = (ledState_1 == LOW) ? HIGH : LOW;
    digitalWrite(led_pin_1, ledState_1);
  }
  
  // LED2 blinking
  if (currentMillis - pmillis_2 >= interval_2) {
    pmillis_2 = currentMillis;
    ledState_2 = (ledState_2 == LOW) ? HIGH : LOW;
    digitalWrite(led_pin_2, ledState_2);
  }

  // LED3 controlled by push button
  int buttonState = digitalRead(buttonPin);
  if (buttonState == LOW) { // Button pressed
    digitalWrite(led_pin_3, HIGH);
  } else {
    digitalWrite(led_pin_3, LOW);
  }
}

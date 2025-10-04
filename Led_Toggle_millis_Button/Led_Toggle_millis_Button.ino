// LED Blink using millis() - Non-blocking 
// + Toggle LED with button (NO debounce)

const int ledPin1 = 13;     // Built-in LED pin on Arduino
unsigned long previousMillis = 0; // store last time LED changed
const long interval = 200;  // interval at which to blink (ms)
int ledState1 = LOW;        // current state of blinking LED

const int buttonPin = 2;    // Push button pin
const int ledPin2 = 11;     // LED pin for toggle
int ledState2 = LOW;        // current LED state
int lastButtonState = HIGH; // previous button state

void setup() {
  pinMode(ledPin1, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);  // Enable internal pull-up
  pinMode(ledPin2, OUTPUT);
}

void loop() {
  unsigned long currentMillis = millis();  // get current time

  // --- Blink LED with millis() ---
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;  
    ledState1 = !ledState1;   // toggle state
    digitalWrite(ledPin1, ledState1);
  }

  // --- Toggle LED with button (no debounce) ---
  int reading = digitalRead(buttonPin);

  if (reading == LOW && lastButtonState == HIGH) {
    ledState2 = !ledState2;   // toggle the LED state
    digitalWrite(ledPin2, ledState2);
    delay(200); // just to slow down bouncing a little
  }

  lastButtonState = reading;
}

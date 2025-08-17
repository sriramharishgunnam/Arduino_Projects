const int ledPin = 13;

void setup() {
  Serial.begin(9600);
  Serial.println("LEd Blink(builtin)");
  pinMode(ledPin, OUTPUT);

}

void loop() {
  digitalWrite(ledPin, HIGH);
  Serial.println("Your_led_is_on");
  delay(10000); 

  digitalWrite(LED_BUILTIN, LOW);
  Serial.println("Your_led_is_off");
  delay(10000);

}

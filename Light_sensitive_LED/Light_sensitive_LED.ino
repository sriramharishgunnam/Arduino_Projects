const int ldr_pin = A1;
const int led_pin = 9;

void setup() {
  pinMode(led_pin, OUTPUT);
  }

void loop() {
  int ldr_value = analogRead(ldr_pin);
   if(ldr_value < 900){
    digitalWrite(led_pin, HIGH);
  }
    else{
    digitalWrite(led_pin, LOW);
   }
}


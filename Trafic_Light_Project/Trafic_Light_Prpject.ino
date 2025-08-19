 const int  green (9) ;
 const int  yellow (10);
 const int  red    (11);
 const int  blue   (12);
 const int  Switch (8);

void setup() {
  pinMode( 9, OUTPUT);
  pinMode( 10, OUTPUT);
  pinMode( 11, OUTPUT);
  pinMode( 12, OUTPUT);
  pinMode(8, INPUT);

}

void loop() {
 digitalWrite(9, HIGH );
delay(20000);
 digitalWrite(9, LOW );

 digitalWrite(10, HIGH);
delay(5000);
 digitalWrite(9, LOW );

 digitalWrite(11, HIGH);
delay(15000);
 digitalWrite(11, LOW);

 if (digitalRead(8) == HIGH) { digitalWrite (12, HIGH);
 delay(10000);
 digitalWrite(12, LOW);
 }

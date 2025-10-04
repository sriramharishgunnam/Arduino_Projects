#include "Arduino_LED_Matrix.h"   //Include the LED_Matrix library
#include "SHG_FRAMES.h"

// Create an instance of the ArduinoLEDMatrix class
ArduinoLEDMatrix matrix;

void setup() {
  Serial.begin(115200);
  matrix.begin();
}
   void loop(){
    matrix.loadFrame(MINI_ROBOT);
   }
   

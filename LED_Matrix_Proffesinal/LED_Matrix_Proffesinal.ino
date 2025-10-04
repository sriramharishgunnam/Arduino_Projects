#include "Arduino_LED_Matrix.h"   // Include the LED_Matrix library

ArduinoLEDMatrix matrix;          // Create an instance of the ArduinoLEDMatrix class

void setup() {
  Serial.begin(115200);           // Initialize serial communication at a baud rate of 115200
  matrix.begin();                 // Initialize the LED matrix

}

void loop() {
  // Load and display the basic emoji frame on the LED matrix
  matrix.loadFrame(LEDMATRIX_EMOJI_BASIC);
  delay(500);
  matrix.loadFrame(LEDMATRIX_BLUETOOTH);
  delay(500);
  matrix.loadFrame(LEDMATRIX_BOOTLOADER_ON);
  delay(500);
  matrix.loadFrame(LEDMATRIX_CHIP);
  delay(500);
  matrix.loadFrame(LEDMATRIX_CLOUD_WIFI);
  delay(500);
  matrix.loadFrame(LEDMATRIX_DANGER);
  delay(500);
  matrix.loadFrame(LEDMATRIX_EMOJI_BASIC);
  delay(500); 
  matrix.loadFrame(LEDMATRIX_EMOJI_HAPPY);
  delay(500); 
  matrix.loadFrame(LEDMATRIX_EMOJI_SAD);
  delay(500); 
  matrix.loadFrame(LEDMATRIX_HEART_BIG);
  delay(500); 
  matrix.loadFrame(LEDMATRIX_HEART_SMALL);
  delay(500); 
  matrix.loadFrame(LEDMATRIX_LIKE);
  delay(500); 
  matrix.loadFrame(LEDMATRIX_MUSIC_NOTE);
  delay(500); 
  matrix.loadFrame(LEDMATRIX_RESISTOR);
  delay(500); 
  matrix.loadFrame(LEDMATRIX_UNO);
  delay(500); 
  
}
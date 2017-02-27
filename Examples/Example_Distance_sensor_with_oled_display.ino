#include <hcsr04.h>

/*  OLED          arduino
     D0-----------10
     D1-----------9
     RST----------7
     DC-----------11
     VCC----------5V
     GND----------GND*/
// Simple software SPI test for ebay 128x64 oled.

// pin definitions
#define OLED_D0    8
#define OLED_D1    7
#define OLED_RST   6
#define OLED_DC    5
#define OLED_CS    4

#define TRIG_PIN  A1
#define ECHO_PIN  A0

#include <SSD1306Ascii.h>
#include <SSD1306AsciiSoftSpi.h>

SSD1306AsciiSoftSpi oled;

HCSR04 sensor;

//------------------------------------------------------------------------------
void setup() {         
  oled.begin(&Adafruit128x64, OLED_CS, OLED_DC, OLED_D0, OLED_D1, OLED_RST);
  oled.setFont(Adafruit5x7);
  oled.clear(); 
  oled.set2X(); 

  //double calibration = 2.1d;
  //short offset = -40;

  sensor.init(TRIG_PIN, ECHO_PIN);
  //sensor.setCalibration(calibration);
  //sensor.setOffset(offset);
  
}
//------------------------------------------------------------------------------

long distance;
 
void loop(){

  distance = sensor.readAccurateDisctanceInCm();
  
  oled.clear();  
  oled.println("Tavolsag: ");
  oled.println();
  oled.print("  ");
  oled.print(distance);
  oled.println(" cm");
  delay(500);
}

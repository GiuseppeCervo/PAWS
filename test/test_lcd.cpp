#include <Arduino.h>
#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include "SensorControl.h"
#include "Config.h"
#include <U8g2lib.h>

#ifdef U8X8_HAVE_HW_I2C
#include <Wire.h>
#endif

//U8G2_ST7920_128X64_F_SW_SPI u8g2(U8G2_R0, EN , R/W, DS/RS, [RST]);
U8G2_ST7920_128X64_F_SW_SPI u8g2(U8G2_R0, /* clock=*/ 18, /* data=*/ 22, /* CS=*/ 23, U8X8_PIN_NONE);

SensorControl sensorControl;

void drawLogo();
void drawURL();

void setup() {
  // Sensor control --- Wire.begin(MPU_SDA_PIN, MPU_SCL_PIN, I2C_FREQ);
  Serial.begin(BAUDRATE);
  // define logging level
  // Log.begin(LOG_LEVEL_VERBOSE, &Serial);
  
  // Sensor control --- sensorControl.begin();

  u8g2.begin();
  u8g2.clearBuffer();
}

void loop() {
    

  // Retrieve and print the sensor data
  /*
  sensorControl.performReading();
  delay(100);
  SensorData data = sensorControl.getReading();
  char parsedData[150];
  sensorControl.parseSensorDataToCharArray(data, parsedData, 50);
  Serial.println(parsedData);

  delay(1000); // Delay for a second before the next reading
  */
 
  drawLogo();
  delay(10000); 
}

/*
  U8g2lib Example Overview:
    Frame Buffer Examples: clearBuffer/sendBuffer. Fast, but may not work with all Arduino boards because of RAM consumption
    Page Buffer Examples: firstPage/nextPage. Less RAM usage, should work with all Arduino boards.
    U8x8 Text Only Example: No RAM usage, direct communication with display controller. No graphics, 8x8 Text only.
    
  This is a page buffer example.    
*/

// Please UNCOMMENT one of the contructor lines below
// U8g2 Contructor List (Picture Loop Page Buffer)
// The complete list is available here: https://github.com/olikraus/u8g2/wiki/u8g2setupcpp
// Please update the pin numbers according to your setup. Use U8X8_PIN_NONE if the reset pin is not connected

void drawLogo(void) {
  static const unsigned char hello_screen[] = {
  0xFE, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
  0xFF, 0xFF, 0xFF, 0x03, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x07, 0x03, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 
  0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x06, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x03, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 
  0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x06, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x03, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 
  0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x06, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x03, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 
  0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x06, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0xFF, 0xFF, 0xFF, 0xFF, 
  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x07, 
  0xFE, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
  0xFF, 0xFF, 0xFF, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0xFE, 0x3F, 0xF8, 0xFF, 0xE0, 0xFF, 0x83, 0xFF, 0x0F, 0xFE, 0x3F, 0xF8, 
  0xFF, 0xE0, 0xFF, 0x03, 0xFF, 0x7F, 0xFC, 0xFF, 0xF1, 0xFF, 0x83, 0xFF, 
  0x0F, 0xFE, 0x3F, 0xFC, 0xFF, 0xF1, 0xFF, 0x07, 0x03, 0x60, 0x0C, 0xC0, 
  0x31, 0x00, 0xC2, 0x00, 0x08, 0x02, 0x60, 0x1C, 0x80, 0x31, 0x00, 0x06, 
  0x03, 0x60, 0x0C, 0xC0, 0x31, 0x00, 0xC2, 0x00, 0x08, 0x02, 0x60, 0x1C, 
  0x80, 0x31, 0x00, 0x06, 0xC3, 0x60, 0x0C, 0xC3, 0x31, 0x1C, 0xC2, 0x60, 
  0x08, 0xC2, 0x61, 0x1C, 0x84, 0x31, 0x3C, 0x06, 0xC3, 0x60, 0x0C, 0xC4, 
  0x31, 0x10, 0xC2, 0x70, 0x08, 0x42, 0x60, 0x1C, 0x82, 0x31, 0x10, 0x06, 
  0x83, 0x60, 0x0C, 0xC6, 0x31, 0x0C, 0xC2, 0x70, 0x08, 0xC2, 0x61, 0x1C, 
  0x87, 0x31, 0x10, 0x06, 0x83, 0x60, 0x0C, 0xC2, 0x31, 0x10, 0xC2, 0xF8, 
  0x08, 0x02, 0x61, 0x1C, 0x8F, 0x31, 0x18, 0x06, 0x83, 0x60, 0x0C, 0xC7, 
  0x31, 0x1C, 0xC2, 0x40, 0x08, 0xC2, 0x61, 0x1C, 0x8F, 0x31, 0x08, 0x06, 
  0x03, 0x60, 0x0C, 0xC0, 0x31, 0x00, 0xC2, 0x00, 0x08, 0x02, 0x60, 0x1C, 
  0x80, 0x31, 0x00, 0x06, 0x03, 0x60, 0x0C, 0xC0, 0x31, 0x00, 0xC2, 0x00, 
  0x08, 0x02, 0x60, 0x1C, 0x80, 0x31, 0x00, 0x06, 0x03, 0x60, 0x0C, 0xC0, 
  0x31, 0x00, 0xC2, 0x00, 0x08, 0x02, 0x60, 0x1C, 0x80, 0x31, 0x00, 0x06, 
  0x03, 0x60, 0x0C, 0xC0, 0x31, 0x00, 0xC2, 0x00, 0x08, 0x02, 0x60, 0x1C, 
  0x80, 0x31, 0x00, 0x06, 0xF3, 0x67, 0xCC, 0x9F, 0xB1, 0x7F, 0xC2, 0xFC, 
  0x09, 0xF2, 0x67, 0xCC, 0x9F, 0x31, 0x7F, 0x06, 0xFB, 0x6F, 0xEC, 0x9F, 
  0xB1, 0x7F, 0xC2, 0xFE, 0x09, 0xF2, 0x6F, 0xCC, 0xBF, 0xB1, 0xFF, 0x06, 
  0xFB, 0x6F, 0xEC, 0x9F, 0xB1, 0x7F, 0xC2, 0xFE, 0x09, 0xF2, 0x6F, 0xCC, 
  0xBF, 0xB1, 0xFF, 0x06, 0xFB, 0x6F, 0xEC, 0x9F, 0xB1, 0x7F, 0xC2, 0xFE, 
  0x09, 0xF2, 0x6F, 0xCC, 0xBF, 0xB1, 0xFF, 0x06, 0xFB, 0x67, 0xEC, 0x9F, 
  0xB1, 0x7F, 0xC2, 0xFC, 0x09, 0xF2, 0x67, 0xCC, 0xBF, 0x31, 0xFF, 0x06, 
  0x03, 0x60, 0x0C, 0xC0, 0x31, 0x00, 0xC2, 0x00, 0x08, 0x02, 0x60, 0x1C, 
  0x80, 0x31, 0x00, 0x06, 0x03, 0x60, 0x0C, 0xC0, 0x31, 0x00, 0xC2, 0x00, 
  0x08, 0x02, 0x60, 0x1C, 0x80, 0x31, 0x00, 0x06, 0xFB, 0x6F, 0xEC, 0x9F, 
  0xB1, 0x7F, 0xC2, 0xFC, 0x09, 0xF2, 0x67, 0xCC, 0xBF, 0xB1, 0xFF, 0x06, 
  0xFB, 0x6F, 0xEC, 0x9F, 0xB1, 0x7F, 0xC2, 0xFE, 0x09, 0xF2, 0x6F, 0xCC, 
  0xBF, 0xB1, 0xFF, 0x06, 0xFB, 0x6F, 0xEC, 0x9F, 0xB1, 0x7F, 0xC2, 0xFE, 
  0x09, 0xF2, 0x6F, 0xCC, 0xBF, 0xB1, 0xFF, 0x06, 0xFB, 0x67, 0xEC, 0x9F, 
  0xB1, 0x7F, 0xC2, 0xFC, 0x09, 0xF2, 0x67, 0xCC, 0xBF, 0x31, 0xFF, 0x06, 
  0x03, 0x60, 0x0C, 0xC0, 0x31, 0x00, 0xC2, 0x00, 0x08, 0x02, 0x60, 0x1C, 
  0x80, 0x31, 0x00, 0x06, 0x03, 0x60, 0x0C, 0xC0, 0x31, 0x00, 0xC2, 0x00, 
  0x08, 0x02, 0x60, 0x1C, 0x80, 0x31, 0x00, 0x06, 0xFB, 0x67, 0xEC, 0x9F, 
  0xB1, 0x7F, 0xC2, 0xFC, 0x09, 0xF2, 0x67, 0xCC, 0xBF, 0x31, 0xFF, 0x06, 
  0xFB, 0x6F, 0xEC, 0x9F, 0xB1, 0x7F, 0xC2, 0xFE, 0x09, 0xF2, 0x6F, 0xCC, 
  0xBF, 0xB1, 0xFF, 0x06, 0xFB, 0x6F, 0xEC, 0x9F, 0xB1, 0x7F, 0xC2, 0xFE, 
  0x09, 0xF2, 0x6F, 0xCC, 0xBF, 0xB1, 0xFF, 0x06, 0xFB, 0x6F, 0xEC, 0x9F, 
  0xB1, 0x7F, 0xC2, 0xFC, 0x09, 0xF2, 0x67, 0xCC, 0xBF, 0xB1, 0xFF, 0x06, 
  0x03, 0x60, 0x0C, 0xC0, 0x31, 0x00, 0xC2, 0x00, 0x08, 0x02, 0x60, 0x1C, 
  0x80, 0x31, 0x00, 0x06, 0x03, 0x60, 0x0C, 0xC0, 0x31, 0x00, 0xC2, 0x00, 
  0x08, 0x02, 0x60, 0x1C, 0x80, 0x31, 0x00, 0x06, 0xFB, 0x67, 0xEC, 0x9F, 
  0xB1, 0x7F, 0xC2, 0xFC, 0x09, 0xF2, 0x67, 0xCC, 0xBF, 0x31, 0xFF, 0x06, 
  0xFB, 0x6F, 0xEC, 0x9F, 0xB1, 0x7F, 0xC2, 0xFE, 0x09, 0xF2, 0x6F, 0xCC, 
  0xBF, 0xB1, 0xFF, 0x06, 0xFB, 0x6F, 0xEC, 0x9F, 0xB1, 0x7F, 0xC2, 0xFE, 
  0x09, 0xF2, 0x6F, 0xCC, 0xBF, 0xB1, 0xFF, 0x06, 0xFB, 0x6F, 0xEC, 0x9F, 
  0xB1, 0x7F, 0xC2, 0xFE, 0x09, 0xF2, 0x6F, 0xCC, 0xBF, 0xB1, 0xFF, 0x06, 
  0xF3, 0x67, 0xEC, 0x9F, 0xB1, 0x7F, 0xC2, 0xFC, 0x09, 0xF2, 0x67, 0xCC, 
  0xBF, 0x31, 0x7F, 0x06, 0x03, 0x60, 0x0C, 0xC0, 0x31, 0x00, 0xC2, 0x00, 
  0x08, 0x02, 0x60, 0x1C, 0x80, 0x31, 0x00, 0x06, 0x03, 0x60, 0x0C, 0xC0, 
  0x31, 0x00, 0xC2, 0x00, 0x08, 0x02, 0x60, 0x1C, 0x80, 0x31, 0x00, 0x06, 
  0xFB, 0x6F, 0xEC, 0x9F, 0xB1, 0x7F, 0xC2, 0xFC, 0x09, 0xF2, 0x6F, 0xCC, 
  0xBF, 0xB1, 0xFF, 0x06, 0xFB, 0x6F, 0xEC, 0x9F, 0xB1, 0x7F, 0xC2, 0xFE, 
  0x09, 0xF2, 0x6F, 0xCC, 0xBF, 0xB1, 0xFF, 0x06, 0xFB, 0x6F, 0xEC, 0x9F, 
  0xB1, 0x7F, 0xC2, 0xFE, 0x09, 0xF2, 0x6F, 0xCC, 0xBF, 0xB1, 0xFF, 0x06, 
  0xFB, 0x67, 0xEC, 0x9F, 0xB1, 0x7F, 0xC2, 0xFC, 0x09, 0xF2, 0x67, 0xCC, 
  0xBF, 0x31, 0xFF, 0x06, 0x03, 0x60, 0x0C, 0xC0, 0x31, 0x00, 0xC2, 0x00, 
  0x08, 0x02, 0x60, 0x1C, 0x80, 0x31, 0x00, 0x06, 0xFF, 0x7F, 0xFC, 0xFF, 
  0xF1, 0xFF, 0x83, 0xFF, 0x0F, 0xFE, 0x7F, 0xFC, 0xFF, 0xF1, 0xFF, 0x07, 
  0xFE, 0x3F, 0xF8, 0xFF, 0xE1, 0xFF, 0x83, 0xFF, 0x0F, 0xFE, 0x3F, 0xFC, 
  0xFF, 0xE0, 0xFF, 0x03
  };
  u8g2.drawXBM(0, 0, u8g2.getDisplayWidth(), u8g2.getDisplayHeight(), hello_screen);

  const char alerta[] = "Alerta Alerta Alerta Al";
  u8g2.setFont(u8g2_font_5x7_tf);
  u8g2.drawStr(6, 12, alerta);
  // u8g2.drawBitmap(0, 0, u8g2.getDisplayWidth(), u8g2.getDisplayHeight(), hello_screen);
  u8g2.sendBuffer();
}

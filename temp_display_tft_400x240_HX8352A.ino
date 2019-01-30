#include <Adafruit_GFX.h>    // Core graphics library
#include <Wire.h> //I2C knihova
#include <LM75.h> //knihovna teplotniho cidla na desce displeje
#include <MCUFRIEND_kbv.h>

MCUFRIEND_kbv tft; //deklarace jmena displeje
LM75 sensor;  // deklarace jmena cidla teploty

// barvy pro lidi
#define	BLACK   0x0000
#define	BLUE    0x001F
#define	RED     0xF800
#define	GREEN   0x07E0
#define CYAN    0x07FF
#define MAGENTA 0xF81F
#define YELLOW  0xFFE0
#define WHITE   0xFFFF

void setup() {
  Serial.begin(9600); //nahozeni serialu meze displejem a arduinem
  Wire.begin(); //nahozeni I2C
 /* Serial.println(F("TFT LCD test"));
  Serial.print("TFT size is "); 
  Serial.print(tft.width()); 
  Serial.print("x"); 
  Serial.println(tft.height()); */
  tft.reset();
  tft.begin(0x5252);//nahozeni HX8352A driveru displeje
  tft.fillScreen(BLACK); //backgroung displeje
}

void loop() {
    tft.setRotation(1);
    tft.fillRect(60,80, 170, 50, BLUE);
    tft.setCursor(65, 85);
    tft.setTextColor(WHITE);  tft.setTextSize(1);
    tft.println("Teplota desky:");
    tft.setCursor(100, 100);
    tft.setTextColor(WHITE);  tft.setTextSize(3);
    tft.print(sensor.temp());
    tft.println(" C");
    tft.setCursor(10, 30);
    tft.setTextColor(YELLOW);  tft.setTextSize(4);
    tft.println("73! DE OK1VBR");
    
    tft.setCursor(60, 200);
    tft.setTextColor(WHITE);  tft.setTextSize(1);
    tft.println(tft.width());

    tft.setCursor(80, 200);
    tft.setTextColor(WHITE);  tft.setTextSize(1);
    tft.println("x");

    tft.setCursor(90, 200);
    tft.setTextColor(WHITE);  tft.setTextSize(1);
    tft.println(tft.height());
    delay(5000);
}


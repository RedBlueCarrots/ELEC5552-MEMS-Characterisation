#include "font_lookup.h"

#include <SPI.h>
#include <XPT2046_Touchscreen.h>

// --- Pin Definitions ---
// TFT Control Pins
#define TFT_CS   PB0
#define TFT_DC   PB1
#define TFT_RST  PB2
#define TFT_BL   PB3

// Define the Touch Chip Select pin
#define XPT2046_IRQ 3   // Optional interrupt pin (TP_IRQ)
#define XPT2046_CS  A0  // Change to your actual TP_CS pin

// Default Hardware SPI1 Pins for STM32F4 (Blackpill):
// SPI1 SCK  -> PA5
// SPI1 MISO -> PA6 (Not connected to LCD)
// SPI1 MOSI -> PA7

bool hidden[30*10] = {false};


XPT2046_Touchscreen ts(XPT2046_CS, XPT2046_IRQ);

// Helper functions for sending Commands & Data via Hardware SPI
void lcdCommand(uint8_t cmd) {
  digitalWrite(TFT_DC, LOW);
  digitalWrite(TFT_CS, LOW);
  SPI.transfer(cmd);
  digitalWrite(TFT_CS, HIGH);
}

void lcdData(uint8_t data) {
  digitalWrite(TFT_DC, HIGH);
  digitalWrite(TFT_CS, LOW);
  SPI.transfer(data);
  digitalWrite(TFT_CS, HIGH);
}

void setup() {
  delay(1000);
  Serial.begin(115200);
  Serial.println("HI");
  // Initialize Control Pins
  pinMode(TFT_CS, OUTPUT);
  pinMode(TFT_DC, OUTPUT);
  pinMode(TFT_RST, OUTPUT);
  pinMode(TFT_BL, OUTPUT);

  digitalWrite(TFT_CS, HIGH);
  digitalWrite(TFT_BL, HIGH); // Turn backlight on

  // Start Hardware SPI
  SPI.begin();
  ts.begin();
  ts.setRotation(3); // Match your display rotation
  // Set SPI settings (18MHz clock speed, MSB First, SPI Mode 0)
  SPI.beginTransaction(SPISettings(27000000, MSBFIRST, SPI_MODE0));

  // 1. Hardware Reset
  digitalWrite(TFT_RST, HIGH); delay(20);
  digitalWrite(TFT_RST, LOW);  delay(50);
  digitalWrite(TFT_RST, HIGH); delay(150);

  // 2. Soft Reset + Wakeup
  lcdCommand(0x01); // SWRESET
  delay(150);

  lcdCommand(0x11); // SLPOUT
  delay(150);

  // 3. Set Color Format to 18-bit RGB666
  lcdCommand(0x3A); 
  lcdData(0x66); 

  // 4. Turn Inversion ON (Required for Waveshare LCD-3.5 panel)
  lcdCommand(0x21); // INVON

  // 5. Display ON
  lcdCommand(0x29); // DISPON
  delay(50);

  // 6. Set Window to Full Screen (320x480)
  lcdCommand(0x2A); // CASET
  lcdData(0x00); lcdData(0x00);
  lcdData(0x01); lcdData(0x3F); // 319

  lcdCommand(0x2B); // PASET
  lcdData(0x00); lcdData(0x00);
  lcdData(0x01); lcdData(0xDF); // 479

  lcdCommand(0x2C); // RAMWR

  // 7. Blast RED (RGB666: R=0xFF, G=0x00, B=0x00)
  digitalWrite(TFT_DC, HIGH);
  digitalWrite(TFT_CS, LOW);

  for (uint32_t i = 0; i < (320UL * 480UL); i++) {
    if (i % 20 < 10) {
      SPI.transfer(0xFF); // R
    } else {
      SPI.transfer(0x00); // R
    }
    SPI.transfer(0xFF); // G
    SPI.transfer(0x00); // B
  }

  digitalWrite(TFT_CS, HIGH);
  SPI.endTransaction();

  //draw_frame();
}

void send_rgb(byte R, byte G, byte B) {
  SPI.transfer(B);
  SPI.transfer(G);
  SPI.transfer(R);
}

void draw_frame() {
  lcdCommand(0x2C); // RAMWR
  SPI.beginTransaction(SPISettings(27000000, MSBFIRST, SPI_MODE0));
  digitalWrite(TFT_DC, HIGH);
  digitalWrite(TFT_CS, LOW);
    for (uint32_t i = 0; i < (320UL * 480UL); i++) {
      int x = i/320;
      int y = i % 320;
      int spot_x = x/16;
      int spot_y = y/32;
      int xx = x % 16;
      int yy = y % 32;
      char line[31] = "Current Temperature: 30.96!!!!";
      byte out = font[line[spot_x]][yy*16+xx];
      if (hidden[spot_y*30+spot_x]) {
        out = font[32][yy*16+xx];
      }
      send_rgb(out, out, out);

    }
  digitalWrite(TFT_CS, HIGH);
  SPI.endTransaction();
}

void loop() {
  if (ts.tirqTouched() && ts.touched()) {
   TS_Point p = ts.getPoint();
    int x = 4+(p.x-280)/15 * 2;
    int y = 320 - (p.y-175)/23*2;
    Serial.print(", X = ");
    Serial.print(x);
    Serial.print(", Y = ");
    Serial.println(y);

    int spot_x = x/16;
    int spot_y = y/32;
    hidden[spot_y*30+spot_x] = true;
    Serial.println(hidden[spot_y*30+spot_x]);//, spot_y, hidden[spot_y*30+spot_x]);
    draw_frame();
    Serial.println("TOUCHED");
    delay(100);
    
  }
  delay(10);
}
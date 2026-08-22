#include <EEPROM.h>
#include <SPI.h>
#include <TFT_eSPI.h>
TFT_eSPI tft = TFT_eSPI();

#define CALIBRATION_MAGIC 0x5A 
#define EEPROM_ADDR 0

void setup(void) {
  uint16_t calibrationData[5];
  uint8_t calDataOK = 0;

  Serial.begin(115200);
  Serial.println("starting");

  tft.init();

  tft.setRotation(3);
  tft.fillScreen((0xFFFF));

  tft.setCursor(20, 0, 2);
  tft.setTextColor(TFT_BLACK, TFT_WHITE);  tft.setTextSize(1);
  tft.println("calibration run");

  uint16_t calData[5];
  uint8_t magicNumber;

  if (magicNumber == CALIBRATION_MAGIC) {
    // 2. Data exists! Load it and apply it.
    Serial.println("Loading touch calibration from EEPROM...");
    
    // Read the array starting right after the 1-byte magic number
    EEPROM.get(EEPROM_ADDR + 1, calData); 
    
    // Apply the calibration to the TFT
    tft.setTouch(calData); 
    
  } else {
    // 3. No valid data found. Run calibration.
    Serial.println("No calibration found. Starting calibration...");
    
    tft.fillScreen(TFT_BLACK);
    tft.setCursor(20, 0);
    tft.setTextFont(2);
    tft.setTextSize(1);
    tft.setTextColor(TFT_WHITE, TFT_BLACK);
    tft.println("Touch corners as indicated");

    // This stops the program and waits for the user to touch the corners
    tft.calibrateTouch(calData, TFT_MAGENTA, TFT_BLACK, 15);
    
    tft.fillScreen(TFT_BLACK);
    tft.println("Calibration complete!");

    // 4. Save the new calibration data to EEPROM
    EEPROM.put(EEPROM_ADDR, (uint8_t)CALIBRATION_MAGIC);
    EEPROM.put(EEPROM_ADDR + 1, calData);
    
    Serial.println("Calibration saved to flash memory.");
  }
  
  tft.fillScreen((0xFFFF));

}

void loop() {
  uint16_t x, y;
  static uint16_t color;

  if (tft.getTouch(&x, &y)) {

    tft.setCursor(5, 5, 2);
    tft.printf("x: %i     ", x);
    tft.setCursor(5, 20, 2);
    tft.printf("y: %i    ", y);

    tft.drawPixel(x, y, color);
    color += 155;
  }
}




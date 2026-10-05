#include "font_lookup.h"

#include <SPI.h>
#include <Wire.h>
#include <XPT2046_Touchscreen.h>

// --- Pin Definitions ---
// TFT Control Pins
#define TFT_CS   PB0
#define TFT_DC   PB1
#define TFT_RST  PB2
#define TFT_BL   PB3
// Define the Touch Chip Select pin
#define XPT2046_IRQ 3   // Optional interrupt pin (TP_IRQ)
#define XPT2046_CS  PB6  // Change to your actual TP_CS pin

// Default Hardware SPI1 Pins for STM32F4 (Blackpill):
// SPI1 SCK  -> PA5
// SPI1 MISO -> PA6 (Not connected to LCD)
// SPI1 MOSI -> PA7


//MENU STATES:
#define HOME 0
#define WFRM_SETTINGS 1
#define WFRM_SHAPE 2
#define WFRM_FQ 3
#define WFRM_AMP 4
#define WFRM_OFF 5
#define WFRM_MOD 6
#define SET_TEMP 7
#define GRAPH_WFRM 8
#define GRAPH_TEMP 9
#define WFRM_MOD_FQ 10
#define WFRM_MOD_DP 11

const int HOME_LINKS[7] = {-1, 1, 7, 8, 9, -2, 0};
const int WFRM_SETTINGS_LINKS[7] = {-1, 2, 3, 4, 5, 6, 0};
const int WFRM_SHAPE_LINKS[7] = {-1, -3, -3, -3, -3, 1, 1};
const int WFRM_FQ_LINKS[7] = {-1, -2, -1, -1, -1, 1, 1};
const int WFRM_AMP_LINKS[7] = {-1, -2, -1, -1, -1, 1, 1};
const int WFRM_OFF_LINKS[7] = {-1, -2, -1, -1, -1, 1, 1};
const int WFRM_MOD_LINKS[7] = {-1, -2, -1, 10, 11, 1, 1};
const int SET_TEMP_LINKS[7] = {-1, -2, -1, -1, -1, 0, 0};
const int GRAPH_WFRM_LINKS[7] = {-1, -2, -2, -2, -2, -2, 0};
const int GRAPH_TEMP_LINKS[7] = {-1, -2, -2, -2, -2, -2, 0};
const int WFRM_MOD_FQ_LINKS[7] = {-1, -2, -1, -1, -1, 6, 6};
const int WFRM_MOD_DP_LINKS[7] = {-1, -2, -1, -1, -1, 6, 6};
const int* PAGE_LINKS[12] = {HOME_LINKS, WFRM_SETTINGS_LINKS,WFRM_SHAPE_LINKS,WFRM_FQ_LINKS,WFRM_AMP_LINKS,WFRM_OFF_LINKS,WFRM_MOD_LINKS,SET_TEMP_LINKS,GRAPH_WFRM_LINKS,GRAPH_TEMP_LINKS,WFRM_MOD_FQ_LINKS,WFRM_MOD_DP_LINKS};

#define SINE 0
#define SQUARE 1
#define TRIANGLE 2
#define SAWTOOTH 3

uint32_t shape = SINE;
int amplitude = 125; // Divide by 10
int freq = 134000; //Divide by 10
int offset = 25; //Divide by 10
int temp = 441; //Divide by 10
int mod_freq = 250; //Divide by 10
int mod_depth = 500; //Divide by 10

int *VAR_LOOKUP[12] = {0, 0, 0, &freq, &amplitude, &offset, 0, &temp, 0, 0, &mod_freq, &mod_depth};
int VAR_MAXES[12] = {0, 0, 0, 200000000, 500, 250, 0, 600, 0, 0, 10000, 1000};
int VAR_MINS[12] = {0, 0, 0, 1, 1, 0, 0, 50, 0, 0, 1, 1};
int HIGHLIGHT_EXP[12] = {0, 0, 0, 8, 2, 2, 0, 2, 0, 0, 4, 3};

XPT2046_Touchscreen ts(XPT2046_CS);//, XPT2046_IRQ);

char* current_menu[10];
int menu = HOME;

int highlight = 0;
const bool IS_HIGHLIGHT[12] = {false, false, false, true, true, true, false, true, false, false, true, true};

// 1. Define custom SPI instances based on your .ioc pins
SPIClass ScreenSPI(PB5, PB4, PB3);  // MOSI, MISO, SCLK (PA15 is CS)
SPIClass DDSSPI(PB15, PB14, PB13); // MOSI, MISO, SCLK (PB12 is CS)
SPIClass TempSPI(PC12, PC11, PC10);

// 2. Define custom I2C instances
TwoWire FPGAI2C(PB9, PB8); // SDA, SCL
TwoWire TempWire(PF0, PF1); // SDA, SCL

#define DDSFSYNC PB12

// Output Pin Array from your .ioc config
const uint8_t outputPins[] = {
  PA0, PA1, PA2, PA3, PB0, PB1, PB2, PB6,
  PC0, PC1, PC2, PC3, PC9, PC10, PC11, PC12
};

void setup_pins() {
  // Configure GPIO Outputs
  for (uint8_t i = 0; i < sizeof(outputPins); i++) {
    pinMode(outputPins[i], OUTPUT);
  }

  // SPI CS Pins
  pinMode(PA15, OUTPUT);
  digitalWrite(PA15, HIGH);
  pinMode(PB12, OUTPUT);
  digitalWrite(PB12, HIGH);

  // Initialize Peripherals
  ScreenSPI.begin();
  DDSSPI.begin();
  FPGAI2C.begin();
  TempWire.begin();

  // Analog Setup
  analogReadResolution(12);  // STM32 ADC supports up to 12-bit
  analogWriteResolution(12); // PA4 DAC Output
  
  // // EXTI Interrupt Setup (PA10)
  // pinMode(PA10, INPUT_PULLUP);
  // attachInterrupt(digitalPinToInterrupt(PA10), myInterruptHandler, RISING);
}

// Helper functions for sending Commands & Data via Hardware SPI
void lcdCommand(uint8_t cmd) {
  digitalWrite(TFT_DC, LOW);
  digitalWrite(TFT_CS, LOW);
  ScreenSPI.transfer(cmd);
  digitalWrite(TFT_CS, HIGH);
}

void lcdData(uint8_t data) {
  digitalWrite(TFT_DC, HIGH);
  digitalWrite(TFT_CS, LOW);
  ScreenSPI.transfer(data);
  digitalWrite(TFT_CS, HIGH);
}

void clear_menu() {
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 31; j++) {
      current_menu[i][j] = ' ';
    }
    current_menu[i][31] = '\0';
  }
}

void init_menu() {
  for (int i = 0; i < 10; i++) {
    current_menu[i]  = new char[32];
  }
  clear_menu();
}


void setup() {
  init_menu();
  load_menu();
  setup_pins();
  delay(1000);
  // Initialize Control Pins
  pinMode(TFT_CS, OUTPUT);
  pinMode(TFT_DC, OUTPUT);
  pinMode(TFT_RST, OUTPUT);
  pinMode(TFT_BL, OUTPUT);

  digitalWrite(TFT_CS, HIGH);
  digitalWrite(TFT_BL, HIGH); // Turn backlight on

  ts.begin();
  ts.setRotation(3); // Match your display rotation
  // Set SPI settings (18MHz clock speed, MSB First, SPI Mode 0)
  ScreenSPI.beginTransaction(SPISettings(60000000, MSBFIRST, SPI_MODE0));

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

  draw_frame();
}

void send_rgb(byte R, byte G, byte B) {
  ScreenSPI.transfer(B);
  ScreenSPI.transfer(G);
  ScreenSPI.transfer(R);
}

void change_menu(int slot, int x) {
  if (slot >= 6) {
    return;
  }
  int changeto = PAGE_LINKS[menu][slot];
  if (changeto == -2) {
    return;
  } else if (changeto == -3) {
    shape = slot - 1;
    return;
  }
  else if (changeto == -1) {
    bool is_left = x < 12;
    switch (slot) {
      case 0:
      if (is_left) {
        menu = PAGE_LINKS[menu][6];
      } else {
        menu = HOME;
      }
        break;
      case 3:
        if (!is_left) {
          increment_highlight();
        } else {
          decrement_highlight();
        }
        break;
      case 4:
        if (is_left) {
          increment_val();
        } else {
          decrement_val();
        }
        break;
    }
    return;
  }
  highlight = 0;
  menu = changeto;
}

void increment_val() {
  int exp = round(pow(10, (HIGHLIGHT_EXP[menu]-highlight)));
  *(VAR_LOOKUP[menu]) += exp;
  if (*(VAR_LOOKUP[menu]) > VAR_MAXES[menu]) {
    *(VAR_LOOKUP[menu]) = VAR_MAXES[menu];
  }
}

void decrement_val() {
  int exp = round(pow(10, (HIGHLIGHT_EXP[menu]-highlight)));
  *(VAR_LOOKUP[menu]) -= exp;
  if (*(VAR_LOOKUP[menu]) < VAR_MINS[menu]) {
    *(VAR_LOOKUP[menu]) = VAR_MINS[menu];
  }
}

void increment_highlight() {
  highlight += 1;
  if (highlight> HIGHLIGHT_EXP[menu]) {
    highlight = HIGHLIGHT_EXP[menu] ;
  }
}

void decrement_highlight() {
  highlight -= 1;
  if (highlight<0) {
    highlight = 0 ;
  }
}

void load_menu() {
  clear_menu();
  strncpy(current_menu[0] , "BACK            HOME", 31);
  switch (menu) {
    case HOME:
    strncpy(current_menu[1], "Change Waveform", 31);
      strncpy(current_menu[1] , "Change Waveform", 31);
      strncpy(current_menu[2] , "Change Temperature", 31);
      strncpy(current_menu[3] , "View Signal", 31);
      strncpy(current_menu[4] , "View Temperature", 31);
      strncpy(current_menu[5] , "", 31);
      break;
    case WFRM_SETTINGS:
      strncpy(current_menu[1] , "Change Shape", 31);
      sprintf(current_menu[2], "%d.%dHz", freq/10, freq%10);
      sprintf(current_menu[3], "%d.%dV p-p", amplitude/10, amplitude%10);
      sprintf(current_menu[4], "%d.%dV DC Offset", offset/10, offset%10);
      strncpy(current_menu[5] , "Modulation", 31);
      break;
    case WFRM_SHAPE:
      strncpy(current_menu[1] , "Sine", 31);
      strncpy(current_menu[2] , "Square", 31);
      strncpy(current_menu[3] , "Triangle", 31);
      strncpy(current_menu[4] , "Sawtooth", 31);
      strncpy(current_menu[5] , "Back", 31);
      break;
    case WFRM_FQ:
      strncpy(current_menu[1] , "Frequency", 31);
      sprintf(current_menu[2] , "%08d.%01dHz", freq/10, freq%10);
      strncpy(current_menu[3] , "    <-        ->    ", 31);
      strncpy(current_menu[4] , "    +          -    ", 31);
      strncpy(current_menu[5] , "Back", 31);
      break;
    case WFRM_AMP:
      strncpy(current_menu[1] , "Amplitude", 31);
      sprintf(current_menu[2] , "%02d.%01dV", amplitude/10, amplitude%10);
      strncpy(current_menu[3] , "    <-        ->    ", 31);
      strncpy(current_menu[4] , "    +          -    ", 31);
      strncpy(current_menu[5] , "Back", 31);
      break;
    case WFRM_OFF:
      strncpy(current_menu[1] , "Change DC Offset", 31);
      sprintf(current_menu[2] , "%02d.%01dV", amplitude/10, amplitude%10);
      strncpy(current_menu[3] , "    <-        ->    ", 31);
      strncpy(current_menu[4] , "    +          -    ", 31);
      strncpy(current_menu[5] , "Back", 31);
      break;
    case WFRM_MOD:
      strncpy(current_menu[1] , "Amplitude Moduation", 31);
      strncpy(current_menu[2] , "Active", 31);
      sprintf(current_menu[3], "%d.%dHz", freq/10, freq%10);
      sprintf(current_menu[4], "%d.%d% Depth", freq/10, freq%10);
      strncpy(current_menu[5] , "Back", 31);
      break;
    case SET_TEMP:
      sprintf(current_menu[1], "Current: %d.%d~", temp/10, temp%10);
      sprintf(current_menu[2] , "%02d.%01d Target   ", temp/10, temp%10);
      strncpy(current_menu[3] , "    <-        ->    ", 31);
      strncpy(current_menu[4] , "    +          -    ", 31);
      strncpy(current_menu[5] , "Back", 31);
      break;
    case GRAPH_WFRM:
      strncpy(current_menu[1] , "", 31);
      strncpy(current_menu[2] , "", 31);
      strncpy(current_menu[3] , "", 31);
      strncpy(current_menu[4] , "", 31);
      strncpy(current_menu[5] , "", 31);
      break;
    case GRAPH_TEMP:
      strncpy(current_menu[1] , "", 31);
      strncpy(current_menu[2] , "", 31);
      strncpy(current_menu[3] , "", 31);
      strncpy(current_menu[4] , "", 31);
      strncpy(current_menu[5] , "", 31);
      break;
    case WFRM_MOD_FQ:
      strncpy(current_menu[1] , "AM Frequency", 31);
      sprintf(current_menu[2] , "%04d.%01dHz", mod_freq/10, mod_freq%10);
      strncpy(current_menu[3] , "    <-        ->    ", 31);
      strncpy(current_menu[4] , "    +          -    ", 31);
      strncpy(current_menu[5] , "Back", 31);
      break;
    case WFRM_MOD_DP:
      strncpy(current_menu[1] , "AM Depth", 31);
      sprintf(current_menu[2] , "%03d.%01d%%", mod_depth/10, mod_depth%10);
      strncpy(current_menu[3] , "    <-        ->    ", 31);
      strncpy(current_menu[4] , "    +          -    ", 31);
      strncpy(current_menu[5] , "Back", 31);
      break;
    default:
      menu = HOME;
      load_menu();
      break;
  }

}

void draw_frame() {
  lcdCommand(0x2C); // RAMWR
  ScreenSPI.beginTransaction(SPISettings(60000000, MSBFIRST, SPI_MODE0));
  digitalWrite(TFT_DC, HIGH);
  digitalWrite(TFT_CS, LOW);
    for (uint32_t i = 0; i < (320UL * 480UL); i++) {
      int x = i/320;
      int y = i % 320;
      int spot_x = x/24;
      int spot_y = y/48;
      int xx = x % 24;
      int yy = y % 48;
      char *line = current_menu[spot_y];
      byte out = font[line[spot_x]][yy*24+xx];
      if (IS_HIGHLIGHT[menu]) {
        if (highlight ==HIGHLIGHT_EXP[menu]) {
          spot_x -= 1;
        }
        if (spot_y == 2 && out == 0xFF && highlight == spot_x) {
          send_rgb(0x88, 0xFF, 0x88);
        } else {
          send_rgb(out, out, out);
        }
      } else if (menu == WFRM_SHAPE && spot_y == shape+1 && out == 0xFF) {
        send_rgb(0x88, 0xFF, 0x88);
      } else {
      send_rgb(out, out, out);
      }

    }
  digitalWrite(TFT_CS, HIGH);
  ScreenSPI.endTransaction();
}

void loop() {
  if (ts.touched()) {
   TS_Point p = ts.getPoint();
    int x = 4+(p.x-280)/15 * 2;
    int y = 320 - (p.y-175)/23*2;

    int spot_x = x/24;
    int spot_y = y/48;
    change_menu(spot_y, spot_x);
    load_menu();
    draw_frame();
    delay(10);
    
  }
  delay(10);
}
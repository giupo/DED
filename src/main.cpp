#include <Arduino.h>
#include <SPI.h>
#include <Wire.h>

// Here is defined the font used.
#include "font/DEDFont.h"

// library for OLED
#include <U8g2lib.h>

#define DCSBIOS_IRQ_SERIAL
#include <DcsBios.h>
#include "constants.hpp"

/*

Pin Connections:

OLED PIN  | Arduino UNO            | C++ var
1         | VSS/Ground (GND)       |
2         | VDD/VCC +3.3v to 5.0v  | 
3         | NC                     |
4         | SCLK (pin 13)          | CLOCK
5         | SDIN/MOSI (pin 11)     | DATA
6         | NC                     |
7         | GND                    |
8         | GND                    |
9         | GND                    |
10        | GND                    |
11        | GND                    |
12        | GND                    |
13        | GND                    |
14        | PIN_DC (pin 9)         | DC
15        | PIN_RESET (pin 8)      | RESET
16        | PIN_CS  (pin 10)            | CS


*Keep in mind* that pin 7/13 are noted as GND but they can be NC (not connected)
*/

constexpr int CLOCK = 13;
constexpr int DATA = 11;
constexpr int CS  = 10;
constexpr int DC = 9;
constexpr int RESET = 8;

U8G2_SSD1322_NHD_256X64_2_4W_SW_SPI oled(U8G2_R0, CLOCK, DATA, CS, DC, RESET);

// DED Class

class DED {
  public:
    DED() {}
    ~DED() {}

    /** @brief initializes the OLED (declared globally) with the new value*/
    void setup() {
      oled.begin();  
      oled.setFont(DEDfont16px);
    }

    /** @brief updates the nth line of the DED with the new value*/
    void update(const int row, const char* value) {
      strncpy(lines[row], value, LINE_LENGTH);
    }

    /* @brief this funcion take care to dump the lines matrix onto the OLED */
    void loop() {
      oled.firstPage();
      do {
        for(uint8_t line_number = 0; line_number < DED_LINES; line_number++) {
          oled.drawStr(START_POINT, DED_LINE_HEIGHT * (line_number + 1), lines[line_number]); 
        }
      } while ( oled.nextPage() );
    }

  private:
    char lines[DED_LINES][LINE_LENGTH] = {
      "        DED v1.0            ",
      "                            ",
      "  WAINTING FOR DATA ...     ",
      "                            ",
      "                            "
    };
};


// our beloved DED
DED ded;

// Callbacks coming straight from DCS-BIOS Control Reference page
// the only contribution here is to copy the new value onto the
// correct line

void onDedLine1Change(char* newValue) {
  //strncpy(lines[0], newValue, LINE_LENGTH);
  ded.update(0, newValue);
}
DcsBios::StringBuffer<LINE_LENGTH> dedLine1Buffer(0x4500, onDedLine1Change);

void onDedLine2Change(char* newValue) {
  //strncpy(lines[1], newValue, LINE_LENGTH);
  ded.update(1, newValue);
}
DcsBios::StringBuffer<LINE_LENGTH> dedLine2Buffer(0x451e, onDedLine2Change);

void onDedLine3Change(char* newValue) {
  //strncpy(lines[2], newValue, LINE_LENGTH);
  ded.update(2, newValue);
}
DcsBios::StringBuffer<LINE_LENGTH> dedLine3Buffer(0x453c, onDedLine3Change);

void onDedLine4Change(char* newValue) {
  //strncpy(lines[3], newValue, LINE_LENGTH);
  ded.update(3, newValue);
}
DcsBios::StringBuffer<LINE_LENGTH> dedLine4Buffer(0x455a, onDedLine4Change);

void onDedLine5Change(char* newValue) {
  //strncpy(lines[4], newValue, LINE_LENGTH);
  ded.update(4, newValue);
}
DcsBios::StringBuffer<LINE_LENGTH> dedLine5Buffer(0x4578, onDedLine5Change);

// Android specific entry points

void setup() {
  ded.setup();
  DcsBios::setup();
}

void loop() {
  DcsBios::loop();
  ded.loop();
}

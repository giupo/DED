#include "ded.hpp"

#include "font/DEDFont.h"
#include <U8g2lib.h>

#include "platform.hpp"

// TODO: see if I can plug this attribute as member attribute of DED

U8G2_SSD1322_NHD_256X64_2_4W_SW_SPI oled(U8G2_R0, 
  Platform::Oled::clock(), 
  Platform::Oled::data(),
  Platform::Oled::cs(),
  Platform::Oled::dc(), 
  Platform::Oled::reset());


DED::DED() {}
DED::~DED() {}

void DED::setup() {
  oled.begin();  
  oled.setFont(DEDfont16px);
}

void DED::update(const int row, const char* value) {
  strncpy(lines[row], value, LINE_LENGTH);
}

void DED::loop() {
  oled.firstPage();
  do {
    for(uint8_t line_number = 0; line_number < DED_LINES; line_number++) {
      oled.drawStr(START_POINT, DED_LINE_HEIGHT * (line_number + 1), lines[line_number]); 
    }
  } while ( oled.nextPage() );
}
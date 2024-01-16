#include <Arduino.h>
#include <SPI.h>
#include <Wire.h>

// library for OLED
#include <U8g2lib.h>

#include "sim/dcs.hpp"
#include "constants.hpp"

// our beloved DED definition
#include "ded.hpp"

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

// our beloved DED
DED ded;

// Android specific entry points

void setup() {
  ded.setup();
  DCS::setup();
}

void loop() {
  DCS::loop();
  ded.loop();
}

#include <Arduino.h>
#include <SPI.h>
#include <Wire.h>


// Platform speicfic
#include "platform.hpp"

//DCS specific 
#include "sim/dcs.hpp"

// our beloved DED definition
#include "ded.hpp"

DED ded;

// Android specific entry points

void setup() {
  Platform::setup();
  ded.setup();
  DCS::setup();
}

void loop() {
  Platform::loop();
  DCS::loop();
  ded.loop();
}

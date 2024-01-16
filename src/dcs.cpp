#include "sim/dcs.hpp"

#define DCSBIOS_IRQ_SERIAL
#include <DcsBios.h>

#include "constants.hpp"
#include "ded.hpp"

extern DED ded;
// Callbacks coming straight from DCS-BIOS Control Reference page
// the only contribution here is to copy the new value onto the
// correct line

void onDedLine1Change(char* newValue) {
  ded.update(0, newValue);
}
DcsBios::StringBuffer<LINE_LENGTH> dedLine1Buffer(0x4500, onDedLine1Change);

void onDedLine2Change(char* newValue) {
  ded.update(1, newValue);
}
DcsBios::StringBuffer<LINE_LENGTH> dedLine2Buffer(0x451e, onDedLine2Change);

void onDedLine3Change(char* newValue) {
  ded.update(2, newValue);
}
DcsBios::StringBuffer<LINE_LENGTH> dedLine3Buffer(0x453c, onDedLine3Change);

void onDedLine4Change(char* newValue) {
  ded.update(3, newValue);
}
DcsBios::StringBuffer<LINE_LENGTH> dedLine4Buffer(0x455a, onDedLine4Change);

void onDedLine5Change(char* newValue) {
  ded.update(4, newValue);
}
DcsBios::StringBuffer<LINE_LENGTH> dedLine5Buffer(0x4578, onDedLine5Change);


namespace DCS {
  void setup() {
    DcsBios::setup();
  }

  void loop() {
    DcsBios::loop();
  }
}
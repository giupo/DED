#include "platform.hpp"

#ifdef TARGET_UNO

namespace Platform {
  
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
16        | PIN_CS  (pin 10)       | CS


*Keep in mind* that pin 7/13 are noted as GND but they can be NC (not connected)

*/

  
  
  namespace Oled {

    constexpr int CLOCK = 13;
    constexpr int DATA = 11;
    constexpr int CS  = 10;
    constexpr int DC = 9;
    constexpr int RESET = 8;
    
    const int clock() { return CLOCK; }
    const int data() { return DATA; }
    const int cs() { return CS; }
    const int dc() { return DC; }
    const int reset() { return RESET; }
  }

  void setup() {}
  void loop() {}
}

#endif
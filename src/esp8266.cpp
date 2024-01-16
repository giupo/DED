#include "platform.hpp"

#ifdef TARGET_ESP

#include <ESP8266WiFi.h>
namespace Platform {

/* 

OLED PIN  | Esp8266                    | C++ var
----------+----------------------------+--------
1         | VSS/Ground (GND)           |
2         | VDD/VCC +3.3v to 5.0v      | 
3         | NC                         |
4         | SCLK      (pin GPIO14/D5)  | CLOCK
5         | SDIN/MOSI (pin GPIO13/D7)  | DATA
6         | NC                         |
7         | GND                        |
8         | GND                        |
9         | GND                        |
10        | GND                        |
11        | GND                        |
12        | GND                        |
13        | GND                        |
14        | PIN_DC    (pin GPIO 5/D1)  | DC
15        | PIN_RESET (pin GPIO 4/D2)  | RESET
16        | PIN_CS    (pin GPIO15/D8)  | CS

D0 (SCK / CLK)  | GPIO 14 (D5)
D1 (MOSI)       | GPIO 13 (D7)
RES             | GPIO 4  (D2)
DC              | GPIO 5  (D1)
CS 	            | GPIO 15 (D8)

*/

  namespace Oled {

    // OLED wiring properties
    constexpr int CLOCK = D5; // SCLK
    constexpr int DATA  = D7; // DATA/MOSI
    constexpr int CS    = D8; 
    constexpr int DC    = D1;
    constexpr int RESET = D2;
    
    const int clock() { return CLOCK; }
    const int data() { return DATA; }
    const int cs() { return CS; }
    const int dc() { return DC; }
    const int reset() { return RESET; }
  }

  constexpr int led = D0;

  void setup() {
    // turn of Wi-Fi
    //WiFi.mode(WIFI_OFF);
  }

  void loop() {}
}

#endif //TARGET_ESP
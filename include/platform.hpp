#ifndef PLATFORM_HPP
#define PLATFORM_HPP

namespace Platform {

  namespace Oled {
    const int clock();
    const int data();
    const int cs();
    const int dc();
    const int reset();
  };

  void setup();
  void loop();
};

#endif //PLATFORM_HPP
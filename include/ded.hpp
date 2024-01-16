#include "constants.hpp"

class DED {
  public:
    DED();
    ~DED();

    /** @brief initializes the OLED (declared globally) with the new value*/
    void setup();

    /** @brief updates the nth line of the DED with the new value*/
    void update(const int row, const char* value);

    /* @brief this funcion take care to dump the lines matrix onto the OLED */
    void loop();

  private:
    char lines[DED_LINES][LINE_LENGTH] = {
      "        DED v1.0            ",
      "                            ",
      "  WAINTING FOR DATA ...     ",
      "                            ",
      "                            "
    };
};

#ifndef SELECTOR_H
#define SELECTOR_H

#include <Arduino.h>

class Selector {
  public:
    int selectedIndex = 0;

    void begin(int clk, int dt, int sw) {
      pinCLK = clk;
      pinDT = dt;
      pinSW = sw;

      pinMode(pinCLK, INPUT_PULLUP);
      pinMode(pinDT, INPUT_PULLUP);
      pinMode(pinSW, INPUT_PULLUP);

      lastCLK = digitalRead(pinCLK);
    }

    bool update(int itemCount) {

      if (itemCount <= 0) {
        selectedIndex = 0;
        return false;
      }

      int clkState = digitalRead(pinCLK);
      bool changed = false;

      if (clkState != lastCLK) {
        if (digitalRead(pinDT) != clkState)
          selectedIndex++;
        else
          selectedIndex--;

        if (selectedIndex < 0) selectedIndex = itemCount - 1;
        if (selectedIndex >= itemCount) selectedIndex = 0;

        changed = true;
      }

      lastCLK = clkState;
      return changed;
    }

    bool clicked() {
      if (digitalRead(pinSW) == LOW) {
        delay(150);
        return true;
      }
      return false;
    }

  private:
    int pinCLK, pinDT, pinSW;
    int lastCLK;
};

#endif

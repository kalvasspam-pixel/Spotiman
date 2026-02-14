#include <TFT_eSPI.h>
#include "selector.h"
#include "menu_system.h"

TFT_eSPI tft = TFT_eSPI();
Selector selector;
MenuSystem menuSystem;

#include "main_menu.h"
#include "settings_menu.h"

void setup() {
  Serial.begin(115200);
  tft.init();
  tft.setRotation(0);

  selector.begin(18,19,21);

  menuSystem.begin(&mainMenu);
}

void loop() {

  bool changed = selector.update(menuSystem.getCurrentMenu()->itemCount);
  menuSystem.selectedIndex = selector.selectedIndex;

  bool clicked = selector.clicked();

  menuSystem.update(changed, clicked);
}

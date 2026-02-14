#include <TFT_eSPI.h>
#include "Logic_Selector.h"
#include "Logic_Menu.h"

TFT_eSPI tft = TFT_eSPI();
Selector selector;
MenuSystem menuSystem;

#include "GUI/Menu_Main.h"
#include "GUI/Menu_Settings.h"

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

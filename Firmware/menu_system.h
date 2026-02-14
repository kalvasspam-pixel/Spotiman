#ifndef MENU_SYSTEM_H
#define MENU_SYSTEM_H

#include <Arduino.h>

struct Menu {
  int itemCount;
  void (**highlight)();
  void (**clear)();
  void (**action)();
  void (*onEnter)();   // vykreslí celé menu při vstupu
};

class MenuSystem {
  public:

    void begin(Menu* startMenu) {
      stackIndex = 0;
      menuStack[0] = startMenu;
      currentMenu = startMenu;
      selectedIndex = 0;
      currentMenu->onEnter();
      currentMenu->highlight[selectedIndex]();
    }

    void update(bool changed, bool clicked) {

      if(changed) {
        currentMenu->clear[oldIndex]();
        currentMenu->highlight[selectedIndex]();
        oldIndex = selectedIndex;
      }

      if(clicked) {
        currentMenu->action[selectedIndex]();
      }
    }

    void push(Menu* menu) {
      stackIndex++;
      menuStack[stackIndex] = menu;
      currentMenu = menu;
      selectedIndex = 0;
      oldIndex = 0;
      currentMenu->onEnter();
      currentMenu->highlight[0]();
    }

    void pop() {
      if(stackIndex == 0) return;
      stackIndex--;
      currentMenu = menuStack[stackIndex];
      selectedIndex = 0;
      oldIndex = 0;
      currentMenu->onEnter();
      currentMenu->highlight[0]();
    }

    Menu* getCurrentMenu() { return currentMenu; }

    int selectedIndex = 0;

  private:
    Menu* menuStack[5];
    int stackIndex = 0;
    Menu* currentMenu;
    int oldIndex = 0;
};

#endif

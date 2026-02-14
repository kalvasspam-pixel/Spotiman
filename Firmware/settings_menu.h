#ifndef SETTINGS_MENU_H
#define SETTINGS_MENU_H

#include "menu_system.h"
#include "highlights.h"

extern MenuSystem menuSystem;
extern TFT_eSPI tft;

void drawSettingsMenu() {
    tft.fillScreen(TFT_BLACK);
    tft.drawString("Settings", 60, 5);
    tft.drawString("Back", 50, 50);
}

void settingsAction0(){
    menuSystem.pop();
}

void (*settingsHighlights[])() = { settingsHighlight0 };
void (*settingsClears[])()     = { settingsClear0 };
void (*settingsActions[])()    = { settingsAction0 };

Menu settingsMenu = {
    1,
    settingsHighlights,
    settingsClears,
    settingsActions,
    drawSettingsMenu
};

#endif

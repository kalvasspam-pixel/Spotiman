#pragma once

#include "menu_system.h"
extern TFT_eSPI tft;

void drawSettingsItem0() {
    tft.drawString("Back", 50, 50);
}

void highlightSettingsItem0() {
    tft.fillRect(45, 45, 80, 30, tft.color565(255,255,0));
    drawSettingsItem0();
}

void clearSettingsItem0() {
    drawSettingsItem0();
}

void actionSettingsItem0() {
    menuSystem.pop();
}

MenuItem settingsMenuItems[] = {
    {"Back", highlightSettingsItem0, clearSettingsItem0, actionSettingsItem0, nullptr}
};

Menu settingsMenu = {
    sizeof(settingsMenuItems) / sizeof(MenuItem),
    (void (**)()) &settingsMenuItems[0].highlight,
    (void (**)()) &settingsMenuItems[0].clear,
    (void (**)()) &settingsMenuItems[0].action,
    nullptr
};

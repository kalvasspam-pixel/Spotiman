#pragma once

#include "menu_system.h"
#include "bitmaps.h"  // bitmaps for icons
extern TFT_eSPI tft;

// base GUI
void drawMainItem0() {  
    tft.drawBitmap(213, 3, image_battery_100_bits, 24, 16, 0xFFFF);
    tft.drawBitmap(189, 3, image_network_4_bars_bits, 15, 16, 0xFFFF);
    tft.drawBitmap(170, 3, image_music_headphones_bits, 15, 16, 0xFFFF);
    tft.drawBitmap(146, 3, image_wifi_full_bits, 19, 16, 0xFFFF);
    tft.drawBitmap(105, 222, image_music_play_bits, 30, 32, 0xFFFF);
    tft.drawBitmap(57, 222, image_music_next_bits, 152, 28, 0xFFFF);
    tft.drawBitmap(41, 222, image_music_previous_bits, 32, 32, 0xFFFF);
    tft.setTextColor(0xFFFF);
    tft.setTextSize(1);
    tft.setFreeFont(&FreeMonoBold9pt7b);
    tft.drawString("Pisnicka", 42, 174);
    tft.drawBitmap(37, 200, image_music_record_bits, 8, 8, 0xFFFF);
    tft.drawLine(40, 203, 208, 203, 0xFFFF);
    tft.drawRect(52, 32, 137, 137, 0xFFFF);
    tft.drawBitmap(192, 266, image_menu_bits, 16, 16, 0xFFFF);
    tft.drawBitmap(38, 266, image_menu_options_bits, 14, 16, 0xFFFF);
    tft.setFreeFont(&FreeMonoBoldOblique12pt7b);
    tft.drawString("PLAYER", 8, 1);
    tft.drawBitmap(163, 266, image_cards_hearts_bits, 15, 16, 0xFFFF);
    tft.drawBitmap(73, 266, image_add_svgrepo_com_1_bits, 16, 16, 0xFFFF);
    tft.drawBitmap(104, 266, image_shuffle_2_svgrepo_com_bits, 16, 16, 0xFFFF);
    tft.drawBitmap(134, 266, image_loop_svgrepo_com_bits, 16, 16, 0xFFFF);

}

void drawMainItem1() {
    tft.drawBitmap(135, 222, image_music_next_bits, 30, 32, tft.color565(0,0,0));
}

void highlightMainItem0() {
    tft.drawBitmap(105, 222, image_music_play_bits, 30, 32, tft.color565(255,255,0));
}

void clearMainItem0() {
    drawMainItem0(); // clears highlight by drawing again
}

void highlightMainItem1() {
    tft.drawBitmap(135, 222, image_music_next_bits, 30, 32, tft.color565(255,255,0));
}

void clearMainItem1() {
    drawMainItem1();
}

// actions after pressing rotary encoder
void actionMainItem0() {
    Serial.println("Play pressed");
}

void actionMainItem1() {
    Serial.println("Next pressed");
}

// list of items in menu
MenuItem mainMenuItems[] = {
    {"Play", highlightMainItem0, clearMainItem0, actionMainItem0, nullptr},
    {"Next", highlightMainItem1, clearMainItem1, actionMainItem1, nullptr}
};

Menu mainMenu = {
    sizeof(mainMenuItems) / sizeof(MenuItem),
    (void (**)()) &mainMenuItems[0].highlight,  // pointers to array
    (void (**)()) &mainMenuItems[0].clear,
    (void (**)()) &mainMenuItems[0].action,
    nullptr
};

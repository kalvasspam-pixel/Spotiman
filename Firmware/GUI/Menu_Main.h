#pragma once

#include "../Assets/Global_Variables.h"   // where to find bitmaps
#include "../Logic_Menu.h"         // imports the logic
extern TFT_eSPI tft;               // TFT object from "Firmware.ino"


// 1. DRAWING HIGHLIGHT OF ELEMENTS
// every item has its own highlight function
// when the selector is on set item it draws a highlight
inline void highlightItem0() {
    // code for highlighting item0
    tft.drawBitmap(38, 266, image_menu_options_bits, 14, 16, tft.color565(255, 255, 0));

}

inline void highlightItem1() {
    // code for highlighting item1
    tft.drawBitmap(192, 266, image_menu_bits, 16, 16, tft.color565(255, 255, 0));
}

// here you can add other item highlights



// 2. CLEARING HIGHLIGHT FUNCTIONS
// every item has its own highlight clearing function (mostly just drawing base item again)
// it's executed when the selector moves away from the highlighted item
inline void clearItem0() {
    // code for clearing higlight of item0
    tft.drawBitmap(38, 266, image_menu_options_bits, 14, 16, tft.color565(255, 255, 255));
}

inline void clearItem1() {
    // code for clearing higlight of item1
    tft.drawBitmap(192, 266, image_menu_bits, 16, 16, tft.color565(255, 255, 255));
}

// here you can add other clearings of highlights



// 3. ACTIONS AFTER CLICKING THE ROTARY ENCODER
// every item has it's own action (eg. going to a sub-menu)
// it defines what happens after selection of an item
inline void actionItem0() {
    // action after selecting item0
    tft.fillScreen(tft.color565(0, 0, 0));
    Serial.println("první menu ukázáno");
}

inline void actionItem1() {
    // action after selecting item0
    tft.fillScreen(tft.color565(255, 0, 0));
    Serial.println("druhé menu ukázáno");
}

// here you can add other actions after confirmation of an item



// 4. MENU-SPECIFIC ARRAY OF FUNCTIONS
// theese fuctions are for connecting higlights/clears/actions functions to the menu
inline void (*highlights[])() = { highlightItem0, highlightItem1 };
inline void (*clears[])()     = { clearItem0, clearItem1 };
inline void (*actions[])()    = { actionItem0, actionItem1 };



// 6. MENU OBJECT
// Menu object is what MenuSystem is using for controling the items
// itemCount → the number of items in a menu
// highlight, clear, action → array of functions
// onEnter → what is gonna draw after entering the menu (base GUI)
inline Menu mainMenu = {
    3,            // the number of items
    highlights,   // highlight of item
    clears,       // clearing the highlight
    actions,      // action after selection
    [](){         // onEnter → drawing the base UI
        // code that will create the non-selectable elements (base GUI)
        tft.fillScreen(0x0);
        // battery_100
        tft.drawBitmap(213, 3, image_battery_100_bits, 24, 16, 0xFFFF);
        // network_4_bars
        tft.drawBitmap(189, 3, image_network_4_bars_bits, 15, 16, 0xFFFF);
        // music_headphones
        tft.drawBitmap(170, 3, image_music_headphones_bits, 15, 16, 0xFFFF);
        // wifi_full
        tft.drawBitmap(146, 3, image_wifi_full_bits, 19, 16, 0xFFFF);
        // music_play
        tft.drawBitmap(109, 221, image_music_play_bits, 80, 30, 0xFFFF);
        // music_next
        tft.drawBitmap(57, 222, image_music_next_bits, 152, 28, 0xFFFF);
        // music_previous
        tft.drawBitmap(41, 222, image_music_previous_bits, 32, 32, 0xFFFF);
        // Layer 8
        tft.setTextColor(0xFFFF);
        tft.setTextSize(1);
        tft.setFreeFont(&FreeMonoBold9pt7b);
        tft.drawString("Pisnicka", 42, 174);
        // music_record
        tft.drawBitmap(37, 200, image_music_record_bits, 8, 8, 0xFFFF);
        // Layer 9
        tft.drawLine(40, 203, 208, 203, 0xFFFF);
        // Layer 11
        tft.drawRect(52, 32, 137, 137, 0xFFFF);
        // menu
        tft.drawBitmap(192, 266, image_menu_bits, 16, 16, 0xFFFF);
        // menu_options
        tft.drawBitmap(38, 266, image_menu_options_bits, 14, 16, 0xFFFF);
        // Layer 14
        tft.setFreeFont(&FreeMonoBoldOblique12pt7b);
        tft.drawString("PLAYER", 8, 1);
        // cards_hearts
        tft.drawBitmap(163, 266, image_cards_hearts_bits, 15, 16, 0xFFFF);
        // add_svgrepo_com_1
        tft.drawBitmap(73, 266, image_add_svgrepo_com_1_bits, 16, 16, 0xFFFF);
        // shuffle_2_svgrepo_com
        tft.drawBitmap(104, 266, image_shuffle_2_svgrepo_com_bits, 16, 16, 0xFFFF);
        // loop_svgrepo_com
        tft.drawBitmap(134, 266, image_loop_svgrepo_com_bits, 16, 16, 0xFFFF);


    }
};

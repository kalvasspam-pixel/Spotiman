#pragma once

#include "../Global_Variables.h"   // where to find bitmaps
#include "../Logic_Menu.h"         // imports the logic
extern TFT_eSPI tft;               // TFT object from "Firmware.ino"


// 1. DRAWING HIGHLIGHT OF ELEMENTS
// every item has its own highlight function
// when the selector is on set item it draws a highlight
inline void highlightItem0() {
    // code for highlighting item0
    // eg. tft.fillRect(x, y, w, h, tft.color565(255,255,0));

}

inline void highlightItem1() {
    // code for highlighting item1
}

// here you can add other item highlights



// 2. CLEARING HIGHLIGHT FUNCTIONS
// every item has its own highlight clearing function (mostly just drawing base item again)
// it's executed when the selector moves away from the highlighted item
inline void clearItem0() {
    // code for clearing higlight of item0
    // eg. tft.fillRect(x, y, w, h, tft.color565(255,255,255));
}

inline void clearItem1() {
    // code for clearing higlight of item1
}

// here you can add other clearings of highlights



// 3. ACTIONS AFTER CLICKING THE ROTARY ENCODER
// every item has it's own action (eg. going to a sub-menu)
// it defines what happens after selection of an item
inline void actionItem0() {
    // action after selecting item0
    // eg. menuSystem.push(&settingsMenu);
}

inline void actionItem1() {
    // action after selecting item0
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
        // eg. tft.fillScreen(tft.color565(50,50,50));

    }
};

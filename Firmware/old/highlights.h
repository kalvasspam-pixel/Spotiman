#ifndef HIGHLIGHTS_H
#define HIGHLIGHTS_H

#include <TFT_eSPI.h>
#include "bitmaps.h"
extern TFT_eSPI tft;

uint16_t highlightColor = tft.color565(247, 210, 41);
uint16_t clearColor = tft.color565(255, 255, 255);

// MAIN MENU highlighty
void mainHighlight0(){ tft.drawBitmap(105, 222, image_music_play_bits, 30, 32, highlightColor); }
void mainClear0(){ tft.fillRect(10,20,200,30,clearColor); }

void mainHighlight1(){ tft.fillRect(10,60,200,30,TFT_YELLOW); }
void mainClear1(){ tft.fillRect(10,60,200,30,tft.color565(0,0,0)); }

// SETTINGS highlighty
void settingsHighlight0(){ tft.drawRect(40,40,150,40,TFT_YELLOW); }
void settingsClear0(){ tft.drawRect(40,40,150,40,tft.color565(0,0,0)); }

#endif

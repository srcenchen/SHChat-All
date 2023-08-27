//
// Created by sanenchen on 2023/6/13.
//

#ifndef OLED_OLED_H
#define OLED_OLED_H
#include "U8g2lib.h"
void showOLED(const char * t_str, int x, int y);
void oledBegin();
void clearBuffer();
void sendBuffer();
#endif //OLED_OLED_H

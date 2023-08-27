//
// Created by sanenchen on 2023/6/13.
//

#include "oled.h"

U8G2_SSD1306_128X64_NONAME_F_SW_I2C u8g2(U8G2_R0, SCL, SDA, /* reset=*/ U8X8_PIN_NONE);


void oledBegin() {
    u8g2.begin();
    u8g2.setDisplayRotation(U8G2_R2);
}

void clearBuffer() {
    u8g2.clearBuffer();
}

void sendBuffer() {
    u8g2.sendBuffer();
}

void showOLED(const char *t_str, int x, int y) {
    u8g2.setFont(u8g2_font_wqy12_t_gb2312);

    u8g2.firstPage();
    do {
        int lineHeight = 13; // 每行文本的高度

        String text = t_str;

        while (text.length() > 0) {
            int maxChars = u8g2.getUTF8Width(text.c_str()); // 当前行可以容纳的最大字符数

            // 循环减少字符数，直到宽度小于等于最大字符数
            while (u8g2.getUTF8Width(text.substring(0, maxChars).c_str()) > u8g2.getWidth()) {
                maxChars--;
            }

            // 绘制当前行的文本
            u8g2.drawUTF8(x, y, text.substring(0, maxChars).c_str());

            // 移动到下一行的位置
            y += lineHeight;

            // 剩余文本
            text = text.substring(maxChars);
        }
    } while (u8g2.nextPage());

}

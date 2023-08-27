//
// Created by sanenchen on 23-8-7.
//

#include "wifi_connect.h"
#include "WiFi.h"
#include "oled/oled.h"

const char *SSID = "gzjkqxq";
const char *password = "gzfx1234";

void WiFiConnect() {
    WiFi.begin(SSID,password); // 连接网络
    pinMode(2, OUTPUT);
    oledBegin();
    clearBuffer();

    showOLED(("网络连接中... 目标网络：" + String(SSID)).c_str(), 0, 12);
    sendBuffer();
    while (WiFiClass::status() != WL_CONNECTED) { // 等待网络连接成功
        digitalWrite(2, HIGH);
        delay(200);
        digitalWrite(2, LOW);
        delay(200);
    }
    Serial.print("Wifi Connected");
    Serial.println("IP address: ");
    Serial.println(WiFi.localIP()); //打印模块IP
    digitalWrite(2, HIGH);

}

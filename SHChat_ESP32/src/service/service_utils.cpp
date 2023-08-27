//
// Created by sanenchen on 23-8-7.
//

#include "service_utils.h"
#include "HTTPClient.h"
#include "ArduinoJson.h"
#include "oled/oled.h"

HTTPClient http;

// 解析Json
void parse_json(String json) {
    DynamicJsonDocument doc(6144);

    DeserializationError error = deserializeJson(doc, json);

    if (error) {
        Serial.print("deserializeJson() failed: ");
        Serial.println(error.c_str());
        return;
    }
    size_t chatListSize = doc["data"]["chatList"].size();
    JsonObject data_chatList_0 = doc["data"]["chatList"][chatListSize - 1];
    int data_chatList_0_Id = data_chatList_0["Id"]; // 1
    const char *data_chatList_0_Content = data_chatList_0["Content"]; // "test"
    const char *data_chatList_0_NickName = data_chatList_0["NickName"]; // "Ehsan"
    const char *data_chatList_0_Date = data_chatList_0["Date"]; // "2023-08-07T14:31:22Z"


    Serial.println(data_chatList_0_Content);
    String content =  String(data_chatList_0_Content) +String(data_chatList_0_Date);
    // 显示到 OLED 屏幕
    clearBuffer();
    showOLED(content.c_str(), 0, 12);
    sendBuffer();
}

// 获取聊天数据
void get_chat_data() {
    oledBegin();
    clearBuffer();
    showOLED("网络连接成功 加载中...", 0, 12);
    sendBuffer();
    http.begin("https://shchat.luckysan.top/api/message/get-least-message-iot");
    int http_code = http.GET();
    if (http_code == 200) {
        parse_json(http.getString());
        http.end();
    } else {
        clearBuffer();
        showOLED("请求失败，即将重启", 0, 12);
        delay(500);
        sendBuffer();
        // 出错重试
        esp_restart();
    }
}

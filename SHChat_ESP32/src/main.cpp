#include <Arduino.h>
#include "wifi/wifi_connect.h"
#include "service/service_utils.h"

void setup() {
    Serial.begin(115200);
    WiFiConnect();
    get_chat_data();
}

void loop() {

}
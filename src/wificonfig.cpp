#include <WiFi.h>
#include <Arduino.h>
#include "wificonfig.h"
#include "config.h"

const char  * SSID  = "KABORE_2.4G";
const char * PASSWORD = "KABORE4114@";

void WiFiStationConnected(WiFiEvent_t event, WiFiEventInfo_t info)
{
    Serial.println("Connected to AP!");
    
}

void wifiConnect()
{
    WiFi.mode(WIFI_STA);
    WiFi.onEvent(WiFiStationConnected, ARDUINO_EVENT_WIFI_STA_CONNECTED);
    WiFi.begin(SSID, PASSWORD);
    while(WiFi.status() != WL_CONNECTED)
    {
        Serial.print(".");
        delay(500);
    }
    Serial.println();
    Serial.print("IP address : ");
    Serial.println(WiFi.localIP());
}
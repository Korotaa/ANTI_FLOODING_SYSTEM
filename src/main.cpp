/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2025-01-17
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include <Arduino.h>
#include "ledBlink.h"
#include "config.h"
#include "wificonfig.h"
#include<WiFi.h>

void setup() {
  Serial.begin(BAUDERATE);
  pinMode(LED_GPIO, OUTPUT);
  wifiConnect();
}

void loop() {

  blinkLed(LED_GPIO);
}

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
#include  <WiFi.h>
#include "ledBlink.h"
#include "config.h"
#include "wificonfig.h"
#include "ultrasonic.h"
#include "configOLED.h"
#include "alarm.h"
#include "floatLevelSensor.h"
#include "pompeControl.h"
#include "configMQTT.h"


void setup() {
  Serial.begin(BAUDERATE);
  pinMode(LED_GPIO, OUTPUT);
  //WiFi connexion
  wifiConnect();
  //MQTT
  setupMQTT();
  initUltrasonic();
  setupOLED();
  pompeInit();
  initAlarm();
  display.setCursor(0, 0);
  display.clearDisplay();
  display.setTextSize(2.75);
  display.println("korota:");
  //display.setTextSize(3);
  //display.println(timeString);
  display.display();
}

void loop() {
  connectToServerMQTT();
  if(waterLevel()) 
  {
    startPompe();
    blinkLed(LED_GPIO);
    onAlarm();
    delay(500);
    //delay(5000);
    }
  else {
    stopPompe();
    offAlarm();
    delay(2000);
  }
  //Serial.print("Distance[cm] = ");
  //Serial.println(readLevel1());
  /*onAlarm();
  delay(1000);
  offAlarm();
  delay(1000);
  */

}

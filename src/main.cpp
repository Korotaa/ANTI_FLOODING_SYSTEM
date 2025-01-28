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
#include <ArduinoJson.h>
#include <ArduinoJson.hpp>
#include "ledBlink.h"
#include "config.h"
#include "wificonfig.h"
#include "ultrasonic.h"
#include "configOLED.h"
#include "alarm.h"
#include "floatLevelSensor.h"
#include "pompeControl.h"
#include "configMQTT.h"

int ETAT_POMPE;
int ETAT_ALARM;

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
  
  StaticJsonDocument<32> doc;
  char data_to_sent[127];
  int criticLevel = waterLevel();
  float waterlevel = readLevel1();

  if(criticLevel) 
  {
    startPompe();
    ETAT_POMPE = 1;
    blinkLed(LED_GPIO);
    onAlarm();
    ETAT_ALARM = 1;
    delay(500);
    }
  else {
    stopPompe();
    ETAT_POMPE = 0;
    offAlarm();
    ETAT_ALARM = 0;
    delay(2000);

  }
  doc["seuil_critique"] = criticLevel;
  doc["Niveau_eau"] = waterlevel;
  doc["Etat_pompe"] = ETAT_POMPE;
  doc["Etat_alarme"] = ETAT_ALARM;
  serializeJson(doc, data_to_sent);
  
  Serial.println("Read");
  Serial.println(data_to_sent);
  sendDataToServerMQTT(data_to_sent);
  delay(5000);
  /*
  //Serial.print("Distance[cm] = ");
  //Serial.println(readLevel1());
  onAlarm();
  delay(1000);
  offAlarm();
  delay(1000);
  */

}

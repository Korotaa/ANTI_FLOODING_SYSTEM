/**
 * @file alarm.cpp
 * @author your name (you@domain.com)
 * @brief Définit deux fonctions qui allume et éteint l'alarme
 * @version 0.1
 * @date 2025-01-19
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include <Arduino.h>
#include "config.h"
#include "alarm.h"

void initAlarm(){
    pinMode(ALARM_GPIO, OUTPUT);
}
/**
 * @brief Démarre l'alarme
 * @param void
 * @return void
 */
void onAlarm(){
    //pinMode(ALARM_GPIO, OUTPUT);
    //digitalWrite(ALARM_GPIO, LOW);
    // Joue une tonalité simple de 4000 Hz (La4) pendant 1 seconde
    tone(ALARM_GPIO, 2000, 1000);
    digitalWrite(ALARM_GPIO, HIGH);
    delay(1000);
    digitalWrite(ALARM_GPIO, LOW);
    delay(1000); // Pause de 1 seconde
}
/**
 * @brief Arrêter l'alarme
 * @param void
 * @return void
 */
void offAlarm(){
    //pinMode(ALARM_GPIO, OUTPUT);
    //digitalWrite(ALARM_GPIO, HIGH);
    noTone(ALARM_GPIO);
    delay(1000);
}
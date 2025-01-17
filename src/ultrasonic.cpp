/**
 * @file ultrasonic.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2025-01-17
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include <Arduino.h>
#include "config.h"
#include "ultrasonic.h"

float duration; // en uS
float distance ; //Distance en cm
float distance2;
/**
 * @brief Initialistion du capteur ultrasonic
 * @param void
 * @return void
 */
void initUltrasonic(){
    pinMode(TRIG_GPIO, OUTPUT);
    pinMode(ECHO_GPIO, INPUT);
}
/**
 * @brief Determine le niveau d'eau avec la formule d = uS/58
 * @param void
 * @return float 
 */
float readLevel1(){
    //Send Trig signal
    digitalWrite(TRIG_GPIO, LOW);
    delayMicroseconds(2);
    digitalWrite(TRIG_GPIO, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIG_GPIO, LOW);

    duration = pulseIn(ECHO_GPIO, HIGH);
    distance = duration/58;
    //distance2 = duration * 0.17; // distance en cm plus precis
    return distance;
}
/**
 * @brief Determine le niveau d'eau avec la formule d = uS * 0.17 Cette méthode est 
 * plus précise que la première
 * @param void
 * @return float 
 */
float readLevel2(){
    //Send Trig signal
    digitalWrite(TRIG_GPIO, LOW);
    delayMicroseconds(2);
    digitalWrite(TRIG_GPIO, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIG_GPIO, LOW);
    duration = pulseIn(ECHO_GPIO, HIGH);
    //distance = duration/58;
    distance2 = duration * 0.17; // distance en cm plus precis
    return distance2;
}
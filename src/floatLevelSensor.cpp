/**
 * @file waterLevelSensor.cpp
 * @author your name (you@domain.com)
 * @brief Detecte le niveau d'eau critique avec un capteur de niveau d'eau vertical à flotteur
 * @version 0.1
 * @date 2025-01-17
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include <Arduino.h>
#include "floatLevelSensor.h"
#include "config.h"

/**
 * @brief Initialise le capteur de niveau
 * @param void
 * @return void
 */
void waterLevelSensorInit(){
    pinMode(FLOAT_SENSOR_GPIO, INPUT_PULLUP);
}
/**
 * @brief Detecte le niveau d'eau critique à ne pas dépasser
 * @param void
 * @return void
 */
int waterLevel(){
    int sensorState = digitalRead(FLOAT_SENSOR_GPIO);
    if (sensorState == LOW) return 0;
    else if(sensorState == HIGH) return 1;
}
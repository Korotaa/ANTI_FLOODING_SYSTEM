/**
 * @file pompeControl.cpp
 * @author your name (you@domain.com)
 * @brief Définis des fonctions permettant de contrôler la pompe
 * @version 0.1
 * @date 2025-01-17
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#include "Arduino.h"
#include "pompeControl.h"
#include "config.h"

/**
 * @brief Initialise le GPIO de la pompe 
 * @param void
 * @return void
 */
void pompeInit(){
    pinMode(POMPE_GPIO, OUTPUT);
    digitalWrite(POMPE_GPIO, LOW);
}
/**
 * @brief Cette fonction Demarre la pompe
 * @param void
 * @return void
 */
void startPompe(){
    digitalWrite(POMPE_GPIO, HIGH);
    Serial.println("Pompe démarrer");
}
/**
 * @brief Cette fonction arrête la pompe
 * @param void
 * @return void
 */
void stopPompe(){
    digitalWrite(POMPE_GPIO, LOW);
    Serial.println("Pompe arrêter");
}
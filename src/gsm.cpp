

/**
 * @file gsm.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2025-01-17
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#include <Arduino.h>
//#include <TinyGsmClient.h>
//#include <SoftwareSerial.h>
#include "config.h"
#include "gsm.h"
/*
void initGsmModule(){
    HardwareSerial SerialAT(1);
    TinyGsm modem(SerialAT);
    Serial.println("Initialisation...");
    // Initialisation du port série pour le SIM800L
    SerialAT.begin(9600, SERIAL_8N1, SIM800L_RX_GPIO, SIM800L_TX_GPIO);
    // Réinitialiser le modem
    modem.restart();
    // Vérifier la connexion
    if (!modem.testAT()) {
        Serial.println("Erreur : Impossible de communiquer avec le SIM800L");
        while (true);
    }
}

void sendSMS(String numero, String message) { 
    initGsmModule();
    Serial.println("Envoi du SMS...");
    if (modem.sendSMS(numero, message)) {
        Serial.println("SMS envoyé avec succès !");
    } else {
        Serial.println("Erreur lors de l'envoi du SMS.");
    }
}
*/
#include <Arduino.h>
#include <PubSubClient.h>
#include <WiFi.h>
#include "config.h"
#include "configMQTT.h"

WiFiClient espClient;
PubSubClient CLIENT(espClient);

void setupMQTT(){
    CLIENT.setServer(BROKERADDRESS, 1883);
    CLIENT.setCallback(callback);
}
/**
 * @brief Cette fonction est appélée à chaque fois que l'esp32 reçoit une commande du serveur mqtt
 * 
 * @param topic 
 * @param payload 
 * @param length 
 */
void callback(char* topic, byte* payload, unsigned int length){

}
/**
 * @brief Cette fonction reconnecte l'esp32 au serveur mqtt
 * @param void
 * @return void 
 * 
 */
void connectToServerMQTT(){
     // Loop until we're reconnected
  while (!CLIENT.connected()) {
        Serial.print("Attempting MQTT connection...");
        // Create a random client ID
        String clientId = "ESP32Client-";
        clientId += String(random(0xffff), HEX);
        // Attempt to connect
    if (CLIENT.connect(clientId.c_str())) {
        Serial.println();
        Serial.println("ESP32 dev is onnected to MQTT server");
        // Once connected, publish an announcement...
        CLIENT.publish(SEND_DATA_TOPIC, "Bonjour la team anti_innondation");
        // ... and resubscribe
        CLIENT.subscribe(DATA_RECEIVED_TOPIC);
    } else {
        Serial.print("failed, rc=");
        Serial.print(CLIENT.state());
        Serial.println(" try again in 5 seconds");
        // Wait 5 seconds before retrying
        delay(5000);
    }
  }
}

void sendDataToServerMQTT(char data[]){
    CLIENT.publish(SEND_DATA_TOPIC, data);
    Serial.println("Sent");
}
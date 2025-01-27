#ifndef CONFIGMQTT_H
#define CONFIGMQTT_H

void setupMQTT();
void connectToServerMQTT();
void callback(char* topic, byte* payload, unsigned int length);

#endif
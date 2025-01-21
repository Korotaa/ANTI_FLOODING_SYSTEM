#ifndef GSM_H 
#define GSM_H

#include <string.h>
#include <Arduino.h>

void initGsmModule();
void test();
void sendSMS(String number, String message);
void activateGPRS();

#endif // GSM_H
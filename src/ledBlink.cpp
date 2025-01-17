#include "ledBlink.h"
#include "Arduino.h"


void blinkLed(char pin){
    digitalWrite(pin, HIGH);
    delay(500);
    digitalWrite(pin, LOW);
    delay(500);
}
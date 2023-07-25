#include "CircusButton.h"
#include <Arduino.h>

#define _BTN_A 4
#define _BTN_B 5

CircusButton buttonA(_BTN_A, 0);
CircusButton buttonB(_BTN_B, 0);

void setup()
{
    Serial.begin(115200);
}

void loop()
{
    buttonA.loop();
    buttonB.loop();

    if (buttonA.readState() == BTN_STATE::F_EDGE) {
        Serial.println("A F_EDGE");
    } else if (buttonA.readState() == BTN_STATE::REPEAT) {
        Serial.println("A REPEAT");
    } else if (buttonA.readState() == BTN_STATE::PRESSED) {
        Serial.println("A PRESSED");
    } else if (buttonA.readState() == BTN_STATE::R_EDGE) {
        Serial.println("A R_EDGE");
    }

    if (buttonB.readState() == BTN_STATE::F_EDGE) {
        Serial.println("B F_EDGE");
    } else if (buttonB.readState() == BTN_STATE::REPEAT) {
        Serial.println("B REPEAT");
    } else if (buttonB.readState() == BTN_STATE::PRESSED) {
        Serial.println("B PRESSED");
    } else if (buttonB.readState() == BTN_STATE::R_EDGE) {
        Serial.println("B R_EDGE");
    }
}

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

    if (buttonA.readState() == _KEYCODE_F_EDGE) {
        Serial.println("A _KEYCODE_F_EDGE");
    } else if (buttonA.readState() == _KEYCODE_REPEAT) {
        Serial.println("A _KEYCODE_REPEAT");
    } else if (buttonA.readState() == _KEYCODE_PRESSED) {
        Serial.println("A _KEYCODE_PRESSED");
    } else if (buttonA.readState() == _KEYCODE_R_EDGE) {
        Serial.println("A _KEYCODE_R_EDGE");
    }

    if (buttonB.readState() == _KEYCODE_F_EDGE) {
        Serial.println("B _KEYCODE_F_EDGE");
    } else if (buttonB.readState() == _KEYCODE_REPEAT) {
        Serial.println("B _KEYCODE_REPEAT");
    } else if (buttonB.readState() == _KEYCODE_PRESSED) {
        Serial.println("B _KEYCODE_PRESSED");
    } else if (buttonB.readState() == _KEYCODE_R_EDGE) {
        Serial.println("B _KEYCODE_R_EDGE");
    }
}

#include "pedestrian.h"

PedestrianButton::PedestrianButton() {
    pressed = false;
    pressCount = 0;
}

// Pressing again while already waiting does nothing extra
void PedestrianButton::press() {
    if (pressed) {
        return;
    }
    pressed = true;
    pressCount++;
}

bool PedestrianButton::isPressed() {
    return pressed;
}

int PedestrianButton::getPressCount() {
    return pressCount;
}

void PedestrianButton::clear() {
    pressed = false;
}

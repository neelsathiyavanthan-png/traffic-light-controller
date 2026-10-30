#include <iostream>
#include "trafficlight.h"
using namespace std;

TrafficLight::TrafficLight() {
    state = RED;
}

// red -> green -> yellow -> red
void TrafficLight::nextState() {
    switch (state) {
        case RED:
            state = GREEN;
            break;
        case GREEN:
            state = YELLOW;
            break;
        case YELLOW:
            state = RED;
            break;
    }
}

LightState TrafficLight::getState() {
    return state;
}

string TrafficLight::stateName() {
    switch (state) {
        case RED:
            return "RED";
        case GREEN:
            return "GREEN";
        case YELLOW:
            return "YELLOW";
        default:
            return "RED";
    }
}

// return the right time for the current light
int TrafficLight::currentDuration(Timer& timer) {
    switch (state) {
        case RED:
            return timer.getRed();
        case GREEN:
            return timer.getGreen();
        case YELLOW:
            return timer.getYellow();
        default:
            return timer.getRed();
    }
}

void TrafficLight::reset() {
    state = RED;
}

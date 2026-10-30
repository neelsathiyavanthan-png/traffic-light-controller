#ifndef TASKS_H
#define TASKS_H

#include "timer.h"
#include "trafficlight.h"
#include "pedestrian.h"

int readNumber();

// Rohan
void runLightCycle(TrafficLight& light, Timer& timer);
void showCurrentState(TrafficLight& light);

// Lucas
void pressPedestrianButton(PedestrianButton& button);
void runCycleWithPedestrian(TrafficLight& light, PedestrianButton& button, Timer& timer);

// Neel
void changeTiming(Timer& timer);
void runEdgeCaseTests();
void resetSystem(Timer& timer, TrafficLight& light, PedestrianButton& button);

#endif

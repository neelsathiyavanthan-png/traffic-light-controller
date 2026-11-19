#include <iostream>
#include <string>
#include "tasks.h"
using namespace std;

// Rohan's tasks

void runLightCycle(TrafficLight& light, Timer& timer) {
    for (int i = 0; i < 3; i++) {
        cout << light.stateName() << " for " << light.currentDuration(timer) << " sec" << endl;
        light.nextState();
    }
    cout << "Back to RED" << endl;
}

void showCurrentState(TrafficLight& light) {
    cout << "Current light: " << light.stateName() << endl;
}

// Lucas's tasks

void pressPedestrianButton(PedestrianButton& button) {
    cout << "Press pedestrian button - not implemented yet" << endl;
}

void runCycleWithPedestrian(TrafficLight& light, PedestrianButton& button, Timer& timer) {
    cout << "Run cycle with pedestrian - not implemented yet" << endl;
}

// Neel's tasks

int readNumber() {
    int num;
    cin >> num;
    // if they type letters cin breaks, so clear it and ask again
    while (cin.fail()) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Enter a number: ";
        cin >> num;
    }
    return num;
}

void changeTiming(Timer& timer) {
    cout << endl << "Current times:" << endl;
    timer.print();

    cout << endl << "Which one do you want to change?" << endl;
    cout << "1. Green" << endl;
    cout << "2. Yellow" << endl;
    cout << "3. Red" << endl;
    cout << "4. Walk" << endl;
    cout << "Choice: ";
    int choice = readNumber();

    cout << "New time (seconds): ";
    int seconds = readNumber();

    bool ok = false;
    switch (choice) {
        case 1:
            ok = timer.setGreen(seconds);
            break;
        case 2:
            ok = timer.setYellow(seconds);
            break;
        case 3:
            ok = timer.setRed(seconds);
            break;
        case 4:
            ok = timer.setWalk(seconds);
            break;
        default:
            cout << "Not a valid option" << endl;
            return;
    }

    if (ok) {
        cout << "Changed. New times:" << endl;
        timer.print();
    } else {
        cout << "That time isn't allowed (has to be 1-60 sec, and walk can't be more than red)" << endl;
    }
}

void check(string name, bool result, int& passed, int& total) {
    total++;
    if (result) {
        passed++;
        cout << "PASS - " << name << endl;
    } else {
        cout << "FAIL - " << name << endl;
    }
}

void runEdgeCaseTests() {
    int passed = 0;
    int total = 0;
    Timer t;

    cout << endl << "Testing timer edge cases" << endl;

    check("default green is 5", t.getGreen() == 5, passed, total);
    check("green = 10 works", t.setGreen(10) == true, passed, total);
    check("yellow = 0 is rejected", t.setYellow(0) == false, passed, total);
    check("negative red is rejected", t.setRed(-3) == false, passed, total);
    check("61 sec is rejected", t.setGreen(61) == false, passed, total);
    check("60 sec works", t.setGreen(60) == true, passed, total);
    check("walk longer than red is rejected", t.setWalk(t.getRed() + 1) == false, passed, total);
    check("walk same as red works", t.setWalk(t.getRed()) == true, passed, total);

    // green should still be 60 since 0 isn't allowed
    t.setGreen(0);
    check("bad value doesn't change green", t.getGreen() == 60, passed, total);

    t.resetDefaults();
    check("reset sets green back to 5", t.getGreen() == 5, passed, total);

    cout << passed << " out of " << total << " passed" << endl;
}

void resetSystem(Timer& timer, TrafficLight& light, PedestrianButton& button) {
    timer.resetDefaults();
    light.reset();
    button.clear();
    cout << "Everything reset back to default" << endl;
}

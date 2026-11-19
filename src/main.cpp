#include <iostream>
#include "timer.h"
#include "trafficlight.h"
#include "pedestrian.h"
#include "tasks.h"
using namespace std;

void printMenu() {
    cout << endl << "--- Traffic Light Controller ---" << endl;
    cout << "1. Run light cycle" << endl;
    cout << "2. Show current light" << endl;
    cout << "3. Press pedestrian button" << endl;
    cout << "4. Run cycle with pedestrian" << endl;
    cout << "5. Change timing" << endl;
    cout << "6. Run edge case tests" << endl;
    cout << "7. Reset" << endl;
    cout << "0. Exit" << endl;
    cout << "Enter choice: ";
}

int main() {
    Timer timer;
    TrafficLight light;
    PedestrianButton button;

    int choice = -1;
    while (choice != 0) {
        printMenu();
        choice = readNumber();

        switch (choice) {
            case 1:
                runLightCycle(light, timer);
                break;
            case 2:
                showCurrentState(light);
                break;
            case 3:
                pressPedestrianButton(button);
                break;
            case 4:
                runCycleWithPedestrian(light, button, timer);
                break;
            case 5:
                changeTiming(timer);
                break;
            case 6:
                runEdgeCaseTests();
                break;
            case 7:
                resetSystem(timer, light, button);
                break;
            case 0:
                cout << "Bye" << endl;
                break;
            default:
                cout << "Invalid choice" << endl;
        }
    }

    return 0;
}

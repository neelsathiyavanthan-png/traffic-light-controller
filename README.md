# Embedded Traffic-Light Controller

EECE 2140 project. A C++ program that uses states and timers to control vehicle and pedestrian traffic signals.

## Team
- Lucas Alves Peralta
- Neel
- Rohan

## How to compile and run
From the main folder of the repo:
```
g++ src/*.cpp -o traffic
./traffic
```
Then pick an option from the menu. Enter `0` to exit.

## Folders
- `src/` - C++ source code
- `docs/` - project plan PDF and Excel plan

## Menu and tasks
Each menu option runs exactly one task function.

| ID | Task | Menu | Owner | Files / function | Status |
|---|---|---|---|---|---|
| T1 | Run light cycle | 1 | Rohan | `tasks.cpp: runLightCycle()`, `trafficlight.cpp` | Done |
| T2 | Show current light | 2 | Rohan | `tasks.cpp: showCurrentState()` | Done |
| T3 | Press pedestrian button | 3 | Lucas | `tasks.cpp: pressPedestrianButton()`, `pedestrian.cpp` | Stub |
| T4 | Run cycle with pedestrian | 4 | Lucas | `tasks.cpp: runCycleWithPedestrian()` | Stub |
| T5 | Change timing | 5 | Neel | `tasks.cpp: changeTiming()`, `timer.cpp` | Done |
| T6 | Run edge case tests | 6 | Neel | `tasks.cpp: runEdgeCaseTests()` | Done |
| T7 | Reset system | 7 | Neel | `tasks.cpp: resetSystem()` | Done |

## Classes
| Class | Private data | Public methods | File |
|---|---|---|---|
| `Timer` | greenTime, yellowTime, redTime, walkTime | setGreen, setYellow, setRed, setWalk, get..., resetDefaults, print | `timer.h/.cpp` |
| `TrafficLight` | state (RED/GREEN/YELLOW) | nextState, getState, stateName, currentDuration(timer), reset | `trafficlight.h/.cpp` |
| `PedestrianButton` | pressed, pressCount | press, isPressed, getPressCount, clear | `pedestrian.h/.cpp` |

## Class diagram
```
                 +-------------+
                 |  main.cpp   |  menu (switch)
                 +------+------+
                        | calls one function per option
                 +------v------+
                 |  tasks.cpp  |
                 +--+---+---+--+
                    |   |   |
       +------------+   |   +--------------+
       v                v                  v
+--------------+  +---------------+  +------------------+
| TrafficLight |  |     Timer     |  | PedestrianButton |
|--------------|  |---------------|  |------------------|
| state        |  | greenTime     |  | pressed          |
|              |  | yellowTime    |  | pressCount       |
|--------------|  | redTime       |  |------------------|
| nextState()  |  | walkTime      |  | press()          |
| stateName()  |  |---------------|  | isPressed()      |
| reset()      |  | setGreen() .. |  | clear()          |
+--------------+  | print()       |  +------------------+
                  +---------------+
TrafficLight asks Timer how long each light lasts (currentDuration).
```

## Rules for the team
- Only edit your own task functions and your own class files.
- Commit often with clear messages, e.g. `T1: implement nextState for RED to GREEN`.
- Make sure `g++ src/*.cpp -o traffic` still compiles before you push.

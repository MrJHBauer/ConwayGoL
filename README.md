# Conway's Game of Life

Conway's Game of Life is [cellular automaton](https://en.wikipedia.org/wiki/Cellular_automaton) developed by John H Conway in the 1970s. It is described as a zero player game as the outcome of the simulation is determined by the initial state and no further input needed.

## Getting Started

Make the required modifications before attempting to compile the code such as;

* include_directories
* link_directories
* location of .dll (if compiling for windows)
* Change the width, height and scale of world (main.cpp)

    auto* world = new World(1024, 1024, 16, sf::milliseconds(100));


Once compiled run the executable to be presented with a simulation window set to the paused state. You may change the state of cells by left or right clicking to make them either alive or dead. Once happy with arrangement of cells hit the space bar to start the simulation. The space bar can be used at any time to pause the simulation again.

### Prerequisites

* CMake greater than specified minimum version (v3.5)
* C++ compiler
* SFML (v2.4.1)

This has been tested on Debian 9 Stable and Windows 10 Visual Studio 2017 with CMake integration.

## Built With

* [SFML](https://www.sfml-dev.org/) - Multimedia library v2.4.1

## Acknowledgments

* John H Conway

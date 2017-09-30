#ifndef CONWAYGOL_WORLD_H
#define CONWAYGOL_WORLD_H

#include <SFML/Graphics.hpp>
#include "Cell.h"

/**
 * WorldState is used to pause and un-pause the simulation allowing for cells
 * to be placed without the simulation enforcing rules until the user is ready.
 */
enum WorldState
{
    PAUSED,
    RUNNING
};

/**
 * World class is responsible for containing the simulation environment for the
 * Game of Life. It shall store the current generation of the simulation,
 * enforce the rules on the next each tick and draw the results to the screen.
 */
class World
{
    sf::RenderWindow* Window;
    int Width;
    int Height;
    int Scale;
    WorldState State;
    sf::Time TickRate;
    Cell** CurrentGeneration;
    void Init();
    void Tick();
    void Draw();

public:
    World(int Width, int Height, int Scale, sf::Time TickRate);
    void Run();
};

#endif
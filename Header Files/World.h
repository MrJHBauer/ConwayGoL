#ifndef CONWAYGOL_WORLD_H
#define CONWAYGOL_WORLD_H

#include <SFML/Graphics.hpp>
#include "Cell.h"

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
    Cell** CurrentGeneration;
    void Init();
    void Draw();

public:
    World(int Width, int Height, int Scale);
    void Run();
};

#endif
#ifndef CONWAYGOL_WORLD_H
#define CONWAYGOL_WORLD_H

#include <SFML/Graphics.hpp>

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
    void Init();
    void Draw();

public:
    World(int Width, int Height);
    void Run();
};

#endif
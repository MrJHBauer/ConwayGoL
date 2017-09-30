#include "../Header Files/World.h"

int main()
{
    auto* world = new World(512, 512, 32, sf::milliseconds(500));

    world->Run();

    return 0;
}
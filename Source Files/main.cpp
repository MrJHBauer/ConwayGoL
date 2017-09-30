#include "../Header Files/World.h"

int main()
{
    auto* world = new World(512, 512, 16, sf::milliseconds(100));

    world->Run();

    return 0;
}
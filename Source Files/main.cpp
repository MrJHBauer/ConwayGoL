#include "../Header Files/World.h"

int main()
{
    auto* world = new World(1024, 1024, 16, sf::milliseconds(100));

    world->Run();

    return 0;
}
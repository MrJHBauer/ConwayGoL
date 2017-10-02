#include "../Header Files/World.h"

int main()
{
    auto* world = new World(720, 720, 48, sf::milliseconds(100));

    world->Run();

    return 0;
}
#include "../Header Files/World.h"

int main()
{
    auto* world = new World(500, 500);

    world->Run();

    return 0;
}
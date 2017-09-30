#include "../Header Files/World.h"

World::World(int Width, int Height)
{
    this->Width = Width;
    this->Height = Height;
}

void World::Init()
{
    Window = new sf::RenderWindow(sf::VideoMode(Width, Height), "Conway Game of Life");
    Window->setFramerateLimit(60);
}

void World::Draw()
{

}

void World::Run()
{
    Init();

    while(Window->isOpen())
    {
        sf::Event event;
        while(Window->pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
            {
                Window->close();
            }
            else if(event.type == sf::Event::KeyPressed)
            {
                if(event.key.code == sf::Keyboard::Escape)
                {
                    Window->close();
                }
            }
        }

        Window->clear(sf::Color::White);

        Draw();

        Window->display();
    }
    delete Window;
}
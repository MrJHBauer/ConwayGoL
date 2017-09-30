#include <iostream>
#include "../Header Files/World.h"

World::World(int Width, int Height, int Scale, sf::Time TickRate)
{
    this->Width = Width;
    this->Height = Height;
    this->Scale = Scale;
    this->TickRate = TickRate;
}

void World::Init()
{
    Window = new sf::RenderWindow(sf::VideoMode(Width, Height), "Conway Game of Life");
    Window->setFramerateLimit(60);
    CurrentGeneration = new Cell*[Height / Scale];
    for(auto row = 0; row < Height / Scale; row++)
    {
        CurrentGeneration[row] =  new Cell[Width / Scale];
    }
    State = WorldState::PAUSED;
}


void World::Tick()
{
    if(State == WorldState::PAUSED) return;
    sf::sleep(TickRate);
}

void World::Draw()
{
    sf::RectangleShape rectangle(sf::Vector2f(Scale, Scale));
    rectangle.setOutlineThickness(1.25);
    rectangle.setOutlineColor(sf::Color(128, 128, 128, 255));
    for(auto row = 0; row < Height / Scale; row++)
    {
        for(auto col = 0; col < Width / Scale; col++)
        {
            sf::Color color = CurrentGeneration[row][col].GetState() ==
                                      CellState::ALIVE ? sf::Color::Black : sf::Color::White;
            rectangle.setFillColor(color);
            rectangle.setPosition(col * Scale, row * Scale);
            Window->draw(rectangle);
        }
    }
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
                else if(event.key.code == sf::Keyboard::Space)
                {
                    State = State == WorldState::PAUSED ? WorldState::RUNNING : WorldState::PAUSED;
                }
            }
        }

        Window->clear(sf::Color::White);

        Tick();

        Draw();

        Window->display();
    }
    delete Window;
}
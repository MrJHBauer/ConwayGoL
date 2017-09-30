#include "../Header Files/World.h"

World::World(int Width, int Height, int Scale)
{
    this->Width = Width;
    this->Height = Height;
    this->Scale = Scale;
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
    CurrentGeneration[0][0].SetState(CellState::ALIVE);
    CurrentGeneration[(Height / Scale) - 1][0].SetState(CellState::ALIVE);
    CurrentGeneration[(Height / Scale) - 1][(Width / Scale) - 1].SetState(CellState::ALIVE);
    CurrentGeneration[0][(Width / Scale) - 1].SetState(CellState::ALIVE);

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
            }
        }

        Window->clear(sf::Color::White);

        Draw();

        Window->display();
    }
    delete Window;
}
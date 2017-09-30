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
        CurrentGeneration[row] = new Cell[Width / Scale];
    }
    State = WorldState::PAUSED;
}


void World::Tick()
{
    if(State == WorldState::PAUSED) return;
    sf::sleep(TickRate);
    auto** nextGeneration = new Cell*[Height / Scale];
    for(auto row = 0; row < Height / Scale; row++)
    {
        nextGeneration[row] = new Cell[Width / Scale];
    }
    for(auto row = 0; row < Height / Scale; row++)
    {
        for(auto col = 0; col < Width / Scale; col++)
        {
            int neighbourCount = 0;
            for(auto i = -1; i <= 1; i++)
            {
                for(auto j = -1; j <= 1; j++)
                {
                    int neighbourRow = row + i;
                    int neighbourCol = col + j;
                    if(IsCellValid(neighbourRow, neighbourCol) && (i != 0 || j != 0))
                    {
                        if(CurrentGeneration[neighbourRow][neighbourCol].GetState() == CellState::ALIVE)
                        {
                            neighbourCount++;
                        }
                    }
                }
            }
            if(CurrentGeneration[row][col].GetState() == CellState::ALIVE)
            {
                if(neighbourCount < 2 || neighbourCount > 3)
                {
                    nextGeneration[row][col].SetState(CellState::DEAD);
                }
                else
                {
                    nextGeneration[row][col].SetState(CellState::ALIVE);
                }
            }
            else if(CurrentGeneration[row][col].GetState() == CellState::DEAD)
            {
                if(neighbourCount == 3)
                {
                    nextGeneration[row][col].SetState(CellState::ALIVE);
                }
                else
                {
                    nextGeneration[row][col].SetState(CellState::DEAD);
                }
            }
        }
    }
    for(auto row = 0; row < Height / Scale; row++)
    {
        for(auto col = 0; col < Width / Scale; col++)
        {
            CurrentGeneration[row][col].SetState(nextGeneration[row][col].GetState());
        }
    }
    delete nextGeneration;
}

void World::HandleInput()
{
    if(State == WorldState::RUNNING) return;
    if(sf::Mouse::isButtonPressed(sf::Mouse::Left) || sf::Mouse::isButtonPressed(sf::Mouse::Right))
    {
        int row = (int) sf::Mouse::getPosition(*Window).y / Scale;
        int col = (int) sf::Mouse::getPosition(*Window).x / Scale;
        if(IsCellValid(row, col))
        {
            if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                CurrentGeneration[row][col].SetState(CellState::ALIVE);
            }
            else
            {
                CurrentGeneration[row][col].SetState(CellState::DEAD);
            }
        }
    }
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

bool World::IsCellValid(int Row, int Col)
{
    return (Row >= 0 && Row < Height / Scale) && (Col >= 0 && Col < Width / Scale);
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

        HandleInput();

        Draw();

        Window->display();
    }
    delete Window;
}
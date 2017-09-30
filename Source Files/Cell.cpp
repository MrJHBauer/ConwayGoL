#include "../Header Files/Cell.h"

Cell::Cell()
{
    SetState(CellState::DEAD);
}

Cell::Cell(CellState State)
{
    SetState(State);
}

CellState Cell::GetState()
{
    return State;
}

void Cell::SetState(CellState State)
{
    this->State = State;
}

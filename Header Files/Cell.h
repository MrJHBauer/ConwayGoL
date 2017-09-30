#ifndef CONWAYGOL_CELL_H
#define CONWAYGOL_CELL_H

/**
 * Used to distinguish between the two possible states any given cell may take.
 */
enum CellState
{
    DEAD,
    ALIVE
};

/**
 * Cell class provides the functionality of storing current state of a single
 * cell within the simulation environment. In addition to providing functions
 * for finding the current state of the cell and the ability to change the
 * state.
 */
class Cell
{
    CellState State;

public:
    Cell();
    Cell(CellState State);
    CellState GetState();
    void SetState(CellState State);
};

#endif
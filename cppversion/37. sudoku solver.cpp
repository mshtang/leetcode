#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <iostream>
#include <utility>
#include <vector>

bool updateConstraints(int i, int j, int excludedValue);
bool findValuesForEmptyCells();
bool backtrack(int k);

struct cell
{
  public:
    uint8_t value;
    uint8_t numPossibilities;
    std::bitset<10> constraints;
    cell() : value(0), numPossibilities(9), constraints(){};
};
std::array<std::array<cell, 9>, 9> cells;

// set the value of cells to [v]
// the function also propagates restraints to other cells and deduces new values where possible
bool set(int i, int j, int v)
{
    // updating the state of the cell
    cell &c = cells[i][j];
    if (c.value == v)
        return true;
    if (c.constraints[v])
        return false;
    c.constraints = std::bitset<10>(0x3FE); // all 1s
    c.constraints.reset(v);
    c.numPossibilities = 1;
    c.value = v;

    // propagating constraints
    for (int k = 0; k < 9; k++)
    {
        // to the row
        if (i != k && !updateConstraints(k, j, v))
            return false;
        // to the col
        if (j != k && !updateConstraints(i, k, v))
            return false;
        // to the subblock
        int ix = (i / 3) * 3 + k / 3;
        int jx = (j / 3) * 3 + k % 3;
        if (ix != i && jx != j && !updateConstraints(ix, jx, v))
            return false;
    }
    return true;
}

// update constraints of the cell i,j by excluding possibility of 'excludedValue'
// once there's one possibility left, the function recureses back into set()
bool updateConstraints(int i, int j, int excludedValue)
{
    cell &c = cells[i][j];
    if (c.constraints[excludedValue])
        return true;
    if (c.value == excludedValue)
        return false;
    c.constraints.set(excludedValue);
    if (--c.numPossibilities > 1)
        return true;

    for (int v = 1; v <= 9; v++)
    {
        if (!c.constraints[v])
            return set(i, j, v);
    }
    assert(false);
}

// backtracking state - list of empty cells
std::vector<std::pair<int, int>> bt;

// find values for empty cells
bool findValuesForEmptyCells()
{
    // collecting all empty cells
    bt.clear();
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (!cells[i][j].value)
                bt.push_back(std::make_pair(i, j));
        }
    }
    std::sort(bt.begin(), bt.end(), [](const std::pair<int, int> &a, const std::pair<int, int> &b) { return cells[a.first][a.second].numPossibilities < cells[b.first][b.second].numPossibilities; });
    return backtrack(0);
}

bool backtrack(int k)
{
    if (k >= bt.size())
        return true;
    int i = bt[k].first;
    int j = bt[k].second;
    // fast path - only one possibility
    if (cells[i][j].value)
        return backtrack(k + 1);
    auto constraints = cells[i][j].constraints;
    // slow path >1 possibility
    // making snapshot of the state
    std::array<std::array<cell, 9>, 9> snapshot(cells);
    for (int v = 1; v <= 9; v++)
    {
        if (!constraints[v])
        {
            if (set(i, j, v))
            {
                if (backtrack(k + 1))
                    return true;
            }
            // restoring from snapshot
            cells = snapshot;
        }
    }
    return false;
}

void solveSudoku(std::vector<std::vector<char>> &board)
{
    cells = std::array<std::array<cell, 9>, 9>(); // clear array
    // decoding the input board into the internal cell matrix
    // as we do it, constraints are propagated and even additional values are set as we go
    // (in the case if it is possible to unambiguously deduce them).
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (board[i][j] != '.' && !set(i, j, board[i][j] - '0'))
                return; // sudoku is either incorrect or unsolvable
        }
    }
    if (!findValuesForEmptyCells())
        return; // sudoku is unsolvable

    // copying the solution back to the board
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (cells[i][j].value)
                board[i][j] = cells[i][j].value + '0';
        }
    }
}

int main()
{
    std::vector<std::vector<char>> sudoku{
        {'8', '.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '3', '6', '.', '.', '.', '.', '.'},
        {'.', '7', '.', '.', '9', '.', '2', '.', '.'},
        {'.', '5', '.', '.', '.', '7', '.', '.', '.'},
        {'.', '.', '.', '.', '4', '5', '7', '.', '.'},
        {'.', '.', '.', '1', '.', '.', '.', '3', '.'},
        {'.', '.', '1', '.', '.', '.', '.', '6', '8'},
        {'.', '.', '8', '5', '.', '.', '.', '1', '.'},
        {'.', '9', '.', '.', '.', '.', '4', '.', '.'}};
    solveSudoku(sudoku);
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            std::cout << sudoku[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cin.get();
}

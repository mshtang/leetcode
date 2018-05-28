#include <iostream>
#include <vector>

bool isValidSudoku(std::vector<std::vector<char>> &board)
{
    int used_row[9][9] = {0}, used_col[9][9] = {0}, used_subbox[9][9] = {0};
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[i].size(); j++)
        {
            if (board[i][j] != '.')
            {
                int num = board[i][j] - '0' - 1;
                int k = i / 3 * 3 + j / 3;
                if (used_row[i][num] || used_col[j][num] || used_subbox[k][num])
                    return false;
                used_row[i][num] = used_col[j][num] = used_subbox[k][num] = 1;
            }
        }
    }
    return true;
}

int main()
{
    std::vector<std::vector<char>> sudoku1{
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};
    std::vector<std::vector<char>> sudoku2{
        {'8', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};

    std::cout << isValidSudoku(sudoku1) << std::endl;
    std::cout << isValidSudoku(sudoku2) << std::endl;
    std::cin.get();
}
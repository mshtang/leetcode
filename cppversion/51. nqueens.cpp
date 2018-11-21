#include <iostream>
#include <vector>

void printSolution(std::vector<std::vector<std::string>> &board)
{
	for (auto row : board)
	{
		for (auto col : row)
		{
			std::cout << col << " ";
		}
		std::cout << std::endl;
	}
}

bool isSafe(std::vector<std::vector<std::string>> &board, int row, int col)
{
	// check this row on the left side
	for (int i = 0; i < col; i++)
	{
		if (board[row][i] == "Q")
			return false;
	}
	// check upper diagonal on left side
	for (int i = row, j = col; i >= 0 and j >= 0; i--, j--)
	{
		if (board[i][j] == "Q")
			return false;
	}
	// check lower diagonal on left side
	for (int i = row, j = col; i >= 0 and j >= 0; i++, j--)
	{
		if (board[i][i] == "Q")
			return false;
	}
	return true;
}

bool solveNQUtil(std::vector<std::vector<std::string>> &board, int col)
{

	int nrows = board.size();
	int ncols = board[0].size();

	if (col >= ncols)
		return true;
	// consider this col and try placing this queen in all rows on by one
	for (int i = 0; i < nrows; i++)
	{
		if (isSafe(board, i, col))
		{
			// place this queen in board[i][col]
			board[i][col] = "Q";
			// recursively to place rest of the queens
			if (solveNQUtil(board, col + 1))
				return true;
			// if placing queen in board[i][col] isn't possible, then remove
			board[i][col] = ".";
		}
	}
	// if the queen cannot be placed in any row in this col
	return false;
}

bool solveQ()
{
	std::vector<std::vector<std::string>> board = {
		{".", ".", ".", "."},
		{".", ".", ".", "."},
		{".", ".", ".", "."},
		{".", ".", ".", "."},
	};
	if (solveNQUtil(board, 0) == false)
	{
		std::cout << "Solution doesn't exist." << std::endl;
		return false;
	}
	printSolution(board);
	return true;
}

int main()
{
	solveQ();
	std::cin.get();
	return 0;
}
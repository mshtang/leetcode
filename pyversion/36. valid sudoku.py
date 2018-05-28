def isValidSudoku(board, verbose=False):

    # used three tables to keep track of the digits used
    # with each row representing the coordinate
    # and the col the actual digit
    used_row = [[0 for i in range(9)] for j in range(9)]
    used_col = [[0 for i in range(9)] for j in range(9)]
    used_sub = [[0 for i in range(9)] for j in range(9)]

    for i in range(9):
        for j in range(9):
            if board[i][j] != '.':
                digit = ord(board[i][j]) - ord('0') - 1
                k = i // 3 * 3 + j // 3
                if (used_row[i][digit] or used_col[j][digit] or used_sub[k][digit]):
                    return False
                used_row[i][digit] = used_col[j][digit] = used_sub[k][digit] = 1


    if verbose:
        def pretty_print(output):
            for i in range(len(output)):
                print(output[i])

        print('row flags:\n')
        pretty_print(used_row)
        print('\ncol flags:\n')
        pretty_print(used_col)
        print('\nsubbox flags:\n')
        pretty_print(used_sub)

    return True


if __name__ == '__main__':
    sudoku1 = [["5", "3", ".", ".", "7", ".", ".", ".",
                "."], ["6", ".", ".", "1", "9", "5", ".", ".",
                       "."], [".", "9", "8", ".", ".", ".", ".", "6", "."],
               ["8", ".", ".", ".", "6", ".", ".", ".",
                "3"], ["4", ".", ".", "8", ".", "3", ".", ".",
                       "1"], ["7", ".", ".", ".", "2", ".", ".", ".", "6"],
               [".", "6", ".", ".", ".", ".", "2", "8",
                "."], [".", ".", ".", "4", "1", "9", ".", ".",
                       "5"], [".", ".", ".", ".", "8", ".", ".", "7", "9"]]
    sudoku2 = [["8", "3", ".", ".", "7", ".", ".", ".",
                "."], ["6", ".", ".", "1", "9", "5", ".", ".",
                       "."], [".", "9", "8", ".", ".", ".", ".", "6", "."],
               ["8", ".", ".", ".", "6", ".", ".", ".",
                "3"], ["4", ".", ".", "8", ".", "3", ".", ".",
                       "1"], ["7", ".", ".", ".", "2", ".", ".", ".", "6"],
               [".", "6", ".", ".", ".", ".", "2", "8",
                "."], [".", ".", ".", "4", "1", "9", ".", ".",
                       "5"], [".", ".", ".", ".", "8", ".", ".", "7", "9"]]
    print(isValidSudoku(sudoku1, True))
    print(isValidSudoku(sudoku2, True))

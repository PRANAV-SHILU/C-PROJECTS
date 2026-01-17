/**
 * The below C program is a Sudoku solver that uses backtracking/recursion to solve a given puzzle.
 *
 * @param puzzle The `puzzle` array represents a 9x9 Sudoku puzzle grid. Each element in the grid contains a number from 1 to 9, where 0 represents an empty cell that needs to be filled.
 */
#include <stdio.h>

int puzzle[9][9] = {
    {3, 0, 0, 0, 2, 0, 0, 7, 0},
    {9, 0, 0, 5, 0, 0, 0, 1, 4},
    {0, 1, 6, 3, 7, 0, 0, 0, 8},
    {2, 0, 0, 8, 0, 0, 0, 0, 1},
    {5, 0, 0, 0, 4, 1, 8, 0, 0},
    {0, 8, 9, 0, 0, 0, 0, 5, 0},
    {0, 0, 5, 0, 1, 0, 2, 8, 0},
    {0, 4, 0, 0, 0, 6, 0, 9, 3},
    {7, 3, 1, 0, 8, 2, 0, 0, 0},
};

void print_puzzle(int puzzle[9][9])
{
    printf("\n+-------+-------+-------+");

    for (int row = 0; row < 9; row++)
    {
        if (row % 3 == 0 && row != 0)
            printf("\n|-------|-------|-------|");

        printf("\n");
        for (int col = 0; col < 9; col++)
        {
            if (col % 3 == 0)
                printf("| ");

            if (puzzle[row][col] == 0)
                printf("  ");
            else
                printf("%d ", puzzle[row][col]);
        }
        printf("|");
    }

    printf("\n+-------+-------+-------+\n\n");
}

int valid_puzzle(int puzzle[9][9], int row, int col, int val)
{
    for (int i = 0; i < 9; i++)
    {
        if (puzzle[row][i] == val)
            return 0;
        if (puzzle[i][col] == val)
            return 0;
    }

    int r = row - row % 3;
    int c = col - col % 3;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (puzzle[r + i][c + j] == val)
                return 0;
        }
    }
    return 1;
}

int solve_puzzle(int puzzle[9][9], int row, int col)
{

    if (col == 9)
    {
        if (row == 8)
            return 1; // Puzzle solved

        col = 0;
        row++;
    }

    if (puzzle[row][col] > 0)
        return solve_puzzle(puzzle, row, col + 1);

    for (int i = 1; i <= 9; i++)
    {
        if (valid_puzzle(puzzle, row, col, i))
        {
            puzzle[row][col] = i;

            if (solve_puzzle(puzzle, row, col + 1))
                return 1;

            puzzle[row][col] = 0; // Backtrack & reset
        }
    }
    return 0;
}

int main()
{
    printf("\nWelcome to Sudoku Solver\n");
    printf("\nOriginal Puzzle");
    print_puzzle(puzzle);

    // printf("%d", valid_puzzle(puzzle, 0, 1, 3)); //false
    // printf("\n%d", valid_puzzle(puzzle, 0, 1, 5)); //true

    if (solve_puzzle(puzzle, 0, 0))
    {
        printf("Solved Puzzle:");
        print_puzzle(puzzle);
    }
    else
        printf("No solution exists!\n");

    return 0;
}
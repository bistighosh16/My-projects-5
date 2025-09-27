#include <stdio.h>
#include <stdbool.h>
#define N 9
void printGrid(int grid[N][N])
{
    for (int row = 0; row < N; row++)
    {
        for (int col = 0; col < N; col++)
        {
            if (grid[row][col] == 0)
                printf(". ");
            else
                printf("%d ", grid[row][col]);
        }
        printf("\n");
    }
}
bool isSafe(int grid[N][N], int row, int col, int num)
{
    for (int x = 0; x < N; x++)
    {
        if (grid[row][x] == num)
            return false;
    }
    for (int x = 0; x < N; x++)
    {
        if (grid[x][col] == num)
            return false;
    }
    int startRow = row - row % 3;
    int startCol = col - col % 3;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (grid[i + startRow][j + startCol] == num)
                return false;
        }
    }
    return true;
}
bool solveSudoku(int grid[N][N])
{
    int row, col;
    bool emptyFound = false;
    for (row = 0; row < N; row++)
    {
        for (col = 0; col < N; col++)
        {
            if (grid[row][col] == 0)
            {
                emptyFound = true;
                break;
            }
        }
        if (emptyFound) break;
    }
    if (!emptyFound)
        return true;
    for (int num = 1; num <= N; num++)
    {
        if (isSafe(grid, row, col, num))
        {
            grid[row][col] = num;
            if (solveSudoku(grid))
                return true;
            grid[row][col] = 0;
        }
    }
    return false;
}
bool giveHint(int grid[N][N], int solution[N][N])
{
    for (int row = 0; row < N; row++)
    {
        for (int col = 0; col < N; col++)
        {
            if (grid[row][col] == 0)
            {
                grid[row][col] = solution[row][col];
                return true;
            }
        }
    }
    return false;
}
int main()
{
    int grid[N][N] =
    {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };
    int solution[N][N];
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            solution[i][j] = grid[i][j];
        }
    }
    if (!solveSudoku(solution))
    {
        printf("Error: Unable to generate the solution for the given puzzle.\n");
        return 1;
    }
    printf("Here is the Sudoku puzzle:\n");
    printGrid(grid);
    int choice, row, col, num;
    while (true)
    {
        printf("\nOptions:\n");
        printf("1. Enter a number\n");
        printf("2. Get a hint\n");
        printf("3. Show the solution\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter row (1-9), column (1-9), and number (1-9): ");
            scanf("%d %d %d", &row, &col, &num);
            row--;
            col--; // Convert to 0-based indexing
            if (row >= 0 && row < N && col >= 0 && col < N)
            {
                if (grid[row][col] == 0 && isSafe(grid, row, col, num))
                {
                    grid[row][col] = num;
                    printf("Number placed successfully!\n");
                    printGrid(grid);
                }
                else
                {
                    printf("Invalid move! Try again.\n");
                }
            }
            else
            {
                printf("Invalid input! Row and column must be between 1 and 9.\n");
            }
            break;
        case 2:
            if (giveHint(grid, solution))
            {
                printf("Hint added to the puzzle:\n");
                printGrid(grid);
            }
            else
            {
                printf("No empty cells available for a hint!\n");
            }
            break;
        case 3:
            printf("Here is the solution:\n");
            printGrid(solution);
            return 0;
        case 4:
            printf("Exiting. Goodbye!\n");
            return 0;
        default:
            printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}

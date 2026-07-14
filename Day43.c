#include <stdio.h>

#define N 9

int grid[N][N];

int isSafe(int row, int col, int num)
{
    for(int i = 0; i < N; i++)
    {
        if(grid[row][i] == num)
            return 0;

        if(grid[i][col] == num)
            return 0;
    }

    int startRow = row - row % 3;
    int startCol = col - col % 3;

    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            if(grid[startRow + i][startCol + j] == num)
                return 0;
        }
    }

    return 1;
}

int solve()
{
    int row = -1, col = -1;

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            if(grid[i][j] == 0)
            {
                row = i;
                col = j;
                goto FOUND;
            }
        }
    }

FOUND:

    if(row == -1)
        return 1;

    for(int num = 1; num <= 9; num++)
    {
        if(isSafe(row, col, num))
        {
            grid[row][col] = num;

            if(solve())
                return 1;

            grid[row][col] = 0;
        }
    }

    return 0;
}

void printGrid()
{
    printf("\nSolved Sudoku\n\n");

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
            printf("%d ", grid[i][j]);

        printf("\n");
    }
}

int main()
{
    printf("Enter Sudoku (0 for Empty Cell)\n");

    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            scanf("%d", &grid[i][j]);

    if(solve())
        printGrid();
    else
        printf("No Solution Exists\n");

    return 0;
}

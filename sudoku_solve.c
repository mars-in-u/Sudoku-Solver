#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

void read_problem(int grid[9][9]);
bool isValid(int grid[9][9], int r, int c, int num);
bool solve(int grid[9][9], int r, int c);

int main(void)
{
    int grid[9][9], wait, i, j;
    read_problem(grid); // reading the random problem

    // printing the random problem
    printf("Problem:\n");
    for (i = 0; i < 9; i++)
    {
        for (j = 0; j < 9; j++)
        {
            printf("%d", grid[i][j]);
        }
        printf("\n");
    }

    solve(grid, 0, 0);
    printf("\n\nSolution:\n");

    // printing the random problem solution
    for (i = 0; i < 9; i++)
    {
        for (j = 0; j < 9; j++)
        {
            printf("%d", grid[i][j]);
        }
        printf("\n");
    }

    // In order to pause the screen
    scanf("%d", &wait);
    return 0;
}

void read_problem(int grid[9][9])
{
    srand(time(0));
    int rand_problem_no = (rand() % 50); // generating a random number between 0 and 49

    int i, j;
    int cnt = 0; // count the number of lines in the txt file
    FILE *file;
    file = fopen("sudoku.txt", "r");
    char line[15]; // stores each line of the file as a string temporarily

    if (file)
    {
        // skipping the lines before the random problem
        for (i = 0; i < rand_problem_no * 10 + 1; i++)
        {
            fgets(line, sizeof(line), file);
        }

        // reading the random problem
        for (i = 0; i < 9; i++)
        {
            fgets(line, sizeof(line), file);
            for (j = 0; j < 9; j++)
            {
                grid[i][j] = line[j] - '0';
            }
        }
    }

    fclose(file);
}

bool solve(int grid[9][9], int r, int c)
{
    if (r == 9)
        return true;
    else if (c == 9)
        return solve(grid, r + 1, 0);
    else if (grid[r][c] != 0)
        return solve(grid, r, c + 1);
    else
    {
        for (int k = 1; k <= 9; k++)
        {
            if (isValid(grid, r, c, k))
            {
                grid[r][c] = k;
                if (solve(grid, r, c + 1))
                    return true;
                grid[r][c] = 0;
            }
        }
        return false;
    }

    return 0;
}

// bool isValid(int grid, int r, int c, int k)
// {
//     return true;
// }

bool isValid(int grid[9][9], int r, int c, int num)
{
    // Check if num is in the same row
    for (int i = 0; i < 9; i++)
    {
        if (grid[r][i] == num)
        {
            return false;
        }
    }

    // Check if num is in the same column
    for (int i = 0; i < 9; i++)
    {
        if (grid[i][c] == num)
        {
            return false; //
        }
    }

    // Check if num is in the same 3x3 subgrid
    int startRow = r - r % 3, startCol = c - c % 3;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (grid[i + startRow][j + startCol] == num)
            {
                return false;
            }
        }
    }

    return true; // Placement is valid
}
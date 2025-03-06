#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int grid[9][9];

    srand(time(0));
    int rand_problem_no = (rand() % 50); // generating a random number between 0 and 49
    int sn;
    int cnt = 0; // count the number of lines in the txt file
    FILE *file;
    char line[15]; // stores each line of the file as a string temporarily
    file = fopen("sudoku.txt", "r");
    if (file)
    {
        while ((fgets(line, sizeof(line), file)))
        {
            // printf("%d\n", cnt);  testing the count of lines
            // printf("%s", line);
            sn = cnt - rand_problem_no * 10 - 1;
            if (cnt >= rand_problem_no * 10 + 1) // skip the lines before the random problem
            {
                // printf("%s", line);
                for (int i = 0; i < 9; i++)
                {
                    grid[sn][i] = line[i] - '0';
                    // printf("%d", grid[sn][i]);
                }
                // printf("\n");
            }
            if (cnt == (rand_problem_no + 1) * 10 - 1) // stop after the 10 lines of the random problem
            {
                break;
            }
            cnt += 1;
        }
    }

    fclose(file);
    printf("%d", grid[0][0] + 1);
    scanf("%d", &cnt); // In order to pause the screen

    return 0;
}

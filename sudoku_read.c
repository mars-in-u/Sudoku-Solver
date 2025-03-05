#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{

    srand(time(0));
    int rand_problem_no = (rand() % 50); // generating a random number between 0 and 49

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

            if (cnt >= rand_problem_no * 10) // skip the lines before the random problem
            {
                printf("%s", line);
            }
            if (cnt == (rand_problem_no + 1) * 10 - 1) // stop after the 10 lines of the random problem
            {
                break;
            }
            cnt += 1;
        }
    }

    fclose(file);
    scanf("%d", &cnt); // In order to pause the screen
    return 0;
}
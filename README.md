# Sudoku Problem Reader

This program reads a random Sudoku problem from a file named `sudoku.txt`. Each Sudoku problem is assumed to be 10 lines long, and the program will randomly select one of the 50 problems in the file to display.

## How It Works

1. The program initializes the random number generator using the current time.
2. It generates a random number between 0 and 49 to select one of the 50 Sudoku problems.
3. It opens the `sudoku.txt` file and reads through the lines.
4. It skips lines until it reaches the start of the randomly selected problem.
5. It prints the 10 lines of the selected Sudoku problem.
6. The program pauses to allow the user to see the output before exiting.

## File Structure

- `sudoku_read.c`: The main C program file.
- `sudoku.txt`: The text file containing 50 Sudoku problems, each 10 lines long.

## Usage

1. Ensure you have a file named `sudoku.txt` in the same directory as the `sudoku_read.c` program.
2. Compile the program using a C compiler. For example:
    ```sh
    gcc sudoku_read.c -o sudoku_read
    ```
3. Run the compiled program:
    ```sh
    ./sudoku_read
    ```

## Example `sudoku.txt` Format

The `sudoku.txt` file should contain 50 Sudoku problems, each 10 lines long. For example:

```
Problem 1 Line 1
Problem 1 Line 2
...
Problem 1 Line 10
Problem 2 Line 1
Problem 2 Line 2
...
Problem 2 Line 10
...
Problem 50 Line 1
Problem 50 Line 2
...
Problem 50 Line 10
```

## Notes

- Ensure that each line in `sudoku.txt` does not exceed 15 characters, as the program uses a buffer of size 15 to read each line.
- The program will pause and wait for user input before exiting, allowing you to see the output.

## License

This project is licensed under the MIT License.

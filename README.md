# skyscraper-solver

42 Piscine Rush01 project.

This repository contains my solution for the Rush01 project from the 42 Piscine.  
The goal of the project is to solve a 4x4 Skyscraper puzzle using C.

## Project description

Rush01 is a puzzle where a 4x4 grid must be filled with numbers from `1` to `4`.

Each row and each column must contain every number only once:

```txt
1 2 3 4
```

The program receives 16 outside clues as a single argument.  
These clues describe how many boxes are visible from each side of the grid.

Example:

```sh
./rush01 "4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2"
```

Expected output example:

```txt
1 2 3 4
2 3 4 1
3 4 1 2
4 1 2 3
```

If the input is invalid or no solution exists, the program prints:

```txt
Error
```

## Input format

The input must contain exactly 16 numbers from `1` to `4`, separated by single spaces.

The clues are ordered like this:

```txt
col1top col2top col3top col4top
col1bottom col2bottom col3bottom col4bottom
row1left row2left row3left row4left
row1right row2right row3right row4right
```

In the program, they are stored in `views[16]`:

```txt
views[0..3]    = top views
views[4..7]    = bottom views
views[8..11]   = left views
views[12..15]  = right views
```

## Algorithm

The project uses a backtracking algorithm.

Backtracking means:

```txt
try a number
continue solving
if it fails later, undo the choice
try another number
```

The solver fills the grid one position at a time.

```txt
pos 0  -> grid[0][0]
pos 1  -> grid[0][1]
pos 2  -> grid[0][2]
pos 3  -> grid[0][3]
...
pos 15 -> grid[3][3]
pos 16 -> grid is full, check all views
```

For each position, the solver tries numbers from `1` to `4`.

A number is valid if it does not already exist in the same row or column.

When the grid is full, the program checks whether all outside views match.  
If they do, the grid is printed.  
If they do not, the solver backtracks and tries another possibility.

## File structure

```txt
ex00/
├── check.c
├── init_grid.c
├── main.c
├── parse_input.c
├── print_error.c
├── print_grid.c
└── solve.c
```

## Functions

### `parse_input`

Reads the argument string and stores the 16 clues inside `views[16]`.

It checks that:

```txt
there are exactly 16 numbers
numbers are between 1 and 4
numbers are separated by spaces
```

### `init_grid`

Initializes the 4x4 grid with zeroes.

A zero means the cell is empty.

### `solve`

Fills the grid using backtracking.

It tries numbers from `1` to `4`, checks if they are valid, and recursively moves to the next position.

### `is_valid_number`

Checks if a number can be placed in a cell without repeating in the same row or column.

### `check_all_views`

Checks if the completed grid matches all outside clues.

### `count_visible`

Counts how many boxes are visible from one direction.

### `print_grid`

Prints the solved grid.

### `print_error`

Prints:

```txt
Error
```

## Compilation

Compile from inside the `ex00` folder:

```sh
cc -Wall -Wextra -Werror -o rush01 *.c
```

Run:

```sh
./rush01 "4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2"
```

## Notes

Only allowed external functions are used.  
The program does not use `printf`, `atoi`, `malloc`, or `free`.

The grid size is fixed to 4x4 for the mandatory part of the project.

## Bonus / Future improvement

A future version of this project will generalize the solver from a fixed 4x4 grid to variable grid sizes up to 9x9.

## Author

KruKuma

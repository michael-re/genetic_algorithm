# Genetic Algorithm: Sudoku Solver

## Description

This project implements a sudoku solver that uses a genetic algorithm (GA) to
solve sudoku puzzles. It is designed to take a sudoku puzzle as input, apply
genetic algorithm operations, and return the fittest puzzle from the population
after said operations. The genetic algorithm involves creating a population of
sudoku puzzles, evaluating their fitness, culling the least-fit puzzles, and
generating new generations until a solution is found or the maximum number of
generations is reached.

For details on background information about this project and/or the statement of
work, please refer to the following documents:

- **[`Background`](docs/background.md)**
- **[`Statement of Work`](docs/statement_of_work.md)**

## Getting Started

### Compiling The Program

Follow these steps to compile the program:

* Clone the repository to your local machine:
* Navigate to the project directory:

    ```
    cd genetic_algorithm/
    ```

* Build the program using the provided **[`makefile`](makefile)**:

    ```bash
    make
    ```

* Alternatively, you can compile the program using the following command:

    ```bash
    g++ -std=c++11 -O3 -Iinclude/ src/*.cpp -o genetic_solver
    ```

### Running The Program

The `genetic_solver` program takes two command-line arguments to run:

- `<population size>`: The number of individuals in the population.
- `<max generations>`: The maximum number of generations to run the algorithm.

To run the program, use the following command and provide values for `<population size>` and `<max generations>`:

```bash
./genetic_solver <population size> <max generations>
```

When the program starts, you will be prompted to enter a puzzle. The program
will keep reading from `std::cin` until 81 digits are entered. If you prefer
not to manually enter a puzzle, you can simply pipe a file that contains a
puzzle to `std::cin`:

```bash
./genetic_solver <population_size> <max_generations> < input_puzzle.txt
```

## Test puzzles

Under the **[`puzzles`](puzzles)** directory, you can find a list of pre-defined
test puzzles to test the program. You can pipe in these file into the program or
manually enter them when prompted.

### Provided puzzles

- **[`example 1`](puzzles/sudoku_ex_1.txt):** `409806701001307200030009004500030680090000050026080007300100020004603900908402503`
- **[`example 2`](puzzles/sudoku_ex_2.txt):** `100090005040050090800302004208000603003206400504000709700605001050080030400030002`
- **[`easy 1`](puzzles/sudoku_easy_1.txt):** `037000150005710030010350700000507301351000070700031005570103000100075003003000517`
- **[`easy 2`](puzzles/sudoku_easy_2.txt):** `007605831508713600136800057813007506060581073705036180670150308381070065050368710`
- **[`easy 3`](puzzles/sudoku_easy_3.txt):** `900020604060940200420060900002004069609200040004096020040602090290000406006409002`
- **[`medium 1`](puzzles/sudoku_medium_1.txt):** `003040000200300049040209300030020904020490030409003200002000493304900000900034000`
- **[`medium 2`](puzzles/sudoku_medium_2.txt):** `007020009509000270002597000200000905790250000050009720900702050075900002020005000`
- **[`hard 1`](puzzles/sudoku_hard_1.txt):** `070004000030000000000000090000680001308045760007010900903000670050300400160000000`
- **[`hard 2`](puzzles/sudoku_hard_2.txt):** `020600400807100000060003020000000080002400500000708301000000000040007062050000800`

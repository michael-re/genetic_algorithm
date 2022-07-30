# Statement of Work

In this program, you are asked to design and implement a set of classes that
define the abstractions necessary to solve puzzles of any kind using a GA.
You will then produce concrete subclasses that implement these interfaces for
sudoku. The overall class relationships are described by the figure below.

![figure 1](/docs/images/figure_1.png)

## Puzzle and Sudoku Classes

The `Puzzle` class defines the abstract interface for any puzzle to be used by
the GA framework. A large number of puzzle (subclass) objects are held by a
`Population` (subclass) object. Subclasses must implement stream I/O helper
methods (the files **`Sudoku.hpp`** and **`Sudoku.cpp`** will define the
standard stream I/O operators, **`operator<()`** and **`operator>>()`**, to
call these methods). You are free to add additional pure virtual methods
to this class as you flesh out your design.

Your `Sudoku` class must hold the representation of a sudoku puzzle.
This means that it must know the numbers of the 9 by 9 grid, as well
as the fitness level of the puzzle.

The `Sudoku` stream input helper method must read a puzzle in a compact text
format. The format consists of a sequence of 81 digits, as ASCII text, each
corresponding to the contents of one square in the puzzle grid, in _row-major_
order (i.e., starting at the upper left corner, reading across each row and then
continuing with the next row, ending at the bottom right corner).
Blank (variable) squares are represented with zeros; fixed squares of course
have non-zero values. Your method should ignore all non-digit characters
(i.e., scan the input character by character and use the first 81 ASCII
characters in the set {0, 1, ..., 9} found). Your input operator should not
make any assumptions about white space (i.e., it works for inputs that do and
do not have white space between characters).

The `Sudoku` stream output helper method must produce a "human friendly" output
as formatted text. Output a puzzle as 13 lines of text, with each line either
being a separator or one containing the numbers in a row of the puzzle separated
by single spaces. Use the '|', '+', and '-' characters to separate 3-by-3 blocks
(so, each line of output should be 25 printing characters long: 9 digits, 12
spaces, and 4 '|' for non-divider lines and 21 '-' and 4 '+' for divider lines).

```c++
Example output:
+-------+-------+-------+
| 9 8 5 | 3 2 1 | 6 7 4 |
| 1 6 3 | 9 4 7 | 2 5 8 |
| 4 2 7 | 5 6 8 | 9 1 3 |
+-------+-------+-------+
| 5 1 2 | 8 7 4 | 3 6 9 |
| 6 7 9 | 2 5 3 | 8 4 1 |
| 8 3 4 | 1 9 6 | 5 2 7 |
+-------+-------+-------+
| 7 4 8 | 6 3 2 | 1 9 5 |
| 2 9 1 | 8 7 5 | 4 3 6 |
| 3 5 6 | 4 1 9 | 7 8 2 |
+-------+-------+-------+
```

## Population and SudokuPopulation Classes

A `Population` is a container for a number of puzzles. It can use a `Fitness`
strategy to evaluate the quality of a `Puzzle`. It can **`cull`** puzzles from
the population (based on their fitness). It can use a `PuzzleFactory` and an
`Offspring` strategy to produce a new generation of puzzles from the most fit
members of the old generation. It performs these operations when commanded by
the main `GeneticAlgorithm`. `Population` or its subclasses must implement:

| method                |                                                                    |
| --------------------- | ------------------------------------------------------------------ |
| constructors          | create an initial, random set of puzzles                           |
| **`cull`**            | eliminates the _`X`_% least fit members of the current generation  |
| **`new_generation`**  | produces a new generation with `N` individuals for every single individual in the old generation — presumably after the old generation has been culled, so that the population size stays constant from one generation to the next. |
| **`best_fitness`**    | returns the fitness of the best `Puzzle` in the current generation |
| **`best_individual`** | returns the `Puzzle` with the highest fitness                      |

You are free to add additional pure virtual methods to this class as you flesh
out your design. The `SudokuPopulation` class implements all `Population`
methods for `Sudoku` objects.

## PuzzleFactory and SudokuFactory Classes

A `PuzzleFactory` is an **[`abstract factory`](http://www.oodesign.com/abstract-factory-pattern.html)**
design pattern for producing puzzles. Subclasses must implement a
**`create_puzzle`** method, which returns a new `Puzzle` (subclass) object.
You are free to add additional pure virtual methods to this class as you flesh
out your design.

The `SudokuFactory` uses a `SudokuOffspring` object and implements
**`create_puzzle`** to produce new `Sudoku` objects.

## Fitness and SudokuFitness Classes

A fitness value is used by a `Population` to compare individual Puzzles.
`Fitness` and its subclasses are implementations of the
**[`strategy`](http://www.oodesign.com/strategy-pattern.html)** design pattern.
`Fitness` subclasses must implement a **`how_fit`** method, which takes a
`Puzzle` (subclass) object and returns an `int`. Perhaps counter-intuitively,
lower fitness values indicate more fit individuals (in other words,
**`how_fit`** is indicating how far a Puzzle is from perfection).

The `SudokuFitness` class implements **`how_fit`** for `Sudoku` objects.
To evaluate the fitness score, count the total number of conflicts in a puzzle:
how many duplicate entries there are in each row, column, and 3- by-3 block.
Each duplicate pair will count as two conflicts (not just one): eg. two 3s in
the same row would increase the fitness by 2, three 3s in the same row would
increase the fitness by 6, and two 3s in the same row _and_ block would increase
the fitness by 4.

## Offspring and SudokuOffspring Classes

`Offspring` is used by `PuzzleFactory` to create new puzzles from old ones.
`Offspring` and its subclasses are also implementations of the strategy design
pattern. Offspring subclasses must implement a **`make_offspring`** method,
which takes a `Puzzle` and returns a new `Puzzle`.

The `SudokuOffspring` class implements **`make_offspring`** for `Sudoku`
objects. In this program, you need not implement all of the different genetic
operations mentioned **[`here`](http://www.genetic-programming.com/gpanimatedtutorial.html)**
(crossover, mutation, and architecture-altering operations); you need only
implement mutation. A simple implementation would make a copy of the original
Sudoku, with some probability (you might start with values like 2% or 5%)
of changing each variable number in the puzzle as it is copied.

## The Program

Your program should take two _command line_ arguments: the size of the
population and the maximum number of generations. It should then read the
`Sudoku` puzzle from cin, print that puzzle in the “human friendly” format,
and create the first generation (i.e., randomly fill in the squares that are
not fixed to produce a population of the specified size with that many different
puzzles). It should then begin the GA iterations. In each iteration, it should:

1. command the `Population` to cull 90% of its puzzles, then
2. command the `Population` to reproduce a **`new_generation`**
3. halt iterations if a solution has been found or if the maximum number of
   generations has been reached, otherwise move on to the next iteration

At the end, it should output whether the puzzle was solved or not and the
solution (along with the number of generations it took to solve) or the best
puzzle found (along with its fitness value).

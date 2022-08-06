#include <iostream>

#include "sudoku_fitness.hpp"
#include "sudoku_offspring.hpp"

auto main() -> int
{
    auto puzzle = (Puzzle*) new Sudoku();
    std::cout << "Enter sudoku puzzle: ";
    std::cin >> *puzzle;
    std::cout << "Puzzle: " << *puzzle << std::endl;
    std::cout << "Fitness: " << SudokuFitness().how_fit(puzzle) << std::endl;

    auto offspring = SudokuOffspring().make_offspring(puzzle);
    std::cout << "\nOffspring: " << *offspring << std::endl;
    std::cout << "Fitness: " << SudokuFitness().how_fit(offspring) << std::endl;

    delete puzzle;
    delete offspring;
    return EXIT_SUCCESS;
}

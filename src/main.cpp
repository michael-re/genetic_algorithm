#include <iostream>

#include "sudoku_fitness.hpp"
#include "sudoku_factory.hpp"

auto main() -> int
{
    std::cout << "Enter sudoku puzzle: ";

    auto puzzle = SudokuFactory().create_puzzle(std::cin);
    std::cout << "Puzzle: " << *puzzle << std::endl;
    std::cout << "Fitness: " << SudokuFitness().how_fit(puzzle) << std::endl;

    auto offspring = SudokuFactory().create_puzzle(puzzle);
    std::cout << "\nOffspring: " << *offspring << std::endl;
    std::cout << "Fitness: " << SudokuFitness().how_fit(offspring) << std::endl;

    delete puzzle;
    delete offspring;
    return EXIT_SUCCESS;
}

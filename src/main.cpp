#include <iostream>

#include "sudoku_factory.hpp"
#include "sudoku_fitness.hpp"
#include "population.hpp"

auto main() -> int
{
    std::cout << "Enter sudoku puzzle: ";
    
    auto puzzle = SudokuFactory().create_puzzle(std::cin);
    auto fitness = SudokuFitness().how_fit(puzzle);
    auto individual = Population::Individual(puzzle, fitness);

    std::cout << individual << std::endl;
    return EXIT_SUCCESS;
}

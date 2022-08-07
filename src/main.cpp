#include <iostream>

#include "sudoku_factory.hpp"
#include "population.hpp"

auto main() -> int
{
    std::cout << "Enter sudoku puzzle: ";
    auto puzzle = Population::Individual(SudokuFactory().create_puzzle(std::cin), 100);
    std::cout << puzzle << std::endl;
    return EXIT_SUCCESS;
}

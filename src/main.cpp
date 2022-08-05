#include <iostream>

#include "sudoku.hpp"

auto main() -> int
{
    auto puzzle = (Puzzle*) new Sudoku();
    std::cout << "Enter sudoku puzzle: ";
    std::cin >> *puzzle;
    std::cout << "Puzzle: " << *puzzle << std::endl;
    delete puzzle;
    return EXIT_SUCCESS;
}

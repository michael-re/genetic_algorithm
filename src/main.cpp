#include <string>
#include <iostream>

#include "sudoku_population.hpp"
#include "genetic_algorithm.hpp"

auto main(int argc, char* argv[]) -> int
{
    if (argc != 3)
    {
        std::cout << "usage: " << argv[0] << "<population size> <max generation>" << std::endl;
        return EXIT_FAILURE;
    }

    const auto cull = 0.90f;                // percent to cull during each iteration
    const auto size = std::stoi(argv[1]);   // population size
    const auto max  = std::stoi(argv[2]);   // max generations
    GeneticAlgorithm<SudokuPopulation>::run(cull, size, max);
    return EXIT_SUCCESS;
}

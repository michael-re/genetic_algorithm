#pragma once

#ifndef GA_SUDOKU_POPULATION_HPP
#define GA_SUDOKU_POPULATION_HPP

#include "population.hpp"

class SudokuPopulation : public Population
{
public:
    SudokuPopulation(size_t population_size);
    ~SudokuPopulation();

    auto make_source()       -> Population& override;
    auto cull(float percent) -> Population& override;
    auto new_generation()    -> Population& override;

    auto best_fitness()    const -> int override;
    auto best_individual() const -> const individual& override;
    auto source_puzzle()   const -> const individual& override;
};

#endif // !GA_SUDOKU_POPULATION_HPP

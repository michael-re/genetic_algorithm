#pragma once

#ifndef GA_SUDOKU_FITNESS_HPP
#define GA_SUDOKU_FITNESS_HPP

#include "fitness.hpp"
#include "sudoku.hpp"

class SudokuFitness : public Fitness
{
public:
    auto how_fit(const Puzzle* const puzzle) const -> int override;

private:
    static auto row_fitness(const Sudoku& sudoku, int y)        -> int;
    static auto col_fitness(const Sudoku& sudoku, int x)        -> int;
    static auto sub_fitness(const Sudoku& sudoku, int x, int y) -> int;

    template<typename Container>
    static inline auto accumulate(const Container& container) -> int
    {
        auto sum = 0;
        for (const auto &val : container)
            if (val > 1) sum += (val == 2) ? 2 : val * 2; 
        return sum;
    }
};

#endif // !GA_SUDOKU_FITNESS_HPP

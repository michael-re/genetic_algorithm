#pragma once

#ifndef GA_SUDOKU_OFFSPRING_HPP
#define GA_SUDOKU_OFFSPRING_HPP

#include "offspring.hpp"

class SudokuOffspring : public Offspring
{
public:
    auto make_offspring(const Puzzle* const puzzle) const -> Puzzle* override;
};

#endif // !GA_SUDOKU_OFFSPRING_HPP

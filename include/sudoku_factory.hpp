#pragma once

#ifndef GA_SUDOKU_FACTORY_HPP
#define GA_SUDOKU_FACTORY_HPP

#include "puzzle_factory.hpp"

class SudokuFactory : public PuzzleFactory
{
public:
    SudokuFactory();
    ~SudokuFactory();

    auto create_puzzle(std::istream& stream) const -> Puzzle* override;
    auto create_puzzle(Puzzle* puzzle)       const -> Puzzle* override;
};

#endif // !GA_SUDOKU_FACTORY_HPP

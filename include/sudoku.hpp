#pragma once

#ifndef GA_SUDOKU_HPP
#define GA_SUDOKU_HPP

#include <array>
#include <iostream>

#include "puzzle.hpp"

class Sudoku : public Puzzle
{
public:
    struct Cell
    {
        bool deterministic = false;
        int  value         = 0;

        Cell(bool deterministic = false, int value = 0)
            : deterministic(deterministic), value(value) {}
    };

    static constexpr auto subgrid_size = int{3};
    static constexpr auto board_width  = int{9};
    using board = std::array<std::array<Cell, board_width>, board_width>;

public:
    auto cell(int x, int y)       -> Cell&;
    auto cell(int x, int y) const -> const Cell&;

    auto read(std::istream &stream)        -> std::istream& override;
    auto write(std::ostream &stream) const -> std::ostream& override;

private:
    board m_board = {};
};

#endif // !GA_SUDOKU_HPP

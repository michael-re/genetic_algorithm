#pragma once

#ifndef GA_PUZZLE_FACTORY_HPP
#define GA_PUZZLE_FACTORY_HPP

#include "puzzle.hpp"
#include "offspring.hpp"

class PuzzleFactory
{
public:
    virtual ~PuzzleFactory() = default;

    virtual auto create_puzzle(std::istream& stream) const -> Puzzle* = 0;
    virtual auto create_puzzle(Puzzle* puzzle)       const -> Puzzle* = 0;

protected:
    Offspring* m_offspring = nullptr;
};

#endif // !GA_PUZZLE_FACTORY_HPP

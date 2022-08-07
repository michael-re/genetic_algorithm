#pragma once

#ifndef GA_PUZZLE_FACTORY_HPP
#define GA_PUZZLE_FACTORY_HPP

#include "puzzle.hpp"
#include "offspring.hpp"

class PuzzleFactory
{
public:
    explicit PuzzleFactory() = default;
    virtual ~PuzzleFactory() = default;

    PuzzleFactory(PuzzleFactory&& other)      = delete;
    PuzzleFactory(const PuzzleFactory& other) = delete;

    auto operator=(PuzzleFactory&& other)      -> PuzzleFactory& = delete;
    auto operator=(const PuzzleFactory& other) -> PuzzleFactory& = delete;

    virtual auto create_puzzle(std::istream& stream)       const -> Puzzle* = 0;
    virtual auto create_puzzle(const Puzzle* const puzzle) const -> Puzzle* = 0;

protected:
    Offspring* m_offspring = nullptr;
};

#endif // !GA_PUZZLE_FACTORY_HPP

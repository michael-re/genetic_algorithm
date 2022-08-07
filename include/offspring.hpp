#pragma once

#ifndef GA_OFFSPRING_HPP
#define GA_OFFSPRING_HPP

#include "puzzle.hpp"

class Offspring
{
public:
    virtual ~Offspring() = default;
    virtual auto make_offspring(const Puzzle* const puzzle) const -> Puzzle* = 0;
};

#endif // !GA_OFFSPRING_HPP

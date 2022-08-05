#pragma once

#ifndef GA_FITNESS_HPP
#define GA_FITNESS_HPP

#include "puzzle.hpp"

class Fitness
{
public:
    virtual ~Fitness() = default;
    virtual auto how_fit(Puzzle* puzzle) const -> int = 0;
};

#endif // !GA_FITNESS_HPP

#pragma once

#ifndef GA_PUZZLE_HPP
#define GA_PUZZLE_HPP

#include <iostream>

class Puzzle
{
public:
    virtual ~Puzzle() = default;

    virtual auto read(std::istream& stream)        -> std::istream& = 0;
    virtual auto write(std::ostream& stream) const -> std::ostream& = 0;

    friend auto operator>>(std::istream& stream, Puzzle& puzzle)       -> std::istream&;
    friend auto operator<<(std::ostream& stream, const Puzzle& puzzle) -> std::ostream&;
};

#endif // !GA_PUZZLE_HPP

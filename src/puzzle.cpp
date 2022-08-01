#include "puzzle.hpp"

auto operator>>(std::istream& stream, Puzzle& puzzle) -> std::istream&
{
    return puzzle.read(stream);
}

auto operator<<(std::ostream& stream, const Puzzle& puzzle) -> std::ostream&
{
    return puzzle.write(stream);
}

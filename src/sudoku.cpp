#include "sudoku.hpp"

inline constexpr auto as_char (int  val) -> char { return val + '0'; }
inline constexpr auto as_digit(char val) -> int  { return val - '0'; }
inline constexpr auto is_digit(char val) -> int  { return val >= '0' && val <= '9'; }

auto Sudoku::cell(int x, int y) -> Cell&
{
    return m_board[x][y];
}

auto Sudoku::cell(int x, int y) const -> const Cell&
{
    return m_board[x][y];
}

auto Sudoku::read(std::istream &stream) -> std::istream&
{
    m_board = {};
    for (int x = 0; x < board_width; x++)
    {
        for (int y = 0; y < board_width; y++)
        {
            auto value = char{0};
            while (!is_digit(value)) stream >> value;
            m_board[x][y] = {(value != '0'), as_digit(value)};
        }
    }

    return stream;
}

auto Sudoku::write(std::ostream &stream) const -> std::ostream&
{
    static constexpr auto line =  "+-------+-------+-------+\n";

    stream << '\n' << line;
    for (int x = 0; x < board_width; x++)
    {
        stream << '|';

        for (int y = 0; y < board_width; y++)
        {
            const auto val = m_board[x][y].value;
            stream << ' ' << (val ? as_char(val): ' ');
            if ((y % subgrid_size) == 2) stream << " |";
        }

        stream << '\n';
        if ((x % subgrid_size) == 2) stream << line;
    }

    return stream;
}

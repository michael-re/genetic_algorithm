#include "sudoku_fitness.hpp"

auto SudokuFitness::how_fit(Puzzle* puzzle) const -> int
{
    const auto sudoku = dynamic_cast<Sudoku*>(puzzle);
    if (!sudoku) return Fitness::invalid; // invalid puzzle

    auto fitness = Fitness::perfect; // assume we start with solution
    for (int i = 0, x = 0, y = 0; i < Sudoku::board_width; i++, y += Sudoku::subgrid_size)
    {
        if (y && !(y % Sudoku::board_width))
        {
            x += Sudoku::subgrid_size;
            y  = 0;
        }

        fitness += row_fitness(*sudoku, i);
        fitness += col_fitness(*sudoku, i);
        fitness += sub_fitness(*sudoku, x, y);
    }

    return fitness;
}

auto SudokuFitness::row_fitness(const Sudoku& sudoku, int y) -> int
{
    auto row = std::array<int, Sudoku::board_width + 1>{0};
    for (int x = 0; x < Sudoku::board_width; x++)
        row[sudoku.cell(x, y).value]++;
    return accumulate(row);
}

auto SudokuFitness::col_fitness(const Sudoku& sudoku, int x) -> int
{
    auto column = std::array<int, Sudoku::board_width + 1>{0};
    for (int y = 0; y < Sudoku::board_width; y++)
        column[sudoku.cell(x, y).value]++;
    return accumulate(column);
}

auto SudokuFitness::sub_fitness(const Sudoku& sudoku, int origin_x, int origin_y) -> int
{
    auto subgrid = std::array<int, Sudoku::board_width + 1>{0};
    for (int x = origin_x; x < origin_x + Sudoku::subgrid_size; x++)
        for (int y = origin_y; y < origin_y + Sudoku::subgrid_size; y++)
            subgrid[sudoku.cell(x, y).value]++;

    return accumulate(subgrid);
}

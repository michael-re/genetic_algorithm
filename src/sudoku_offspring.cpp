#include <random>
#include <chrono>

#include "sudoku_offspring.hpp"
#include "sudoku.hpp"

using random_engine = std::mt19937_64;
using distribution  = std::uniform_int_distribution<int>;
using chrono_clock  = std::chrono::high_resolution_clock;

auto SudokuOffspring::make_offspring(const Puzzle* const puzzle) const -> Puzzle*
{
    static auto time_seed             = chrono_clock::now().time_since_epoch().count();
    static auto mutation_probability  = std::int32_t{5};
    static auto mutation_generator    = random_engine{static_cast<random_engine::result_type>(time_seed)};
    static auto probability_generator = random_engine{static_cast<random_engine::result_type>(time_seed)};
    static auto random_cell_value     = []() { return distribution(1, Sudoku::board_width)(mutation_generator); };
    static auto random_probability    = []() { return distribution(0, 99)(probability_generator);               };

    auto sudoku    = dynamic_cast<const Sudoku*>(puzzle);
    auto offspring = sudoku ? new Sudoku() : nullptr;
    if (!offspring) return offspring; // return nullptr; - can only make sudoku puzzle offspring

    for (int x = 0; x < Sudoku::board_width; x++)
    {
        for (int y = 0; y < Sudoku::board_width; y++)
        {
            const auto &cell         = sudoku->cell(x, y);
            const auto deterministic = cell.deterministic;
            const auto can_mutate    = (!cell.value || mutation_probability >= random_probability());
            const auto new_value     = (!deterministic && can_mutate) ? random_cell_value() : cell.value;
            offspring->cell(x, y)    = {deterministic, new_value};
        }
    }

    return offspring;
}

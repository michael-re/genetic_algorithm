#include "sudoku_factory.hpp"
#include "sudoku_offspring.hpp"
#include "sudoku.hpp"

SudokuFactory::SudokuFactory()
    : PuzzleFactory()
{
    m_offspring = new SudokuOffspring();
}

SudokuFactory::~SudokuFactory()
{
    delete m_offspring;
    m_offspring = nullptr;
}

auto SudokuFactory::create_puzzle(std::istream& stream) const -> Puzzle*
{
    auto puzzle = (Puzzle*) new Sudoku();
    stream >> *puzzle;
    return puzzle;
}

auto SudokuFactory::create_puzzle(Puzzle* puzzle) const -> Puzzle*
{
    return m_offspring->make_offspring(puzzle);
}

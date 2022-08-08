#include "sudoku_population.hpp"
#include "sudoku_factory.hpp"
#include "sudoku_fitness.hpp"

SudokuPopulation::SudokuPopulation(size_t population_size)
{
    m_size       = population_size;
    m_factory    = new SudokuFactory();
    m_fitness    = new SudokuFitness();
    m_population = {};

    m_population.emplace_back(nullptr, -1);
}

SudokuPopulation::~SudokuPopulation()
{
    delete m_factory;
    m_factory = nullptr;

    delete m_fitness;
    m_fitness = nullptr;
}

auto SudokuPopulation::make_source() -> Population&
{
    return *this;
}

auto SudokuPopulation::cull(float percent) -> Population& 
{
    static_cast<void>(percent);
    return *this;
}

auto SudokuPopulation::new_generation() -> Population& 
{
    return *this;
}

auto SudokuPopulation::best_fitness() const -> int
{
    return m_population.front().fitness();
}

auto SudokuPopulation::best_individual() const -> const individual&
{
    return m_population.front();
}

auto SudokuPopulation::source_puzzle() const -> const individual&
{
    return m_source;
}

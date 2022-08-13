#include <iostream>
#include <algorithm>

#include "sudoku_population.hpp"
#include "sudoku_factory.hpp"
#include "sudoku_fitness.hpp"

SudokuPopulation::SudokuPopulation(size_t population_size)
{
    m_size       = population_size ? population_size : 1;
    m_factory    = new SudokuFactory();
    m_fitness    = new SudokuFitness();
    m_population = {};

    std::cout << "Enter sudoku puzzle: ";
    m_source = individual{m_factory->create_puzzle(std::cin), -1};

    m_population.reserve(m_size);
    for (size_t i = 0; i < m_size; i++)
    {
        auto offspring = m_factory->create_puzzle(m_source.puzzle());
        auto fitness   = m_fitness->how_fit(offspring);
        m_population.push_back({offspring, fitness});
    }

    std::sort(m_population.begin(), m_population.end());
}

SudokuPopulation::~SudokuPopulation()
{
    delete m_factory;
    m_factory = nullptr;

    delete m_fitness;
    m_fitness = nullptr;
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

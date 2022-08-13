#include <iostream>
#include <algorithm>

#include "sudoku_population.hpp"
#include "sudoku_factory.hpp"
#include "sudoku_fitness.hpp"

SudokuPopulation::SudokuPopulation(size_t population_size)
{
    m_size       = population_size ? population_size : 1;
    m_generation = 1;
    m_factory    = new SudokuFactory();
    m_fitness    = new SudokuFitness();
    m_population = {};

    std::cout << "Enter sudoku puzzle: ";
    m_source = individual{m_factory->create_puzzle(std::cin), -1};
    new_generation();
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
    if (percent < 0) percent *= -1;
    if (percent > 1) percent  = 1;

    const auto least_fit_start = m_size - m_size * percent;
    const auto least_fit_begin = m_population.begin() + least_fit_start;
    m_population.erase(least_fit_begin, m_population.end());

    // remove at least 1 puzzle during cull phase
    if (m_population.size() == m_size)
        m_population.pop_back();

    return *this;
}

auto SudokuPopulation::new_generation() -> Population& 
{
    auto old_generation = std::move(m_population);
    if (old_generation.empty()) old_generation.push_back(m_source);

    m_population = {};
    m_population.reserve(m_size);
    while (m_population.size() < m_size)
    {
        for (const auto &puzzle : old_generation)
        {
            auto offspring = m_factory->create_puzzle(puzzle.puzzle());
            auto fitness   = m_fitness->how_fit(offspring);
            m_population.emplace_back(offspring, fitness, m_generation);
        }
    }

    // ensure population remains stable
    while (m_population.size() > m_size)
        m_population.pop_back();

    // sort population from most fit to least fit
    std::sort(m_population.begin(), m_population.end());

    m_generation++;
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

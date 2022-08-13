#include "population.hpp"

Population::Individual::Individual()
    : m_puzzle(nullptr), m_fitness(Fitness::invalid), m_generation(0) {}

Population::Individual::~Individual()
{
    delete m_puzzle;
    m_puzzle = nullptr;
}

Population::Individual::Individual(Individual&& other)
    : Individual()
{
    m_puzzle     = other.m_puzzle;
    m_fitness    = other.m_fitness;
    m_generation = other.m_generation;

    other.m_puzzle = nullptr;
}

Population::Individual::Individual(const Individual& other)
    : Individual()
{
    m_puzzle     = other.m_puzzle ? other.m_puzzle->clone() : nullptr;
    m_fitness    = other.m_fitness;
    m_generation = other.m_generation;
}

Population::Individual::Individual(Puzzle* puzzle, int fitness)
    : m_puzzle(puzzle), m_fitness(fitness) {}

Population::Individual::Individual(Puzzle* puzzle, int fitness, int generation)
    : m_puzzle(puzzle), m_fitness(fitness), m_generation(generation) {}

auto Population::Individual::operator=(Individual&& other) -> Individual&
{
    delete m_puzzle;
    m_puzzle     = other.m_puzzle;
    m_fitness    = other.m_fitness;
    m_generation = other.m_generation;

    other.m_puzzle = nullptr;
    return *this;
}

auto Population::Individual::operator=(const Individual& other) -> Individual&
{
    delete m_puzzle;
    m_puzzle     = other.m_puzzle ? other.m_puzzle->clone() : nullptr;
    m_fitness    = other.m_fitness;
    m_generation = other.m_generation;
    return *this;
}

auto Population::Individual::puzzle() const -> const Puzzle* const&
{
    return m_puzzle;
}

auto Population::Individual::fitness() const -> int
{
    return m_fitness;
}

auto Population::Individual::generation() const -> int
{
    return m_generation;
}

auto Population::Individual::operator<(const Individual& other) const -> bool
{
    return m_fitness < other.m_fitness;
}

auto Population::Individual::operator>(const Individual& other) const -> bool
{
    return m_fitness > other.m_fitness;
}

auto operator<<(std::ostream& stream, const Population::Individual& individual) -> std::ostream&
{
    if (!individual.puzzle()) return stream;

    if (individual.fitness() == Fitness::solution || individual.fitness() == Fitness::invalid)
    {
        return stream << *individual.puzzle();
    }
    else
    {
        return stream << "Fitness:    "   << individual.fitness()
                      << "\nGeneration: " << individual.generation()
                      << *individual.puzzle();
    }
}

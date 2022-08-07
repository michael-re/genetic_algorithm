#include "population.hpp"

Population::Individual::Individual()
    : m_puzzle(nullptr), m_fitness(Fitness::invalid) {}

Population::Individual::~Individual()
{
    delete m_puzzle;
    m_puzzle = nullptr;
}

Population::Individual::Individual(Individual&& other)
    : Individual()
{
    m_puzzle  = other.m_puzzle;
    m_fitness = other.m_fitness;

    other.m_puzzle = nullptr;
}

Population::Individual::Individual(const Individual& other)
    : Individual()
{
    m_puzzle  = other.m_puzzle ? other.m_puzzle->clone() : nullptr;
    m_fitness = other.m_fitness;
}

Population::Individual::Individual(Puzzle* puzzle, int fitness)
    : m_puzzle(puzzle), m_fitness(fitness) {}

auto Population::Individual::operator=(Individual&& other) -> Individual&
{
    delete m_puzzle;
    m_puzzle  = other.m_puzzle;
    m_fitness = other.m_fitness;

    other.m_puzzle = nullptr;
    return *this;
}

auto Population::Individual::operator=(const Individual& other) -> Individual&
{
    delete m_puzzle;
    m_puzzle  = other.m_puzzle ? other.m_puzzle->clone() : nullptr;
    m_fitness = other.m_fitness;
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

auto operator<<(std::ostream& stream, const Population::Individual& individual) -> std::ostream&
{
    if (individual.fitness() == Fitness::perfect || individual.fitness() == Fitness::invalid)
    {
        return stream << *individual.puzzle();
    }
    else
    {
        return stream << "Fitness: " << individual.fitness()
                      << *individual.puzzle();
    }
}

#pragma once

#ifndef GA_POPULATION_HPP
#define GA_POPULATION_HPP

#include <vector>

#include "puzzle.hpp"
#include "fitness.hpp"
#include "puzzle_factory.hpp"

class Population
{
public:
    struct Individual
    {
        Puzzle* puzzle  = nullptr;
        int     fitness = Fitness::invalid;

        Individual(Puzzle* puzzle = nullptr, int fitness = -1)
            : puzzle(puzzle), fitness(fitness) {}
    };

    using size_t      = std::size_t;
    using factory     = PuzzleFactory;
    using fitness     = Fitness;
    using individual  = Individual;
    using population  = std::vector<individual>;

public:
    explicit Population() = default;
    virtual ~Population() = default;

    Population(Population&& other)      = delete;
    Population(const Population& other) = delete;

    auto operator=(Population&& other)      -> Population& = delete;
    auto operator=(const Population& other) -> Population& = delete;

    virtual auto cull(float percent) -> Population& = 0;
    virtual auto new_generation()    -> Population& = 0;

    virtual auto best_fitness() const -> int = 0;
    virtual auto best_individual() const -> const individual& = 0;

protected:
    size_t     m_size       = 0;
    factory*   m_factory    = nullptr;
    fitness*   m_fitness    = nullptr;
    individual m_source     = {};
    population m_population = {};
};

#endif // !GA_POPULATION_HPP

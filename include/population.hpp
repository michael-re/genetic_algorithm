#pragma once

#ifndef GA_POPULATION_HPP
#define GA_POPULATION_HPP

#include <vector>
#include <iostream>

#include "puzzle.hpp"
#include "fitness.hpp"
#include "puzzle_factory.hpp"

class Population
{
public:
    class Individual
    {
    public:
        Individual();
        ~Individual();

        Individual(Individual&& other);
        Individual(const Individual& other);

        Individual(Puzzle* puzzle, int fitness);
        Individual(Puzzle* puzzle, int fitness, int generation);

        auto operator=(Individual&& other)      -> Individual&;
        auto operator=(const Individual& other) -> Individual&;

        auto operator<(const Individual& other) const -> bool;
        auto operator>(const Individual& other) const -> bool;

        auto puzzle()     const -> const Puzzle* const&;
        auto fitness()    const -> int;
        auto generation() const -> int;

        friend auto operator<<(std::ostream& stream, const Individual& individual) -> std::ostream&;

    private:
        Puzzle* m_puzzle     = nullptr;
        int     m_fitness    = Fitness::invalid;
        int     m_generation = 0;
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

    virtual auto best_fitness()    const -> int = 0;
    virtual auto best_individual() const -> const individual& = 0;
    virtual auto source_puzzle()   const -> const individual& = 0;

protected:
    size_t     m_size       = 0;
    size_t     m_generation = 0;
    factory*   m_factory    = nullptr;
    fitness*   m_fitness    = nullptr;
    individual m_source     = {};
    population m_population = {};
};

#endif // !GA_POPULATION_HPP

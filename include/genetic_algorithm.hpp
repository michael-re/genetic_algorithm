#pragma once

#ifndef GA_GENETIC_ALGORITHM_HPP
#define GA_GENETIC_ALGORITHM_HPP

#include <limits>
#include <utility>
#include <iostream>

#include "population.hpp"

template<typename T>
class GeneticAlgorithm
{
public:
    static_assert(std::is_base_of<Population, T>::value, "T must be derived from Population.");
    using individual = Population::Individual;
    using result     = std::pair<individual, individual>;

public:
    static inline auto run(float percent, int population_size, int max_generation) -> void
    {
        auto result = run_iteration(percent, population_size, max_generation);

        std::cout << "\n=== source puzzle ====\n";
        std::cout << result.second << std::endl;

        if (result.first.fitness() == Fitness::solution)
            std::cout << "\n=== solution found ===\n";
        else
            std::cout << "\n=== solution NOT found ===\n";

        std::cout << result.first << std::endl;
    }

private:
    static inline auto run_iteration(float percent, int population_size, int max_generation) -> result
    {
        auto population = (Population*) new T(population_size);
        auto best       = individual{nullptr, std::numeric_limits<int>::max()};

        for (int i = 0; i < max_generation; i++)
        {
            const auto &new_best = population->cull(percent)
                                              .new_generation()
                                              .best_individual();
            if (new_best.fitness() < best.fitness()) best = new_best;
            if (best.fitness() == Fitness::solution) break;
        }

        auto result = GeneticAlgorithm::result{best, population->source_puzzle()};
        delete population;
        return result;
    }
};

#endif // !GA_GENETIC_ALGORITHM_HPP

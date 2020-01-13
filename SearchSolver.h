//
// Created by giladby on 13/01/2020.
//

#ifndef ADVANCED_PROGRAMMING_EX4_SEARCHSOLVER_H
#define ADVANCED_PROGRAMMING_EX4_SEARCHSOLVER_H

#include "Solver.h"
#include "Searchable.h"

template <class Solution>
class SearchSolver : public Solver<Searchable*, Solution> {
public:
    Solution solve(Searchable* searchable) {
        Solution s;
        return s;
    }
};


#endif //ADVANCED_PROGRAMMING_EX4_SEARCHSOLVER_H

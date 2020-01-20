//
// Created by giladby on 13/01/2020.
//

#ifndef ADVANCED_PROGRAMMING_EX4_SEARCHSOLVER_H
#define ADVANCED_PROGRAMMING_EX4_SEARCHSOLVER_H

#include "Solver.h"
#include "Node.h"
#include "Searchables/Searchable.h"
#include "Searchers/Searcher.h"
#include "State.h"
#include <vector>
#include <iostream>

using namespace std;

/**
 * SearchSolver class
 */
template <class T>
class SearchSolver : public Solver<Searchable<T>*, vector<State<Node*>*>> {
private:
    Searcher<T>* searcher;
public:
    SearchSolver(Searcher<T>* inputSearcher) {
        this->searcher = inputSearcher;
    }

    //a method for creating deep clone of the object
    Solver<Searchable<T>*, vector<State<Node*>*>>* getClone() {
        return new SearchSolver<T> (this->searcher->getClone());
    }

    vector<State<Node*>*> solve(Searchable<Node*>* searchable) {
        vector<State<Node*>*> result = this->searcher->search(searchable);
        return result;
    }
};


#endif //ADVANCED_PROGRAMMING_EX4_SEARCHSOLVER_H

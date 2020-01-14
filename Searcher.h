//
// Created by yuvalkit on 14/01/2020.
//

#ifndef ADVANCED_PROGRAMMING_EX4_SEARCHER_H
#define ADVANCED_PROGRAMMING_EX4_SEARCHER_H

#include "Searchable.h"
#include "State.h"

using namespace std;

template <class T>
class Searcher {
protected:
    int nodesEvaluated;
public:
    virtual vector<State<T>*> search(Searchable<T>* searchable) = 0;
    virtual int getNumberOfNodesEvaluated() = 0;
};


#endif //ADVANCED_PROGRAMMING_EX4_SEARCHER_H
//
// Created by giladby on 10/01/2020.
//

#ifndef ADVANCED_PROGRAMMING_EX4_SEARCHABLE_H
#define ADVANCED_PROGRAMMING_EX4_SEARCHABLE_H

#include <string>
#include <list>
#include "State.h"

using namespace std;

template <class T>
class Searchable {
    list<State<T>*> goalStates;
public:
    virtual string getString() = 0;
    bool isGoalState(State<T> )
};

#endif //ADVANCED_PROGRAMMING_EX4_SEARCHABLE_H

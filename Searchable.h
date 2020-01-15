//
// Created by giladby on 10/01/2020.
//

#ifndef ADVANCED_PROGRAMMING_EX4_SEARCHABLE_H
#define ADVANCED_PROGRAMMING_EX4_SEARCHABLE_H

#include <string>
#include <vector>
#include "State.h"

using namespace std;

template <class T>
class Searchable {
protected:
    vector<State<T>*> goalStates;
    State<T>* initialState;
public:
    virtual string getString() = 0;
    virtual bool isGoalState(State<T>* state) = 0;
    virtual State<T>* getGoalState() = 0;
    virtual State<T>* getInitialState() = 0;
    virtual vector<State<T>*> getAllPossibleStates(State<T>* state) = 0;
};

#endif //ADVANCED_PROGRAMMING_EX4_SEARCHABLE_H

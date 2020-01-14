//
// Created by giladby on 14/01/2020.
//

#ifndef ADVANCED_PROGRAMMING_EX4_STATECOMPARATOR_H
#define ADVANCED_PROGRAMMING_EX4_STATECOMPARATOR_H

#include "State.h"

template <class T>
class StateComparator {
public:
    int operator() (State<T>* s1, State<T>* s2) {
        return s1->getSum() > s2->getSum();
    }
};


#endif //ADVANCED_PROGRAMMING_EX4_STATECOMPARATOR_H


#ifndef ADVANCED_PROGRAMMING_EX4_STATECOMPARATOR_H
#define ADVANCED_PROGRAMMING_EX4_STATECOMPARATOR_H

#include "State.h"

/**
 * StateComparator class
 */
template <class T>
class StateComparator {
public:
    // compare between 2 states by comparing theirs 'getSum' data
    int operator() (State<T>* s1, State<T>* s2) {
        return s1->getSum() > s2->getSum();
    }
};


#endif //ADVANCED_PROGRAMMING_EX4_STATECOMPARATOR_H

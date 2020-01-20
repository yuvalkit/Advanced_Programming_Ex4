
#ifndef ADVANCED_PROGRAMMING_EX4_SEARCHABLE_H
#define ADVANCED_PROGRAMMING_EX4_SEARCHABLE_H

#include <string>
#include <vector>
#include "../Components/State.h"

using namespace std;

/**
 * Searchable interface
 */
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
    virtual Searchable<T>* getClone() = 0;
    virtual ~Searchable() {}
};

#endif //ADVANCED_PROGRAMMING_EX4_SEARCHABLE_H

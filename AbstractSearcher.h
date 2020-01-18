//
// Created by giladby on 14/01/2020.
//

#ifndef ADVANCED_PROGRAMMING_EX4_ABSTRACTSEARCHER_H
#define ADVANCED_PROGRAMMING_EX4_ABSTRACTSEARCHER_H

#include "Searcher.h"
#include <queue>
#include "StateComparator.h"
#include <set>
#include <vector>

/**
 * AbstractSearcher class
 * This class is used for sharing code for the different implements of the searcher interface.
 */
template <class T>
class AbstractSearcher : public Searcher<T> {
protected:
    set<State<T>*> closed;
    priority_queue<State<T>*, vector<State<T>*>, StateComparator<T>> open;
public:

    AbstractSearcher() {
        this->nodesEvaluated = 0;
    }

    //get the number of elements the algorithm visited in.
    int getNumberOfNodesEvaluated() {
        int result = this->nodesEvaluated;
        this->nodesEvaluated = 0;
        return result;
    }

    // return the top element in the minimum priority queue, remove it, and re-organized the priority queue
    State<T>* popOpen() {
        this->nodesEvaluated++;
        State<T>* state = this->open.top();
        this->open.pop();
        return state;
    }

    // get the trace from the end state to the first
    vector<State<T>*> getBackTrace(State<T>* state) {
        vector<State<T>*> result;
        result.emplace_back(state);
        // add to the result vector the current state and move the state that the current state came from
        while (state->getCameFrom() != NULL) {
            state = state->getCameFrom();
            result.emplace_back(state);
        }
        return result;
    }

    //check if the priority queue contains the given state
    bool isOpenContains(State<T>* state) {
        vector<State<T>*> copy;
        bool isContain = false;
        //make a copy of the priority queue
        while(!this->open.empty()) {
            copy.emplace_back(this->open.top());
            this->open.pop();
        }
        for (State<T>* s : copy) {
            this->open.push(s);
            if(s->isEqual(state)) {
                isContain = true;
            }
        }
        return isContain;
    }
};


#endif //ADVANCED_PROGRAMMING_EX4_ABSTRACTSEARCHER_H

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

template <class T>
class AbstractSearcher : public Searcher<T> {
protected:
    set<State<T>*> closed;
    priority_queue<State<T>*, vector<State<T>*>, StateComparator<T>> open;
public:

    AbstractSearcher() {
        this->nodesEvaluated = 0;
    }

    int getNumberOfNodesEvaluated() {
        return this->nodesEvaluated;
    }


    State<T>* popOpen() {
        this->nodesEvaluated++;
        State<T>* state = this->open.top();
        this->open.pop();
        return state;
    }

    vector<State<T>*> getBackTrace(State<T>* state) {
        vector<State<T>*> result;
        result.emplace_back(state);
        while (state->getCameFrom() != NULL) {
            state = state->getCameFrom();
            result.emplace_back(state);
        }
        return result;
    }

    bool isOpenContains(State<T>* state) {
        vector<State<T>*> copy;
        bool isContain = false;
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

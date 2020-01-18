//
// Created by yuvalkit on 14/01/2020.
//

#ifndef ADVANCED_PROGRAMMING_EX4_DEPTHFIRSTSEARCH_H
#define ADVANCED_PROGRAMMING_EX4_DEPTHFIRSTSEARCH_H

#include "AbstractSearcher.h"
#include "State.h"

template <class T>
class DepthFirstSearch : public AbstractSearcher<T> {
public:
    DepthFirstSearch() : AbstractSearcher<T>() {}

    //a method for creating deep clone of the object
    Searcher<T>* getClone() {
        return new DepthFirstSearch<T>();
    }

    vector<State<T>*> search(Searchable<T>* searchable) {
        vector<State<T>*> successors;
        State<T>* n;
        n = searchable->getInitialState();
        this->open.push(n);
        while (!this->open.empty()) {
            n = this->popOpen();
            if(searchable->isGoalState(n)) {
                return this->getBackTrace(n);
            }
            if (n->getColor() == 'W') {
                n->setColor('B');
                successors = searchable->getAllPossibleStates(n);
                for (State<T>* s : successors) {
                    if (s->getColor() == 'W') {
                        s->setCameFrom(n);
                        this->open.push(s);
                    }
                }
            }
        }
    }
};



#endif //ADVANCED_PROGRAMMING_EX4_DEPTHFIRSTSEARCH_H

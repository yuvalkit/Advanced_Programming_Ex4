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
    vector<State<T>*> search(Searchable<T>* searchable) {
//        State<T>* n;
//        n = searchable->getInitialState();
//        return this->DFS(searchable, n);

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

//    vector<State<T>*> DFS(Searchable<T>* searchable, State<T>* state) {
//        if (searchable->isGoalState(state)) {
//            return this->getBackTrace(state);
//        }
//        state->setColor('G');
//        vector<State<T>*> result;
//        vector<State<T>*> successors;
//        successors = searchable->getAllPossibleStates(state);
//        for (State<T>* s : successors) {
//            if (s->getColor() == 'W') {
//                s->setCameFrom(state);
//                result = this->DFS(searchable, s);
//            }
//        }
//        state->setColor('B');
//        return result;
//    }
};



#endif //ADVANCED_PROGRAMMING_EX4_DEPTHFIRSTSEARCH_H

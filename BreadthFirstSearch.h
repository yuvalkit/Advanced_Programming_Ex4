//
// Created by giladby on 14/01/2020.
//

#ifndef ADVANCED_PROGRAMMING_EX4_BREADTHFIRSTSEARCH_H
#define ADVANCED_PROGRAMMING_EX4_BREADTHFIRSTSEARCH_H

#include "AbstractSearcher.h"

template <class T>
class BreadthFirstSearch : public AbstractSearcher<T>{
public:
    BreadthFirstSearch() : AbstractSearcher<T>() {}

    //a method for creating deep clone of the object
    Searcher<T>* getClone() {
        return new BreadthFirstSearch<T>();
    }

    vector<State<T>*> search(Searchable<T>* searchable) {
        vector<State<T>*> successors;
        State<T>* n;
        n = searchable->getInitialState();
        this->open.push(n);
        n->setColor('G');
        while (this->open.size() != 0) {
            n = this->popOpen();
            if(searchable->isGoalState(n)) {
                return this->getBackTrace(n);
            }
            successors = searchable->getAllPossibleStates(n);
            for (State<T>* s : successors) {
                if(s->getColor() == 'W') {
                    s->setColor('G');
                    s->setSum(n->getSum() + 1);
                    s->setCameFrom(n);
                    this->open.push(s);
                }
            }
            n->setColor('B');
        }
    }
};


#endif //ADVANCED_PROGRAMMING_EX4_BREADTHFIRSTSEARCH_H

//
// Created by giladby on 14/01/2020.
//

#ifndef ADVANCED_PROGRAMMING_EX4_BESTFIRSTSEARCH_H
#define ADVANCED_PROGRAMMING_EX4_BESTFIRSTSEARCH_H

#include "AbstractSearcher.h"

template <class T>
class BestFirstSearch : public AbstractSearcher<T> {
private:

public:
    BestFirstSearch() : AbstractSearcher<T>() {}
    vector<State<T>*> search(Searchable<T>* searchable) {
        vector<State<T>*> successors;
        State<T>* n;
        this->open.push(searchable->getInitialState());
        while (this->open.size() != 0) {
            n = this->popOpen();
            this->closed.insert(n);
            if(searchable->isGoalState(n)) {
                return this->getBackTrace();
            }
            successors = searchable->getAllPossibleStates(n);
            for (State<T>* s : successors) {
                if(this->closed.find(s) == this->closed.end() && !this->isOpenContains(s)) {
                    s->setSum(s->getState()->getCost() + n->getSum());
                    this->open.push(s);
                } else if(s->getSum() > s->getState()->getCost() + n->getSum()) {
                    s->setSum(s->getState()->getCost() + n->getSum());
                    if(!this->isOpenContains(s)) {
                        this->open.push(s);
                    }
                }
            }
        }
    }
};


#endif //ADVANCED_PROGRAMMING_EX4_BESTFIRSTSEARCH_H

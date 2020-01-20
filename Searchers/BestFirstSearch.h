
#ifndef ADVANCED_PROGRAMMING_EX4_BESTFIRSTSEARCH_H
#define ADVANCED_PROGRAMMING_EX4_BESTFIRSTSEARCH_H

#include "AbstractSearcher.h"

/**
 * BestFirstSearch class
 */
template <class T>
class BestFirstSearch : public AbstractSearcher<T> {
public:
    BestFirstSearch() : AbstractSearcher<T>() {}

    //a method for creating deep clone of the object
    Searcher<T>* getClone() {
        return new BestFirstSearch<T>();
    }

    // the BestFirstSearch algorithm for finding the shortest path form the starting state to a goal state
    vector<State<T>*> search(Searchable<T>* searchable) {
        vector<State<T>*> successors;
        // get the starting state
        State<T>* n = searchable->getInitialState();
        this->open.push(n);
        //set the cumulative cost to reach the starting state as it's cost
        n->setSum(n->getState()->getCost());
        while (this->open.size() != 0) {
            n = this->popOpen();
            this->closed.insert(n);
            if(searchable->isGoalState(n)) {
                return this->getBackTrace(n);
            }
            successors = searchable->getAllPossibleStates(n);
            for (State<T>* s : successors) {
                // check if the path, which starts form the stating state to the current neighbor,
                // through the current n node, is an upgrade path
                // in case that the tested neighbor isn't contained in the 'open' set - add it.
                if(this->closed.find(s) == this->closed.end() && !this->isOpenContains(s)) {
                    s->setCameFrom(n);
                    s->setSum(s->getState()->getCost() + n->getSum());
                    this->open.push(s);
                } else if(s->getSum() > s->getState()->getCost() + n->getSum()) {
                    s->setCameFrom(n);
                    s->setSum(s->getState()->getCost() + n->getSum());
                    if(!this->isOpenContains(s)) {
                        this->open.push(s);
                    }
                }
            }
        }
        cerr << "error: cannot get the goal state" << endl;
        exit(1);
    }
};


#endif //ADVANCED_PROGRAMMING_EX4_BESTFIRSTSEARCH_H

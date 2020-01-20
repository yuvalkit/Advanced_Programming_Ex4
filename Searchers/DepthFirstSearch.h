
#ifndef ADVANCED_PROGRAMMING_EX4_DEPTHFIRSTSEARCH_H
#define ADVANCED_PROGRAMMING_EX4_DEPTHFIRSTSEARCH_H

#include "AbstractSearcher.h"
#include "../Components/State.h"

/**
 * DepthFirstSearch class
 */
template <class T>
class DepthFirstSearch : public AbstractSearcher<T> {
public:
    DepthFirstSearch() : AbstractSearcher<T>() {}

    //a method for creating deep clone of the object
    Searcher<T>* getClone() {
        return new DepthFirstSearch<T>();
    }

    // the DepthFirstSearch algorithm for finding path form the starting state to a goal state by depth searching
    vector<State<T>*> search(Searchable<T>* searchable) {
        vector<State<T>*> successors;
        State<T>* n;
        n = searchable->getInitialState();
        this->open.push(n);
        while (!this->open.empty()) {
            n = this->popOpen();
            // get the starting state
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
        cerr << "error: cannot get the goal state" << endl;
        exit(1);
    }
};



#endif //ADVANCED_PROGRAMMING_EX4_DEPTHFIRSTSEARCH_H

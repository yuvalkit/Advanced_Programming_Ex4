
#ifndef ADVANCED_PROGRAMMING_EX4_BREADTHFIRSTSEARCH_H
#define ADVANCED_PROGRAMMING_EX4_BREADTHFIRSTSEARCH_H

#include "AbstractSearcher.h"

/**
 * BreadthFirstSearch class
 */
template <class T>
class BreadthFirstSearch : public AbstractSearcher<T>{
public:
    BreadthFirstSearch() : AbstractSearcher<T>() {}

    //a method for creating deep clone of the object
    Searcher<T>* getClone() {
        return new BreadthFirstSearch<T>();
    }

    // the BreadthFirstSearch algorithm for finding path form the starting state to a goal state by breadth searching
    vector<State<T>*> search(Searchable<T>* searchable) {
        vector<State<T>*> successors;
        State<T>* n;
        // get the starting state
        n = searchable->getInitialState();
        this->open.push(n);
        // color the state in gray color
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
        // there is no path to goal
        vector<State<T>*> emptyVector;
        return emptyVector;
    }
};


#endif //ADVANCED_PROGRAMMING_EX4_BREADTHFIRSTSEARCH_H

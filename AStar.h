//
// Created by giladby on 14/01/2020.
//

#ifndef ADVANCED_PROGRAMMING_EX4_ASTAR_H
#define ADVANCED_PROGRAMMING_EX4_ASTAR_H

#include "AbstractSearcher.h"
#include "Utils.h"
#include <unordered_map>
#include <limits>

template <class T>
class Wrap {
    State<T>* state;
    double distance;
public:
    Wrap(State<T>* inputState) {
        this->state = inputState;
        this->distance = numeric_limits<int>::max();
    }
    double getDistance() {
        return this->distance;
    }
    void setDistance(double newVal) {
        this->distance = newVal;
    }
};

template <class T>
class AStar : public AbstractSearcher<T> {
    unordered_map<State<T>*, Wrap<T>*> stateToWrap;
public:
    vector<State<T>*> search(Searchable<T>* searchable) {
        vector<State<T>*> successors;
        int x1, y1, x2, y2;
        double tentativeScore, distance;
        State<T>* n = searchable->getInitialState();
        this->open.push(n);
        Wrap<T>* w = new Wrap<T>(n);
        this->stateToWrap[n] = w;
        w->setDistance(n->getState()->getCost());
        n->setSum(n->getState()->getCost());
        while (this->open.size() != 0) {
            n = this->popOpen();
            if(searchable->isGoalState(n)) {
                return this->getBackTrace(n);
            }
            successors = searchable->getAllPossibleStates(n);
            for (State<T>* s : successors) {
                if(this->stateToWrap.find(s) == this->stateToWrap.end()) {
                    w = new Wrap<T>(s);
                    this->stateToWrap[s] = w;
                }
                tentativeScore = s->getState()->getCost() + this->stateToWrap[n]->getDistance();
                if(this->stateToWrap[s]->getDistance() > tentativeScore) {
                    s->setCameFrom(n);
                    this->stateToWrap[s]->setDistance(tentativeScore);
                    x1 = n->getState()->getI();
                    y1 = n->getState()->getJ();
                    x2 = n->getState()->getI();
                    y2 = n->getState()->getJ();
                    distance = Utils::getDistance(x1, y1 , x2, y2);
                    s->setSum(this->stateToWrap[s]->getDistance() + distance);
                    if(!this->isOpenContains(s)) {
                        this->open.push(s);
                    }
                }
            }
        }
    }
};


#endif //ADVANCED_PROGRAMMING_EX4_ASTAR_H

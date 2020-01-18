//
// Created by giladby on 14/01/2020.
//

#ifndef ADVANCED_PROGRAMMING_EX4_ASTAR_H
#define ADVANCED_PROGRAMMING_EX4_ASTAR_H

#include "AbstractSearcher.h"
#include "Utils.h"
#include <unordered_map>
#include <limits>

/**
 * Wrap class
 * This class wraps state object, for supply extra information for them.
 */
template <class T>
class Wrap {
    State<T>* state;
    double distance;
public:
    Wrap(State<T>* inputState) {
        this->state = inputState;
        this->distance = numeric_limits<int>::max();
    }
    // get the minimum distance from the start state (the gScore)
    double getDistance() {
        return this->distance;
    }
    // set the minimum distance from the start state (the gScore)
    void setDistance(double newVal) {
        this->distance = newVal;
    }
};

/**
 * AStar class
 */
template <class T>
class AStar : public AbstractSearcher<T> {
    // this map is used for mapping for a state object to the the object wraps it
    unordered_map<State<T>*, Wrap<T>*> stateToWrap;

    // get the H function (the heuristics function) for a given state.
    // the function is computing the absolute distance between the current state and the goal state
    double getH(State<T>* s1, State<T>* s2) {
        int x1 = s1->getState()->getI();
        int y1 = s1->getState()->getJ();
        int x2 = s2->getState()->getI();
        int y2 = s2->getState()->getJ();
        return Utils::getDistance(x1, y1 , x2, y2);
    }
public:
    AStar() : AbstractSearcher<T>() {}

    //a method for creating deep clone of the object
    Searcher<T>* getClone() {
        return new AStar<T>();
    }

    // the a star algorithm for finding the shortest path form the starting state to a goal state
    vector<State<T>*> search(Searchable<T>* searchable) {
        vector<State<T>*> successors;
        int x1, y1, x2, y2;
        double tentativeScore, distance;
        // get the starting state
        State<T>* n = searchable->getInitialState();
        // get a goal state
        State<T>* goal = searchable->getGoalState();
        this->open.push(n);
        Wrap<T>* w = new Wrap<T>(n);
        this->stateToWrap[n] = w;
        w->setDistance(n->getState()->getCost());
        n->setSum(this->stateToWrap[n]->getDistance() + this->getH(n, goal, searchable));
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
                tentativeScore = this->stateToWrap[n]->getDistance() + s->getState()->getCost();
                if(this->stateToWrap[s]->getDistance() > tentativeScore) {
                    s->setCameFrom(n);
                    this->stateToWrap[s]->setDistance(tentativeScore);
                    s->setSum(this->stateToWrap[s]->getDistance() + this->getH(s, goal, searchable));
                    if(!this->isOpenContains(s)) {
                        this->open.push(s);
                    }
                }
            }
        }
    }
};


#endif //ADVANCED_PROGRAMMING_EX4_ASTAR_H

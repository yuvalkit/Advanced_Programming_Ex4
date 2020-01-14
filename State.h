//
// Created by yuvalkit on 14/01/2020.
//

#ifndef ADVANCED_PROGRAMMING_EX4_STATE_H
#define ADVANCED_PROGRAMMING_EX4_STATE_H

template <class T>
class State {
    T state;
    int sum;
    State<T>* cameFrom;
public:
    State<T>(T inputState, int inputSum, State<T>* inputCameFrom) {
        this->state = inputState;
        this->cameFrom = inputCameFrom;
        this->sum = inputSum;
    }
    T getState() {
        return this->state;
    }
    bool isEqual(State<T>* state) {
        return this->state->isEqual(state->getState());
    }
    void setSum(int inputSum) {
        this->sum = inputSum;
    }
    int getSum() {
        return this->sum;
    }
    State<T>* getCameFrom() {
        return this->cameFrom;
    }
    void setCameFrom(State<T>* newCameFrom) {
        this->cameFrom = newCameFrom;
    }
};


#endif //ADVANCED_PROGRAMMING_EX4_STATE_H

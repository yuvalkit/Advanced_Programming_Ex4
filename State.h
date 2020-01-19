//
// Created by yuvalkit on 14/01/2020.
//

#ifndef ADVANCED_PROGRAMMING_EX4_STATE_H
#define ADVANCED_PROGRAMMING_EX4_STATE_H

/**
 * State class
 */
template <class T>
class State {
    T state;
    int sum;
    State<T>* cameFrom;
    char color;
public:
    State<T>(T inputState) {
        this->state = inputState;
        this->cameFrom = NULL;
        this->sum = 0;
        this->color = 'W';
    }

    T getState() {
        return this->state;
    }

    //check if the current state is equal to the given state
    bool isEqual(State<T>* other) {
        return this->state->isEqual(other->getState());
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

    char getColor() {
        return this->color;
    }

    void setColor(char c) {
        this->color = c;
    }
};


#endif //ADVANCED_PROGRAMMING_EX4_STATE_H

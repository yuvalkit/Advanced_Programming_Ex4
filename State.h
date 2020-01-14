//
// Created by yuvalkit on 14/01/2020.
//

#ifndef ADVANCED_PROGRAMMING_EX4_STATE_H
#define ADVANCED_PROGRAMMING_EX4_STATE_H

template <class T>
class State {
    T state;
public:
    State<T>(T inputState) {
        this->state = inputState;
    }
};


#endif //ADVANCED_PROGRAMMING_EX4_STATE_H

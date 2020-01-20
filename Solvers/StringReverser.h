
#ifndef ADVANCED_PROGRAMMING_EX4_STRINGREVERSER_H
#define ADVANCED_PROGRAMMING_EX4_STRINGREVERSER_H

#include <string>
#include "Solver.h"

using namespace std;

/**
 * StringReverser class
 */
class StringReverser : public Solver<string, string> {
    string solve(string problem);
    Solver<string, string>* getClone();
};


#endif //ADVANCED_PROGRAMMING_EX4_STRINGREVERSER_H

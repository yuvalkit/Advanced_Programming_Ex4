
#include <algorithm>
#include "StringReverser.h"

string StringReverser::solve(string problem) {
    reverse(problem.begin(), problem.end());
    return problem;
}

//a method for creating deep clone of the object
Solver<string, string>* StringReverser::getClone() {
    return new StringReverser();
}
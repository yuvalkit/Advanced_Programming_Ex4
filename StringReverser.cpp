//
// Created by yuvalkit on 10/01/2020.
//

#include <algorithm>
#include "StringReverser.h"

string StringReverser::solve(string problem) {
    reverse(problem.begin(), problem.end());
    return problem;
}
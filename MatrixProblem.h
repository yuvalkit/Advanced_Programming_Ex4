//
// Created by giladby on 10/01/2020.
//

#ifndef ADVANCED_PROGRAMMING_EX4_MATRIXPROBLEM_H
#define ADVANCED_PROGRAMMING_EX4_MATRIXPROBLEM_H

#include "Searchable.h"
#include <string>

using namespace std;

class MatrixProblem : public Searchable {
    string problem;
public:
    MatrixProblem(string inputProblem);
};


#endif //ADVANCED_PROGRAMMING_EX4_MATRIXPROBLEM_H

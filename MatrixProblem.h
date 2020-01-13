//
// Created by giladby on 10/01/2020.
//

#ifndef ADVANCED_PROGRAMMING_EX4_MATRIXPROBLEM_H
#define ADVANCED_PROGRAMMING_EX4_MATRIXPROBLEM_H

#include "Searchable.h"
#include <string>
#include <vector>

using namespace std;

class MatrixProblem : public Searchable {
    vector<string> problem;
    string problemString;
    string makeProblemString();

public:
    MatrixProblem(vector<string> inputProblem);
    static string getString(MatrixProblem problem);
    string getProblemString();
};


#endif //ADVANCED_PROGRAMMING_EX4_MATRIXPROBLEM_H

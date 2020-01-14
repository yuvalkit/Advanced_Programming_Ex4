//
// Created by giladby on 10/01/2020.
//

#ifndef ADVANCED_PROGRAMMING_EX4_MATRIXPROBLEM_H
#define ADVANCED_PROGRAMMING_EX4_MATRIXPROBLEM_H

#include "Searchable.h"
#include <string>
#include <vector>
#include "Node.h"

using namespace std;

class MatrixProblem : public Searchable {
    vector<string> problem;
    string problemString;
    string makeProblemString();
    vector<vector<Node*>> matrix;
public:
    MatrixProblem(vector<string> inputProblem);
    string getString();
};


#endif //ADVANCED_PROGRAMMING_EX4_MATRIXPROBLEM_H

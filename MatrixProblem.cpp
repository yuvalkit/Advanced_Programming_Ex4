//
// Created by giladby on 10/01/2020.
//

#include "MatrixProblem.h"

MatrixProblem::MatrixProblem(vector<string> inputProblem) {
    this->problem = inputProblem;
    this->problemString = this->makeProblemString();
}

string MatrixProblem::makeProblemString() {
    string str = "";
    for (int i = 0; i < this->problem.size(); i++) {
        str += this->problem[i];
        if (i != this->problem.size() - 1) {
            str += "$";
        }
    }
    return str;
}

string MatrixProblem::getProblemString() {
    return this->problemString;
}

string MatrixProblem::getString(MatrixProblem problem) {
    hash<string> hasher;
    auto hashed = hasher(problem.getProblemString());
    return to_string(hashed);
}
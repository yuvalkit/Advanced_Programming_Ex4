//
// Created by giladby on 10/01/2020.
//

#ifndef ADVANCED_PROGRAMMING_EX4_MATRIXPROBLEM_H
#define ADVANCED_PROGRAMMING_EX4_MATRIXPROBLEM_H

#include "Searchable.h"
#include <string>
#include <vector>
#include "Node.h"
#include "State.h"

using namespace std;

class MatrixProblem : public Searchable<Node*> {
    vector<string> problemVector;
    string problemString;
    int rows;
    int cols;
    State<Node*>*** matrix;
    string makeProblemString();
    void initMatrix();
public:
    MatrixProblem(vector<string> inputProblem);
    string getString();
    bool isGoalState(State<Node*>* state);
    State<Node*>* getGoalState();
    State<Node*>* getInitialState();
    vector<State<Node*>*> getAllPossibleStates(State<Node*>* state);
    void makeMatrix();
    void printMatrix();
    static string getPath(vector<State<Node*>*> statesVector);
};


#endif //ADVANCED_PROGRAMMING_EX4_MATRIXPROBLEM_H

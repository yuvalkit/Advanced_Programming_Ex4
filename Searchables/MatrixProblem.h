
#ifndef ADVANCED_PROGRAMMING_EX4_MATRIXPROBLEM_H
#define ADVANCED_PROGRAMMING_EX4_MATRIXPROBLEM_H

#include "Searchable.h"
#include <string>
#include <vector>
#include "../Components/Node.h"
#include "../Components/State.h"

using namespace std;

/**
 * MatrixProblem class
 */
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
    Searchable<Node*>* getClone();
};


#endif //ADVANCED_PROGRAMMING_EX4_MATRIXPROBLEM_H

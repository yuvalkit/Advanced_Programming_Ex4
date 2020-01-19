//
// Created by giladby on 10/01/2020.
//

#include "MatrixProblem.h"
#include "Utils.h"
#include <limits>

MatrixProblem::MatrixProblem(vector<string> inputProblem) {
    this->problemVector = inputProblem;
    this->problemString = this->makeProblemString();
    this->makeMatrix();
}

//a method for creating deep clone of the object
Searchable<Node *> * MatrixProblem::getClone() {
    // Declaring new vector
    vector<string> copy;

    // Copying vector by copy function
    for(int i = this->problemVector.size() - 1 ; i >= 0; i--) {
        copy.emplace_back(this->problemVector[i]);
    }
    return new MatrixProblem(copy);
}

// convert the strings vector to a unique string to represent the current matrix problem
string MatrixProblem::makeProblemString() {
    string str = "";
    for (unsigned int i = 0; i < this->problemVector.size(); i++) {
        str += this->problemVector[i];
        if (i != this->problemVector.size() - 1) {
            str += "$";
        }
    }
    return str;
}

// An initialize method. get the strings vector and parse it:
// split each row by ',' and creates matching dynamic 2D array, starting state and finish state
void MatrixProblem::makeMatrix() {
    vector<string> cells;
    int size = this->problemVector.size();
    this->rows = this->problemVector.size() - 2;
    for (int i = 0; i < size; i++) {
        cells = Utils::split(this->problemVector[i], ",");
        if (i < size - 2) {
            if (i == 0) {
                this->cols = cells.size();
                this->initMatrix();
            } else {
                if (cells.size() != (unsigned)this->cols) {
                    cerr << "bad matrix size input" << endl;
                    exit(1);
                }
            }
            for (unsigned int j = 0; j < cells.size(); j++) {
                this->matrix[i][j] = new State<Node*>(new Node(i, j, strtod(cells[j].c_str(), NULL)));
            }
        } else if (i == size - 2) {
            int row = strtod(cells[0].c_str(), NULL);
            int col = strtod(cells[1].c_str(), NULL);
            this->initialState = this->matrix[row][col];
        // i == size - 1
        } else {
            int row = strtod(cells[0].c_str(), NULL);
            int col = strtod(cells[1].c_str(), NULL);
            this->goalStates.emplace_back(this->matrix[row][col]);
        }
    }
}

// An initialize method. creates a matching dynamic 2D array according the cols and rows size.
void MatrixProblem::initMatrix() {
    this->matrix = new State<Node*>**[this->rows];
    for (int i = 0; i < this->rows; i++) {
        this->matrix[i] = new State<Node*>*[this->cols];
    }
}

// return a to_string representing of the number which calculated from the hash function on the unique string of the matrix
string MatrixProblem::getString() {
    hash<string> hasher;
    auto hashed = hasher(this->problemString);
    return to_string(hashed);
}

// check if the given state is a goal state of the current matrix problem
bool MatrixProblem::isGoalState(State<Node*> *state) {
    for(State<Node*>* current : this->goalStates) {
        if(current->isEqual(state)) {
            return true;
        }
    }
    return false;
}

// return a goal state of the current matrix problem
State<Node *> * MatrixProblem::getGoalState() {
    if(this->goalStates.empty()) {
        return NULL;
    }
    return this->goalStates[0];
}

// return the initial state
State<Node *> * MatrixProblem::getInitialState() {
    return this->initialState;
}

//return all the possible moves from the given state (the adjacent cells which their cost isn't -1) as a states vector
vector<State<Node *> *> MatrixProblem::getAllPossibleStates(State<Node *> *state) {
    vector<State<Node *> *> result;
    int i = state->getState()->getI();
    int j = state->getState()->getJ();
    bool isTop = false, isDown = false, isRight = false, isLeft = false;
    if(i == 0)  {
        isTop = true;
    }
    if(i == this->rows - 1) {
        isDown = true;
    }
    if(j == 0)  {
        isLeft = true;
    }
    if(j == this->cols - 1) {
        isRight = true;
    }
    if(!isTop && this->matrix[i - 1][j]->getState()->getCost() != -1) {
        // make up
        result.emplace_back(this->matrix[i - 1][j]);
    }
    if(!isDown && this->matrix[i + 1][j]->getState()->getCost() != -1) {
        // make down
        result.emplace_back(this->matrix[i + 1][j]);
    }
    if(!isRight && this->matrix[i][j + 1]->getState()->getCost() != -1) {
        // make right
        result.emplace_back(this->matrix[i][j + 1]);
    }
    if(!isLeft && this->matrix[i][j - 1]->getState()->getCost() != -1) {
        // make left
        result.emplace_back(this->matrix[i][j - 1]);
    }
    return result;
}

// make a string restoring the moves of the path from the starting state to the goal state, and for each move calculate the cumulative cost
string MatrixProblem::getPath(vector<State<Node *>*> statesVector) {
    string result = "";
    int size = statesVector.size();
    State<Node*>* prev = statesVector[size - 1];
    int counter = prev->getState()->getCost();
    State<Node*>* curr;
    for (int i = size - 2; i >= 0; i--) {
        if (i != size - 2) {
            result += ", ";
        }
        curr = statesVector[i];
        counter += curr->getState()->getCost();
        if (prev->getState()->getI() > curr->getState()->getI()) {
            result += "Up";
        } else if (prev->getState()->getI() < curr->getState()->getI()) {
            result += "Down";
        } else if (prev->getState()->getJ() > curr->getState()->getJ()) {
            result += "Left";
        } else {
            result += "Right";
        }
        result += " (" + to_string(counter) + ")";
        prev = curr;
    }
    return result;
}
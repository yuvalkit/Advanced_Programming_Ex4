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

Searchable<Node *> * MatrixProblem::getClone() {
    // Declaring new vector
    vector<string> copy;

    // Copying vector by copy function
    for(unsigned int i = this->problemVector.size() - 1 ; i >= 0; i--) {
        copy.emplace_back(this->problemVector[i]);
    }
    return new MatrixProblem(copy);
}

string MatrixProblem::makeProblemString() {
    string str = "";
    for (int i = 0; i < this->problemVector.size(); i++) {
        str += this->problemVector[i];
        if (i != this->problemVector.size() - 1) {
            str += "$";
        }
    }
    return str;
}

void MatrixProblem::makeMatrix() {
    vector<string> cells;
    int infinity = numeric_limits<int>::max();
    int size = this->problemVector.size();
    this->rows = this->problemVector.size() - 2;
    for (int i = 0; i < size; i++) {
        cells = Utils::split(this->problemVector[i], ",");
        if (i < size - 2) {
            if (i == 0) {
                this->cols = cells.size();
                this->initMatrix();
            } else {
                if (cells.size() != this->cols) {
                    cerr << "bad matrix size input" << endl;
                    exit(1);
                }
            }
            for (int j = 0; j < cells.size(); j++) {
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

void MatrixProblem::printMatrix() {
    for (int i = 0; i < this->rows; i++) {
        for (int j = 0; j < this->cols; j++) {
            cout << this->matrix[i][j]->getState()->getCost();
            if (j != this->cols - 1) {
                cout << ",";
            }
        }
        cout << endl;
    }
}

void MatrixProblem::initMatrix() {
    this->matrix = new State<Node*>**[this->rows];
    for (int i = 0; i < this->rows; i++) {
        this->matrix[i] = new State<Node*>*[this->cols];
    }
}

string MatrixProblem::getString() {
    hash<string> hasher;
    auto hashed = hasher(this->problemString);
    return to_string(hashed);
}

bool MatrixProblem::isGoalState(State<Node*> *state) {
    for(State<Node*>* current : this->goalStates) {
        if(current->isEqual(state)) {
            return true;
        }
    }
    return false;
}

State<Node *> * MatrixProblem::getGoalState() {
    if(this->goalStates.empty()) {
        return NULL;
    }
    return this->goalStates[0];
}

State<Node *> * MatrixProblem::getInitialState() {
    return this->initialState;
}

vector<State<Node *> *> MatrixProblem::getAllPossibleStates(State<Node *> *state) {
    vector<State<Node *> *> result;
    int i = state->getState()->getI();
    int j = state->getState()->getJ();
    int cost = state->getState()->getCost();
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
        //this->matrix[i - 1][j]->setCameFrom(state);
        result.emplace_back(this->matrix[i - 1][j]);
    }
    if(!isDown && this->matrix[i + 1][j]->getState()->getCost() != -1) {
        // make down
        //this->matrix[i + 1][j]->setCameFrom(state);
        result.emplace_back(this->matrix[i + 1][j]);
    }
    if(!isRight && this->matrix[i][j + 1]->getState()->getCost() != -1) {
        // make right
        //this->matrix[i][j + 1]->setCameFrom(state);
        result.emplace_back(this->matrix[i][j + 1]);
    }
    if(!isLeft && this->matrix[i][j - 1]->getState()->getCost() != -1) {
        // make left
        //this->matrix[i][j - 1]->setCameFrom(state);
        result.emplace_back(this->matrix[i][j - 1]);
    }
    return result;
}

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
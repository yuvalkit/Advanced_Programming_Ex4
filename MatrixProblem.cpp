//
// Created by giladby on 10/01/2020.
//

#include "MatrixProblem.h"
#include "Utils.h"

MatrixProblem::MatrixProblem(vector<string> inputProblem) {
    this->problemVector = inputProblem;
    this->problemString = this->makeProblemString();
    this->makeMatrix();
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
                this->matrix[i][j] = new Node(i, j, strtod(cells[j].c_str(), NULL));
            }
        } else if (i == size - 2) {
            int row = strtod(cells[0].c_str(), NULL);
            int col = strtod(cells[1].c_str(), NULL);
            this->initialState = new State<Node*>(this->matrix[row][col], this->matrix[row][col]->getCost(), NULL);
        // i == size - 1
        } else {
            int row = strtod(cells[0].c_str(), NULL);
            int col = strtod(cells[1].c_str(), NULL);
            this->goalStates.emplace_back(new State<Node*>(this->matrix[row][col], this->matrix[row][col]->getCost(), NULL));
        }
    }
}

void MatrixProblem::printMatrix() {
    for (int i = 0; i < this->rows; i++) {
        for (int j = 0; j < this->cols; j++) {
            cout << this->matrix[i][j]->getCost();
            if (j != this->cols - 1) {
                cout << ",";
            }
        }
        cout << endl;
    }
}

void MatrixProblem::initMatrix() {
    this->matrix = new Node**[this->rows];
    for (int i = 0; i < this->rows; i++) {
        this->matrix[i] = new Node*[this->cols];
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

State<Node *> * MatrixProblem::getInitialState() {
    return this->initialState;
}

vector<State<Node *> *> * MatrixProblem::getAllPossibleStates(State<Node *> *state) {
    vector<State<Node *> *> * result = NULL;
    int i = state->getState()->getI();
    int j = state->getState()->getJ();
    int cost = state->getState()->getCost();
    bool isTop = false, isDown = false, isRight = false, isLeft = false;
    State<Node*>* newState;
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
    if(!isTop && this->matrix[i - 1][j]->getCost() != -1) {
        // make up
        newState = new State<Node*>(this->matrix[i - 1][j], this->matrix[i - 1][j]->getCost() + state->getSum(), state);
        result->emplace_back(newState);
    }
    if(!isDown && this->matrix[i + 1][j]->getCost() != -1) {
        // make down
        newState = new State<Node*>(this->matrix[i + 1][j], this->matrix[i + 1][j]->getCost() + state->getSum(), state);
        result->emplace_back(newState);
    }
    if(!isRight && this->matrix[i][j + 1]->getCost() != -1) {
        // make right
        newState = new State<Node*>(this->matrix[i][j + 1], this->matrix[i][j + 1]->getCost() + state->getSum(), state);
        result->emplace_back(newState);
    }
    if(!isLeft && this->matrix[i][j - 1]->getCost() != -1) {
        // make left
        newState = new State<Node*>(this->matrix[i][j - 1], this->matrix[i][j - 1]->getCost() + state->getSum(), state);
        result->emplace_back(newState);
    }
    return result;
}
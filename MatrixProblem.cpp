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
            this->initialState = new State<Node*>(this->matrix[row][col]);
        // i == size - 1
        } else {
            int row = strtod(cells[0].c_str(), NULL);
            int col = strtod(cells[1].c_str(), NULL);
            this->goalStates.emplace_back(new State<Node*>(this->matrix[row][col]));
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

}

State<Node *> * MatrixProblem::getInitialState() {

}

list<State<Node *> *> * MatrixProblem::getAllPossibleStates(State<Node *> *state) {

}
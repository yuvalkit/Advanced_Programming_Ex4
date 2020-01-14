//
// Created by yuvalkit on 14/01/2020.
//

#include "Node.h"

Node::Node(int inputI, int inputJ, int inputCost) {
    this->i = inputI;
    this->j = inputJ;
    this->cost = inputCost;
}

int Node::getI() {
    return this->i;
}

int Node::getJ() {
    return this->j;
}

int Node::getCost() {
    return this->cost;
}
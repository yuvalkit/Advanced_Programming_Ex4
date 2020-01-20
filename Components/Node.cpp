
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

// check if this current node is equal to the given node
bool Node::isEqual(Node *node) {
    return this->i == node->getI() && this->j == node->getJ() && this->cost == node->getCost();
}
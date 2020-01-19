//
// Created by yuvalkit on 14/01/2020.
//

#ifndef ADVANCED_PROGRAMMING_EX4_NODE_H
#define ADVANCED_PROGRAMMING_EX4_NODE_H

using namespace std;

/**
 * Node class
 */
class Node {
private:
    int i;
    int j;
    int cost;
public:
    Node(int inputI, int inputJ, int inputCost);
    int getI();
    int getJ();
    int getCost();
    bool isEqual(Node* node);
};


#endif //ADVANCED_PROGRAMMING_EX4_NODE_H

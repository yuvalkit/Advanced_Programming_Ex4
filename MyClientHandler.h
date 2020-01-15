//
// Created by giladby on 09/01/2020.
//

#ifndef ADVANCED_PROGRAMMING_EX4_MYCLIENTHANDLER_H
#define ADVANCED_PROGRAMMING_EX4_MYCLIENTHANDLER_H

#include "ClientHandler.h"
#include "Solver.h"
#include <vector>
#include <string>
#include <iostream>
#include "CacheManager.h"
#include "Searchable.h"
#include "Node.h"

using namespace std;

class MyClientHandler : public ClientHandler {
private:
    Solver<Searchable<Node*>*, vector<State<Node*>*>>* solver;
    CacheManager<Searchable<Node*>*, string>* cm;
public:
    void handleClient(int clientSocket);
    MyClientHandler(Solver<Searchable<Node*>*, vector<State<Node*>*>>* inputSolver, CacheManager <Searchable<Node*>*, string>* inputCm);
    ClientHandler* getClone();
};


#endif //ADVANCED_PROGRAMMING_EX4_MYCLIENTHANDLER_H

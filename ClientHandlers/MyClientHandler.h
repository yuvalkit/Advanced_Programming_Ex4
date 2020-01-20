
#ifndef ADVANCED_PROGRAMMING_EX4_MYCLIENTHANDLER_H
#define ADVANCED_PROGRAMMING_EX4_MYCLIENTHANDLER_H

#include "ClientHandler.h"
#include "../Solvers/Solver.h"
#include <vector>
#include <string>
#include <iostream>
#include "../CacheManagers/CacheManager.h"
#include "../Searchables/Searchable.h"
#include "../Components/Node.h"
#include "../Components/State.h"

using namespace std;

/**
 * MyClientHandler class
 */
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

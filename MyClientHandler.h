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

using namespace std;

class MyClientHandler : public ClientHandler {
private:
    Solver<Searchable*, string>* solver;
    CacheManager<string, string>* cm;
public:
    void handleClient(int clientSocket);
    MyClientHandler(Solver<Searchable*, string>* inputSolver, CacheManager <string, string>* inputCm);
};


#endif //ADVANCED_PROGRAMMING_EX4_MYCLIENTHANDLER_H

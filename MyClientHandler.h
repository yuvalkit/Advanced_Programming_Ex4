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

using namespace std;

template <class Solution>
class MyClientHandler : public ClientHandler {
private:
    Solver<string, Solution>* solver;
    CacheManager<string, Solution>* cm;
public:
    void handleClient(int clientSocket);
};


#endif //ADVANCED_PROGRAMMING_EX4_MYCLIENTHANDLER_H

//
// Created by giladby on 09/01/2020.
//

#ifndef ADVANCED_PROGRAMMING_EX4_MYTESTCLIENTHANDLER_H
#define ADVANCED_PROGRAMMING_EX4_MYTESTCLIENTHANDLER_H

#include "ClientHandler.h"
#include "Solver.h"
#include <vector>
#include <string>
#include <iostream>
#include "CacheManager.h"
#include <thread>
#include <unistd.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include "Utils.h"
#include "ReverseProblem.h"

using namespace std;

class MyTestClientHandler : public ClientHandler {
private:
    Solver<string, string>* solver;
    CacheManager <ReverseProblem*, string>* cm;
public:
    MyTestClientHandler(Solver<string, string>* inputSolver, CacheManager <ReverseProblem*, string>* inputCm);
    void handleClient(int clientSocket);
    ClientHandler* getClone();
};


#endif //ADVANCED_PROGRAMMING_EX4_MYTESTCLIENTHANDLER_H

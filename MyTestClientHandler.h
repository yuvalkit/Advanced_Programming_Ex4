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

using namespace std;

template <class Solution>
class MyTestClientHandler : public ClientHandler {
private:
    Solver<string, Solution>* solver;
    CacheManager <string, Solution>* cm;
public:
    MyTestClientHandler(Solver<string, Solution>* inputSolver, CacheManager <string, Solution>* inputCm) {
        this->solver = inputSolver;
        this->cm = inputCm;
    }
    void handleClient(int clientSocket) {
        int isSent;
        char buffer[1024] = {0};
        vector<string> bufferVector;
        vector<string> valuesVector;
        string current;
        Solution solution;
        int data = read(clientSocket, buffer, 1024);
        while (data != -1) {
            current = buffer;
            if(current == "end") {
                break;
            }
            if(this->cm->isExist(current)) {
                solution = this->cm->getSolution(current);
            } else {
                solution = this->solver->solve(current);
                this->cm->saveSolution(current, solution);
            }
            isSent = send(clientSocket, solution, sizeof(solution), 0);
            if(isSent == -1) {
                cerr << "failed send message"<< endl;
                exit(1);
            }
            buffer[1024] = {0};
            data = read(clientSocket, buffer, 1024);
        }
    }
};


#endif //ADVANCED_PROGRAMMING_EX4_MYTESTCLIENTHANDLER_H

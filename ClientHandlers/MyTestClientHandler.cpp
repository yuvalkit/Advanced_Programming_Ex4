//
// Created by giladby on 09/01/2020.
//

#include "MyTestClientHandler.h"

MyTestClientHandler::MyTestClientHandler(Solver<string, string> *inputSolver, CacheManager<ReverseProblem*, string> *inputCm)  {
    this->solver = inputSolver;
    this->cm = inputCm;
}

// get strings by client and send him the reverse strings until the client's input is 'end'
// before solving the problem of reversing the string, check if there is a solution in cache
// in case of new solution - save it in cache
void MyTestClientHandler::handleClient(int clientSocket) {
    int isSent;
    char buffer[1024] = {0};
    vector<string> bufferVector;
    vector<string> valuesVector;
    string current;
    string solution;
    char c;
    int data = read(clientSocket, buffer, 1024);
    while (data != -1) {
        current = buffer;
        c = current[current.size() - 1];
        while(c == '\n' || c == '\r') {
            current = current.substr(0, current.size() - 1);
            c = current[current.size() - 1];
        }
        if(current == "end") {
            break;
        }
        ReverseProblem* rp = new ReverseProblem(current);
        // check if there is a solution in cache
        if(this->cm->isExist(rp)) {
            solution = this->cm->getSolution(rp);
        } else {
            solution = this->solver->solve(rp->getString());
            this->cm->saveSolution(rp, solution);
        }
        isSent = send(clientSocket, solution.c_str(), solution.size(), 0);
        if(isSent == -1) {
            cerr << "failed send message"<< endl;
            exit(1);
        }
        for (int i = 0; i < 1024; i++) {
            buffer[i] = 0;
        }
        data = read(clientSocket, buffer, 1024);
    }
}

//a method for creating deep clone of the object
ClientHandler* MyTestClientHandler::getClone() {
    return new MyTestClientHandler(this->solver->getClone(), this->cm->getClone());
}
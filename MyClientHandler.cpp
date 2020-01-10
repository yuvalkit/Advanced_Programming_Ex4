
#include "MyClientHandler.h"
#include <thread>
#include <unistd.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include "Utils.h"
#include "MatrixProblem.h"

MyClientHandler::MyClientHandler(Solver<Searchable*, string> *inputSolver, CacheManager<string, string> *inputCm) {
    this->cm = inputCm;
    this->solver = inputSolver;
}

void MyClientHandler::handleClient(int clientSocket) {
    int isSent;
    char buffer[1024] = {0};
    vector<string> bufferVector;
    vector<string> valuesVector;
    string current,problem = "";
    string solution;
    Searchable* searchable;
    char c;
    int data = read(clientSocket, buffer, 1024);
    while (data != -1) {
        current = buffer;
        c = current[current.size() - 1];
        while (c == '\n' || c == '\r') {
            current = current.substr(0, current.size() - 1);
            c = current[current.size() - 1];
        }
        if (current == "end") {
            //remove last '$'
            problem = problem.substr(0, problem.size() - 1);
            break;
        }
        current = Utils::removeSpaces(current);
        problem += current + "$";
        for (int i = 0; i < 1024; i++) {
            buffer[i] = 0;
        }
        data = read(clientSocket, buffer, 1024);
    }
    if(this->cm->isExist(problem)) {
        solution = this->cm->getSolution(problem);
    } else {
        searchable = new MatrixProblem(problem);
        solution = this->solver->solve(searchable);
        this->cm->saveSolution(current, solution);
    }
    isSent = send(clientSocket, solution.c_str(), solution.size(), 0);
    if(isSent == -1) {
        cerr << "failed send message"<< endl;
        exit(1);
    }
}
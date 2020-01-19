
#include "MyClientHandler.h"
#include <thread>
#include <unistd.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include "Utils.h"
#include "MatrixProblem.h"

MyClientHandler::MyClientHandler(Solver<Searchable<Node*>*, vector<State<Node*>*>> *inputSolver, CacheManager<Searchable<Node*>*, string> *inputCm) {
    this->cm = inputCm;
    this->solver = inputSolver;
}

// get the clientSocket and receive a matrix problem from the client line by line, and send the solution back to him.
// search the solution in cache, and if it is not exist yet, calculate it and save it in the cache.
void MyClientHandler::handleClient(int clientSocket) {
    int isSent, counterValid;
    bool validFlag, finishFlag, newLineFlag;
    char testChar;
    char buffer[1024] = {0};
    vector<string> bufferVector;
    vector<string> valuesVector;
    string current = "", str;
    string problem = "";
    string solution;
    vector<State<Node*>*> solutionVector;
    Searchable<Node*>* searchable;
    int data = read(clientSocket, buffer, 1024);
    // getting the matrix line by line
    while (data != -1) {
        finishFlag = false;
        newLineFlag = false;
        validFlag = true;
        current += Utils::removeSpaces((string) buffer);
        if (current[current.size() - 1] == '\n') {
            newLineFlag = true;
        }
        bufferVector = Utils::split(current, "\n");
        for (unsigned int j = 0; j < bufferVector.size(); j++) {
            str = bufferVector[j];
            counterValid = 0;
            if(str == "") {
                break;
            }
            //the last chunk get cut sometimes, and if so - run over the chunk and remove the bad characters.
            if(j == bufferVector.size() - 1) {
                if (!newLineFlag) {
                    for(unsigned int i = 0; i < str.length(); i++) {
                        testChar = str[i];
                        if(isdigit(testChar) || testChar == '.' || testChar == ','|| testChar == '-') {
                            counterValid++;
                        } else {
                            validFlag = false;
                            break;
                        }
                    }
                    if(!validFlag) {
                        str = str.substr(0, counterValid);
                    }
                }
                current = str;
                if (str == "end") {
                    finishFlag = true;
                } else {
                    if (newLineFlag) {
                        valuesVector.emplace_back(str);
                    }
                }
            } else {
                valuesVector.emplace_back(str);
            }
        }
        if (finishFlag) {
            break;
        }
        if(newLineFlag) {
            current = "";
        }
        for (int i = 0; i < 1024; i++) {
            buffer[i] = 0;
        }
        data = read(clientSocket, buffer, 1024);
    }
    searchable = new MatrixProblem(valuesVector);
    // check if the solution has been already calculated
    if(this->cm->isExist(searchable)) {
        solution = this->cm->getSolution(searchable);
    } else {
        solutionVector = this->solver->solve(searchable);
        solution = MatrixProblem::getPath(solutionVector);
        this->cm->saveSolution(searchable, solution);
    }
    isSent = send(clientSocket, solution.c_str(), solution.size(), 0);
    if(isSent == -1) {
        cerr << "failed send message"<< endl;
        exit(1);
    }
}

//a method for creating deep clone of the object
ClientHandler * MyClientHandler::getClone() {
    return new MyClientHandler(this->solver->getClone(), this->cm->getClone());
}
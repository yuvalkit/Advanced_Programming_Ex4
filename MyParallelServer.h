//
// Created by yuvalkit on 15/01/2020.
//

#ifndef ADVANCED_PROGRAMMING_EX4_MYPARALLELSERVER_H
#define ADVANCED_PROGRAMMING_EX4_MYPARALLELSERVER_H


#include "Server.h"
#include <thread>
#include <vector>

using namespace std;

class MyParallelServer : public server_side::Server {
private:
    vector<thread> threadsVector;
    vector<bool> threadsIndex;
public:
    MyParallelServer();
    void open(int port, ClientHandler* c);
    void stop();
    void handleClientInThread(int clientSocket, ClientHandler* c, int threadIndex);
    void joinTreads();
};


#endif //ADVANCED_PROGRAMMING_EX4_MYPARALLELSERVER_H

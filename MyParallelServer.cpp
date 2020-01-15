//
// Created by yuvalkit on 15/01/2020.
//

#include "MyParallelServer.h"
#include <iostream>
#include <unistd.h>
#include <netinet/in.h>
#include <sys/socket.h>

MyParallelServer::MyParallelServer() {
    this->toStop = false;
}

void MyParallelServer::stop() {
    this->toStop = true;
}

void MyParallelServer::open(int port, ClientHandler *c) {
    int threadCounter = 0;
    struct timeval timeout{};
    timeout.tv_sec = 120;
    int socketfd = socket(AF_INET, SOCK_STREAM, 0);
    if (socketfd == -1) {
        //error
        cerr << "Could not create a socket"<<endl;
        exit(1);
    }
    sockaddr_in address{};
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(port);
    // bind to socket
    if (bind(socketfd, (struct sockaddr *) &address, sizeof(address)) == -1) {
        std::cerr<<"Could not bind the socket to an IP"<<endl;
        exit(1);
    }
    if (listen(socketfd, 10) == -1) {
        std::cerr<<"Error during listening command"<<endl;
        exit(1);
    }
    setsockopt(socketfd, SOL_SOCKET, SO_RCVTIMEO, (const char*)&timeout, sizeof timeout);
    while (!this->toStop) {
        struct sockaddr_in client;
        socklen_t clilen = sizeof(client);
        cout << "listening" << endl;
        // accept a client
        int clientSocket = accept(socketfd, (struct sockaddr *)&client, &clilen);
        if (clientSocket < 0) {
            if (errno == EWOULDBLOCK) {
                cout << "timeout" << endl;
                this->joinTreads();
                this->stop();
            } else {
                cout << "error with client socket" << endl;
            }
            continue;
        }
        cout << "client " + to_string(threadCounter) + " connected" << endl;
        this->threadsFlags.emplace_back(true);
        this->threadsVector.emplace_back(thread(&MyParallelServer::handleClientInThread, this, clientSocket, c, threadCounter));
        threadCounter++;
    }

    close(socketfd);
}

void MyParallelServer::joinTreads() {
    for (int i = 0; i < this->threadsFlags.size(); i++) {
        if(this->threadsFlags[i]) {
            this->threadsVector[i].join();
        }
    }
}

void MyParallelServer::handleClientInThread(int clientSocket, ClientHandler *c, int threadCounter) {
    cout << "start handling client " + to_string(threadCounter) << endl;
    c->handleClient(clientSocket);
    this->threadsFlags[threadCounter]= false;
    close(clientSocket);
    cout << "finish handling client " + to_string(threadCounter) << endl;
}
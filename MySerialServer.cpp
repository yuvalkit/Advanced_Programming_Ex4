//
// Created by giladby on 09/01/2020.
//

#include "MySerialServer.h"
#include <iostream>
#include <unistd.h>
#include <netinet/in.h>
#include <sys/socket.h>

using namespace std;

void MySerialServer::open(int port, ClientHandler* c) {
    this->t = thread(clientListening, port, c);
    this->t.join();
}

void MySerialServer::clientListening(int port, ClientHandler *c) {
    int clientSocket;
    struct timeval timeout{};
    timeout.tv_sec = 2;
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
    if (listen(socketfd, 5) == -1) {
        std::cerr<<"Error during listening command"<<endl;
        exit(1);
    }
    setsockopt(socketfd, SOL_SOCKET, SO_RCVTIMEO, (const char*)&timeout, sizeof timeout);
    while (!MySerialServer::stopFlag) {
        // accept a client
        clientSocket = accept(socketfd, (struct sockaddr *)&address, (socklen_t*)&address);
        if (clientSocket == -1) {
            continue;
        }
        c->handleClient(clientSocket);
    }
    close(socketfd);
}

void MySerialServer::stop() {
    stopFlag = true;
}

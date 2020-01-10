////
//// Created by giladby on 09/01/2020.
////
//
#include "MySerialServer.h"
#include <iostream>
#include <unistd.h>
#include <netinet/in.h>
#include <sys/socket.h>

using namespace std;

MySerialServer::MySerialServer() {
    this->toStop = false;
}

void MySerialServer::open(int port, ClientHandler* c) {
    this->t = thread(&MySerialServer::start, this, port, c);
    this->t.join();
}
void MySerialServer::start(int port, ClientHandler *c) {
    int clientSocket;
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
    if (listen(socketfd, 5) == -1) {
        std::cerr<<"Error during listening command"<<endl;
        exit(1);
    }
    setsockopt(socketfd, SOL_SOCKET, SO_RCVTIMEO, (const char*)&timeout, sizeof timeout);
    while (!this->toStop) {
        struct sockaddr_in client;
        socklen_t clilen = sizeof(client);
        cout << "listening" << endl;
        // accept a client
        clientSocket = accept(socketfd, (struct sockaddr *)&client, &clilen);
        if (clientSocket < 0) {
            if (errno == EWOULDBLOCK) {
                cout << "timeout" << endl;
            } else {
                cout << "error with client socket" << endl;
            }
            this->stop();
            continue;
        }
        cout << "client connected" << endl;
        c->handleClient(clientSocket);
    }
    close(socketfd);
}
void MySerialServer::stop() {
    toStop = true;
}

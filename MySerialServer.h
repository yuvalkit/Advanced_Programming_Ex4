//
// Created by giladby on 09/01/2020.
//

#ifndef ADVANCED_PROGRAMMING_EX4_MYSERIALSERVER_H
#define ADVANCED_PROGRAMMING_EX4_MYSERIALSERVER_H

#include "Server.h"
#include <thread>

using namespace std;

class MySerialServer : public server_side::Server{
private:
    thread t;
public:
    void open(int port, ClientHandler* c);
    void stop();
    static void clientListening(int port, ClientHandler* c);
};


#endif //ADVANCED_PROGRAMMING_EX4_MYSERIALSERVER_H

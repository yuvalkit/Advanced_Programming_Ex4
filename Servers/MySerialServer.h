
#ifndef ADVANCED_PROGRAMMING_EX4_MYSERIALSERVER_H
#define ADVANCED_PROGRAMMING_EX4_MYSERIALSERVER_H

#include "Server.h"
#include <thread>

using namespace std;

/**
 * MySerialServer class
 */
class MySerialServer : public server_side::Server {
private:
    thread t;
public:
    MySerialServer();
    void open(int port, ClientHandler* c);
    void stop();
    void start(int port, ClientHandler* c);
};


#endif //ADVANCED_PROGRAMMING_EX4_MYSERIALSERVER_H

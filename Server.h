//
// Created by giladby on 09/01/2020.
//

#ifndef ADVANCED_PROGRAMMING_EX4_SERVER_H
#define ADVANCED_PROGRAMMING_EX4_SERVER_H

#include "ClientHandler.h"

namespace server_side {
    class Server {
    protected:
        bool toStop;
    public:
        virtual void open(int port, ClientHandler* c) = 0;
        virtual void stop() = 0;
    };
}

#endif //ADVANCED_PROGRAMMING_EX4_SERVER_H

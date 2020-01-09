//
// Created by giladby on 09/01/2020.
//

#ifndef ADVANCED_PROGRAMMING_EX4_SERVER_H
#define ADVANCED_PROGRAMMING_EX4_SERVER_H

#include "ClientHandler.h"

namespace server_side {
    class Server {
    protected:
        static bool stopFlag;
    public:
        virtual void open(int port, ClientHandler* c);
        virtual void stop();
    };
}

#endif //ADVANCED_PROGRAMMING_EX4_SERVER_H

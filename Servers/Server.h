
#ifndef ADVANCED_PROGRAMMING_EX4_SERVER_H
#define ADVANCED_PROGRAMMING_EX4_SERVER_H

#include "../ClientHandlers/ClientHandler.h"

namespace server_side {
    /**
    * Server interface
    */
    class Server {
    protected:
        bool toStop;
    public:
        virtual void open(int port, ClientHandler* c) = 0;
        virtual void stop() = 0;
        virtual ~Server() {}
    };
}

#endif //ADVANCED_PROGRAMMING_EX4_SERVER_H

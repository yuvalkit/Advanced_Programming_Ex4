//
// Created by giladby on 09/01/2020.
//

#ifndef ADVANCED_PROGRAMMING_EX4_CLIENTHANDLER_H
#define ADVANCED_PROGRAMMING_EX4_CLIENTHANDLER_H

/**
 * ClientHandler interface
 */
class ClientHandler {
public:
    virtual void handleClient(int clientSocket) = 0;
    virtual ClientHandler* getClone() = 0;
};


#endif //ADVANCED_PROGRAMMING_EX4_CLIENTHANDLER_H

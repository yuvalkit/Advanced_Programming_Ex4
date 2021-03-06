
#ifndef ADVANCED_PROGRAMMING_EX4_CLIENTHANDLER_H
#define ADVANCED_PROGRAMMING_EX4_CLIENTHANDLER_H

/**
 * ClientHandler interface
 */
class ClientHandler {
public:
    virtual void handleClient(int clientSocket) = 0;
    virtual ClientHandler* getClone() = 0;
    virtual ~ClientHandler() {}
};


#endif //ADVANCED_PROGRAMMING_EX4_CLIENTHANDLER_H

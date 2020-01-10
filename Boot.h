//
// Created by giladby on 09/01/2020.
//

#ifndef ADVANCED_PROGRAMMING_EX4_BOOT_H
#define ADVANCED_PROGRAMMING_EX4_BOOT_H

#include "CacheManager.h"
#include "MyTestClientHandler.h"
#include "FileCacheManager.h"
#include "Solver.h"
#include "Server.h"
#include "StringReverser.h"
#include "MySerialServer.h"

namespace boot {
    class Main {
    public:
        int main1(int argc, char** argv) {
            CacheManager<string, string>* cm = new FileCacheManager<string>(5);
            Solver<string, string>* s = new StringReverser();
            ClientHandler* c = new MyTestClientHandler(s, cm);
            server_side::Server* server = new MySerialServer();
            if(argc >= 2) {
                server->open(strtod(argv[1], NULL), c);
            }
            return 0;
        }
    };
}

#endif //ADVANCED_PROGRAMMING_EX4_BOOT_H

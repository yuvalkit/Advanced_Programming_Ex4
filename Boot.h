//
// Created by giladby on 09/01/2020.
//

#ifndef ADVANCED_PROGRAMMING_EX4_BOOT_H
#define ADVANCED_PROGRAMMING_EX4_BOOT_H

namespace boot {
    class Main {
        int main1(int argc, char** argv) {
            ClientHandler* c;
            Server* server = new MySerialServer();
            if(argc >= 2) {
                server->open(strtod(argv[1], NULL), c);
            }
            return 0;
        }
    };
}

#endif //ADVANCED_PROGRAMMING_EX4_BOOT_H

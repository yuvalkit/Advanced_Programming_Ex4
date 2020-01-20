//
// Created by giladby on 09/01/2020.
//

#ifndef ADVANCED_PROGRAMMING_EX4_BOOT_H
#define ADVANCED_PROGRAMMING_EX4_BOOT_H

#include "CacheManager.h"
#include "MyTestClientHandler.h"
#include "FileCacheManager.h"
#include "Solver.h"
#include "Node.h"
#include "BestFirstSearch.h"
#include "Searcher.h"
#include "Server.h"
#include "StringReverser.h"
#include "MySerialServer.h"
#include "Searchable.h"
#include "MyClientHandler.h"
#include "SearchSolver.h"
#include "BreadthFirstSearch.h"
#include "DepthFirstSearch.h"
#include "AStar.h"
#include "MyParallelServer.h"

namespace boot {
    class Main {
    public:
        int main1(int argc, char** argv) {
            CacheManager<Searchable<Node*>*, string>* cm = new FileCacheManager<Searchable<Node*>*>(5);
            Searcher<Node*>* searcher = new AStar<Node*>();
            Solver<Searchable<Node*>*, vector<State<Node*>*>>* s = new SearchSolver<Node*>(searcher);
            ClientHandler* c = new MyClientHandler(s, cm);
            server_side::Server* server = new MyParallelServer();
            // set port to 5600 as default
            int port = 5600;
            // if there's an argument, set it as port
            if(argc >= 2) {
                port = strtod(argv[1], NULL);
            }
            server->open(port, c);
            return 0;
        }
    };
}

#endif //ADVANCED_PROGRAMMING_EX4_BOOT_H

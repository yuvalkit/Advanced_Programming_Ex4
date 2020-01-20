//
// Created by giladby on 09/01/2020.
//

#ifndef ADVANCED_PROGRAMMING_EX4_BOOT_H
#define ADVANCED_PROGRAMMING_EX4_BOOT_H

#include "CacheManagers/CacheManager.h"
#include "ClientHandlers/MyTestClientHandler.h"
#include "CacheManagers/FileCacheManager.h"
#include "Solvers/Solver.h"
#include "Node.h"
#include "Searchers/BestFirstSearch.h"
#include "Searchers/Searcher.h"
#include "Servers/Server.h"
#include "Solvers/StringReverser.h"
#include "Servers/MySerialServer.h"
#include "Searchables/Searchable.h"
#include "ClientHandlers/MyClientHandler.h"
#include "Solvers/SearchSolver.h"
#include "Searchers/BreadthFirstSearch.h"
#include "Searchers/DepthFirstSearch.h"
#include "Searchers/AStar.h"
#include "Servers/MyParallelServer.h"

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

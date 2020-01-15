//
// Created by giladby on 09/01/2020.
//

#ifndef ADVANCED_PROGRAMMING_EX4_FILECACHEMANAGER_H
#define ADVANCED_PROGRAMMING_EX4_FILECACHEMANAGER_H

#include "CacheManager.h"
#include <iostream>
#include <list>
#include <unordered_map>
#include <iostream>
#include <fstream>

using namespace std;

/**
 * FileCacheManager class
 */
template <class Problem, class Solution>
class FileCacheManager : public CacheManager<Problem, Solution> {
    /**
    * enter the value into the list, if reach to the limit - remove the least recently Used node.
    */
    void toTheTop(Entry<Problem, Solution>* e) {
        this->myList.push_front(e);
        if(this->myList.size() > (unsigned)this->maxSize) {
            Entry<Problem, Solution>* temp = (this->myList.back());
            this->myList.remove(temp);
            this->objMap.erase (temp->problem->getString());
            delete temp;
        }
    }

public:
    FileCacheManager(int max) {
        this->maxSize = max;
        this->enter= false;
    }

    ~FileCacheManager() {
        for(auto p : this->myList) {
            delete p;
        }
    }

    bool isExist(Problem problem) {
        string name = problem->getString();
        if(this->objMap.find(name) != this->objMap.end()) {
            return true;
        }
        fstream file_obj;
        file_obj.open(name, ios::in|ios::binary);
        // key is missing in files
        if (!file_obj.is_open()) {
            return false;
        }
        file_obj.close();
        return true;
    }

    Solution getSolution(Problem problem) {
        string name = problem->getString();
        fstream file_obj;
        Solution object;
        if(!this->myList.empty()) {
            object = this->myList.back()->solution;
        }
        // the key doesn't exist in the cache - search it in files
        if(this->objMap.find(name) == this->objMap.end()) {
            file_obj.open(name, ios::in|ios::binary);
            // key is missing in files
            if (!file_obj.is_open()) {
                cerr << "cannot open file"<< endl;
                exit(1);
            } else {
                file_obj.read((char *) &(object), sizeof(object));
                Entry<Problem, Solution>* e = new Entry<Problem, Solution>(problem, object);
                // update the current value in the map
                this->objMap[name] = e;
                // update the list according the current value
                this->toTheTop(e);
                file_obj.close();
                return object;
            }
        } else {
            auto found = this->objMap.find(name);
            // update the list according the new entered value
            this->myList.remove((found->second));
            this->toTheTop((found->second));
            return found->second->solution;
        }
    }


    void saveSolution(Problem problem, Solution solution) {
        string name = problem->getString();
        fstream outfile;
        Solution object = solution;
        //writing the object to file
        outfile.open(name, ios::out|ios::binary);
        if(!outfile.is_open()) {
            cerr << "cannot open file"<< endl;
            exit(1);
        }
        outfile.write((char *) &(object), sizeof(object));
        outfile.close();
        Entry<Problem, Solution>* e = new Entry<Problem, Solution>(problem,solution);
        //the key is already exist in the map - remove it from the list, preventing duplicate.
        if (this->objMap.find(name) != this->objMap.end()) {
            auto found = this->objMap.find(name);
            this->myList.remove((found->second));
            delete found->second;
        }
        // enter/update the value in the map
        this->objMap[name] = e;
        // update the list according the new entered value
        this->toTheTop(e);
    }
};


#endif //ADVANCED_PROGRAMMING_EX4_FILECACHEMANAGER_H

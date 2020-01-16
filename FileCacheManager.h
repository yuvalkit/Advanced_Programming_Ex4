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
template <class Problem>
class FileCacheManager : public CacheManager<Problem, string> {
    /**
    * enter the value into the list, if reach to the limit - remove the least recently Used node.
    */
    void toTheTop(Entry<Problem, string>* e) {
        this->myList.push_front(e);
        if(this->myList.size() > (unsigned)this->maxSize) {
            Entry<Problem, string>* temp = (this->myList.back());
            this->myList.remove(temp);
            this->objMap.erase (temp->problem->getString());
            delete temp;
        }
    }

public:
    FileCacheManager(int max) {
        this->maxSize = max;
    }

    ~FileCacheManager() {
        for(auto p : this->myList) {
            delete p;
        }
    }

    CacheManager<Problem, string>* getClone() {
        return new FileCacheManager<Problem>(this->maxSize);
    }

    bool isExist(Problem problem) {
        string name = problem->getString();
        if(this->objMap.find(name) != this->objMap.end()) {
            return true;
        }
        ifstream file_obj;
        file_obj.open(name);
        // key is missing in files
        if (!file_obj) {
            return false;
        }
        file_obj.close();
        return true;
    }

    string getSolution(Problem problem) {
        string name = problem->getString();
        ifstream file_obj;
        string object = "", temp;
        // the key doesn't exist in the cache - search it in files
        if(this->objMap.find(name) == this->objMap.end()) {
            file_obj.open(name);
            // key is missing in files
            if (!file_obj) {
                cerr << "cannot open file"<< endl;
                exit(1);
            } else {
                while(getline(file_obj, temp)) {
                    object += temp;
                }
                file_obj.close();
                Entry<Problem, string>* e = new Entry<Problem, string>(problem, object);
                // update the current value in the map
                this->objMap[name] = e;
                // update the list according the current value
                this->toTheTop(e);
                cout << "got from file" << endl;
                return object;
            }
        } else {
            auto found = this->objMap.find(name);
            // update the list according the new entered value
            this->myList.remove((found->second));
            this->toTheTop((found->second));
            cout << "got from cache" << endl;
            return found->second->solution;
        }
    }


    void saveSolution(Problem problem, string solution) {
        string name = problem->getString();
        ofstream outfile(name);
        if (!outfile) {
            cerr << "cannot open file"<< endl;
            exit(1);
        }
        outfile << solution;
        outfile.close();
        Entry<Problem, string>* e = new Entry<Problem, string>(problem,solution);
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

//
// Created by giladby on 09/01/2020.
//

#ifndef ADVANCED_PROGRAMMING_EX4_CACHEMANAGER_H
#define ADVANCED_PROGRAMMING_EX4_CACHEMANAGER_H

#include <unordered_map>
#include <list>

using namespace std;

/**
 * Entry class.
 * Entry's object holds a field of the string key and a field for the data
 */

template <class Problem, class Solution>
class Entry {
public:
    Problem problem;
    Solution solution;
    Entry(){}
    Entry(Problem p, Solution s) {
        this->problem = p;
        this->solution = s;
    }
};

template <class Problem, class Solution>
class CacheManager {
protected:
    unordered_map<string, Entry<Problem, Solution>*> objMap;
    int maxSize;
    list<Entry<Problem, Solution>*> myList;
public:
    virtual bool isExist(Problem p) = 0;
    virtual Solution getSolution(Problem p) = 0;
    virtual void saveSolution(Problem p, Solution s) = 0;
    virtual CacheManager<Problem, Solution>* getClone() = 0;
};


#endif //ADVANCED_PROGRAMMING_EX4_CACHEMANAGER_H

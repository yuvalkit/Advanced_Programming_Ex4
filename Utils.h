//
// Created by giladby on 09/01/2020.
//

#ifndef ADVANCED_PROGRAMMING_EX4_UTILS_H
#define ADVANCED_PROGRAMMING_EX4_UTILS_H

#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Utils {
public:
    static vector<string> split(string str, const string& delimiter);
    static string removeSpaces(const string& str);
};


#endif //ADVANCED_PROGRAMMING_EX4_UTILS_H

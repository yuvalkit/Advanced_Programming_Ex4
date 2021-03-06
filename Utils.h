
#ifndef ADVANCED_PROGRAMMING_EX4_UTILS_H
#define ADVANCED_PROGRAMMING_EX4_UTILS_H

#include <vector>
#include <string>
#include <iostream>

using namespace std;

/**
 * Utils class
 */
class Utils {
public:
    static vector<string> split(string str, const string& delimiter);
    static string removeSpaces(const string& str);
    static double getDistance(int x1, int y1, int x2, int y2);
};


#endif //ADVANCED_PROGRAMMING_EX4_UTILS_H

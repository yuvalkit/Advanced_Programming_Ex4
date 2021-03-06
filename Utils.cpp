
#include "Utils.h"
#include <cmath>

//split the given string by the given delimiter
vector<string> Utils::split(string str, const string &delimiter) {
    vector<string> strings;
    string token;
    int pos = str.find(delimiter);
    while ((unsigned) pos != (unsigned) string::npos) {
        token = str.substr(0, pos);
        strings.emplace_back(token);
        str.erase(0, pos + delimiter.length());
        pos = str.find(delimiter);
    }
    if(str != "") {
        strings.emplace_back(str);
    }
    return strings;
}

//remove spaces from the given string
string Utils::removeSpaces(const string &str) {
    string result;
    for (char c : str) {
        if (c != ' ') {
            string s(1, c);
            result += s;
        }
    }
    return result;
}

// compute the absolute distance between 2 points
double Utils::getDistance(int x1, int y1, int x2, int y2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}
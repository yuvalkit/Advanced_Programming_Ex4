////
//// Created by giladby on 09/01/2020.
////
//
#include "MyClientHandler.h"
//#include <thread>
//#include <unistd.h>
//#include <netinet/in.h>
//#include <sys/socket.h>
//#include "Utils.h"
//
//void MyClientHandler::handleClient(int clientSocket) {
//    Lexer lexer;
//    char testChar;
//    bool validFlag;
//    int counterValid;
//    char buffer[1024] = {0};
//    vector<string> bufferVector;
//    vector<string> valuesVector;
//    string current = "", substr, testStr, str, temp;
//    int data = read(clientSocket, buffer, 1024);
//    while (data != -1) {
//        if (manager->isDone()) {
//            break;
//        }
//        validFlag = true;
//        current += buffer;
//        temp = current;
//        // split chunks by '\n'
//        bufferVector = Utils::split(current, "\n");
//        for (unsigned int j = 0; j < bufferVector.size(); j++) {
//            str = bufferVector[j];
//            counterValid = 0;
//            if(str == "") {
//                break;
//            }
//            //the last chunk get cut sometimes, and if so - run over the chunk and remove the bad characters.
//            if(j == bufferVector.size() - 1) {
//                for(unsigned int i = 0; i < str.length(); i++) {
//                    testChar = str[i];
//                    if(isdigit(testChar) || testChar == '.' || testChar == ','|| testChar == '-') {
//                        counterValid++;
//                    } else {
//                        validFlag = false;
//                        break;
//                    }
//                }
//                if(!validFlag) {
//                    current = str.substr(0, counterValid);
//                    break;
//                }
//            }
//            // get the values by splitting on every ','
//            valuesVector = Utils::split(str, ",");
//            current = "";
//        }
//        data = read(clientSocket, buffer, 1024);
//    }
//}
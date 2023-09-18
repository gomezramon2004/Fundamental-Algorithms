#include "parse.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <ctime>
#include <algorithm>
#include <stdexcept> 

std::vector<Info> parse(std::string fileName) {
    std::vector<Info> parsedVec;
    std::ifstream inputFile;  //RAII is responsible for destruct the file-handling object out of scope. It will handle file closing automatically
    std::string line;
    inputFile.open(fileName);

    if (!inputFile.is_open()) {
        throw std::runtime_error("Error - Unable to open the file.");
    }

    while (std::getline(inputFile, line)) {
        const char *dateTime = line.substr(0, 16).c_str();
        struct tm timeStruct;
        strptime(dateTime,"%d/%m/%Y %H:%M", &timeStruct);
        std::time_t time = mktime(&timeStruct);
        parsedVec.push_back({time, timeStruct, line[17], line.substr(19, 24)});
    }
    return parsedVec;
}
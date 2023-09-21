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
    std::ifstream inputFile;  // RAII is responsible for destruct the file-handling object out of scope. It will handle file closing automatically
    std::string line;
    inputFile.open(fileName);

    if (!inputFile.is_open()) {
        throw std::runtime_error("Error - Unable to open the file.");
    }

    while (std::getline(inputFile, line)) {
        const std::string dateTime = line.substr(0, 16);
        struct tm timeStruct;

        sscanf(dateTime.c_str(), "%d/%d/%d %d:%d", &timeStruct.tm_mday, &timeStruct.tm_mon, &timeStruct.tm_year, &timeStruct.tm_hour, &timeStruct.tm_min);
        timeStruct.tm_mon -= 1;

        std::time_t time = mktime(&timeStruct);
        parsedVec.push_back({time, timeStruct, line[17], line.substr(19, 24)});
    }
    return parsedVec;
}

// strptime(dateTime,"%d/%m/%Y %H:%M", &timeStruct); We can't use strptime because Windows isn't POSIX Compliant
//  https://stackoverflow.com/questions/321849/strptime-equivalent-on-windows
//  https://www.quora.com/Why-doesnt-Microsoft-make-Windows-POSIX-compliant 
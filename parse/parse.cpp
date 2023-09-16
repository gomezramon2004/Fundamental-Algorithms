#include "parse.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stdexcept> 

std::vector<std::vector<int>> parse(std::string fileName) {
    std::vector<std::vector<int>> parsedVec;
    std::ifstream inputFile;
    int sizeVec, num;
    inputFile.open(fileName); //RAII is responsible for destruct the file-handling object out of scope. It will handle file closing automatically

    if (!inputFile.is_open()) {
        throw std::runtime_error("Error - Unable to open the file.");
    }

    while (inputFile >> sizeVec) {
        if (sizeVec <= 0) {
            throw std::runtime_error("Error - Vector size must be a positive integer.");
        }

        std::vector<int> tempVec; 
        tempVec.reserve(sizeVec); // To reduced reallocation vector size

        for (int i = 0; i < sizeVec; ++i) {
            inputFile >> num;
            tempVec.push_back(num);
        }
        
        parsedVec.push_back(tempVec);
    }

    return parsedVec;
}
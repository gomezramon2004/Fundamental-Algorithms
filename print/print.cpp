#include "print.hpp"
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

void print(std::vector<Info> vec) {
    for (auto &&i : vec) {
        std::cout << std::setfill('0') << std::setw(2) << i.dateTime.tm_mday << '/' << 
        std::setfill('0') << std::setw(2) << i.dateTime.tm_mon + 1 << '/' << 
        i.dateTime.tm_year + 1900 << ' ' << 
        std::setfill('0') << std::setw(2) << i.dateTime.tm_hour << ":" << 
        std::setfill('0') << std::setw(2) << i.dateTime.tm_min << " " << 
        i.enterPoint << " " << 
        i.ubi << "\n";
    }
}
#include "./parse/parse.hpp"
#include "./sort/mergeSort.hpp"
#include "./search/sequentialSearch.hpp"
#include <iostream>
#include <string>
#include <vector>

int main() {
    std::vector<Info> bitacora = parse("bitacora.txt");
    mergeSort(bitacora, 0, bitacora.size() - 1);

    for (auto &&i : bitacora) {
        std::cout << "dia: " << i.dateTime.tm_mday << " ";
        std::cout << "mes: " << i.dateTime.tm_mon << " ";
        std::cout << "año: " << i.dateTime.tm_year << " ";
        std::cout << "hora: " << i.dateTime.tm_hour << " ";
        std::cout << "minutos: " << i.dateTime.tm_min << " ";
        std::cout << "entrada: " << i.enterPoint << " ";
        std::cout << "ubi: " << i.ubi << "\n";
    }

    return 0;
}
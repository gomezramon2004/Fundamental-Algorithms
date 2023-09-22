#include "./parse/parse.hpp"
#include "./sort/mergeSort.hpp"
#include "./search/binarySearch.hpp"
#include "./print/print.hpp"
#include <iostream>
#include <string>
#include <vector>

int main() {
    try {
        std::string input = "4TL";
        std::vector<Info> bitacora = parse("bitacora.txt");
        mergeSort(bitacora, 0, bitacora.size() - 1);
        std::vector<Info> output = binarySearch(input, bitacora);
        print(output);

    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }

    return 0;
}
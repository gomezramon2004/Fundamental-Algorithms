#include "./parse/parse.hpp"
#include "./sort/mergeSort.hpp"
#include "./search/binarySearch.hpp"
#include "./print/print.hpp"
#include <iostream>
#include <string>
#include <vector>

// Description: Sort a log info in descending order using merge sort and display all of the entries matched with the user input

// Francisco Rochín Gómez - A01252974
// Andrés Sandoval Ibarra - A01253138
// Daniel Fernández Clausen - A01254659
// Ramón Alberto Gómez Urquídez - A01254784
// September 22th, 2023

int main() {
    try {
        std::string inputTest = "4TL";
        std::vector<Info> bitacora = parse("bitacora.txt");
        mergeSort(bitacora, 0, bitacora.size() - 1);
        std::vector<Info> output = binarySearch(inputTest, bitacora);
        print(output);

    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }

    return 0;
}
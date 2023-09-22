#include "binarySearch.hpp"
#include <vector>
#include <algorithm>

// It will search if the same value exists to the left side
void searchByLeft(const std::string& input, const std::vector<Info>& vec, const int mid, std::vector<Info>& output) {
    int i = mid - 1;
    while (i >= 0 && vec[i].ubi.substr(0,3) == input) {
        output.push_back(vec[i]);
        --i;
    }
    std::reverse(output.begin(), output.end()); 
}

// It will search if the same value exists to the right side
void searchByRight(const std::string& input, const std::vector<Info>& vec, const int mid, std::vector<Info>& output) {
    int j = mid + 1;
    while (j < vec.size() && vec[j].ubi.substr(0,3) == input) {
        output.push_back(vec[j]);
        ++j;
    }
}

// Binary Search algorithm to find the data structs that they have the same value as the comparison input
std::vector<Info> binarySearch(const std::string& input, const std::vector<Info>& vec) {
    std::vector<Info> output{};
    int left{}, right = vec.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        std::string key = vec[mid].ubi.substr(0, 3);

        if (key == input) {
            searchByLeft(input, vec, mid, output); 
            output.push_back(vec[mid]);
            searchByRight(input, vec, mid, output); 
            return output;
        }

        key < input ? left = mid + 1 : right = mid - 1;
    }

    return output;
}
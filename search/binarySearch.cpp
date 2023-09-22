#include "binarySearch.hpp"
#include <vector>
#include <algorithm>

void searchByLeft(const std::string& input, const std::vector<Info>& vec, const int mid, std::vector<Info>& output) {
    int i = mid - 1;
    while (vec[i].ubi.substr(0,3) == input) {
        output.push_back(vec[i]);
        --i;
    }
    std::reverse(output.begin(), output.end());
}

void searchByRight(const std::string& input, const std::vector<Info>& vec, const int mid, std::vector<Info>& output) {
    int j = mid + 1;
    while (vec[j].ubi.substr(0,3) == input) {
        output.push_back(vec[j]);
        ++j;
    }
}

std::vector<Info> binarySearch(const std::string& input, const std::vector<Info>& vec) {
    std::vector<Info> output{};
    int left{}, right = vec.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        const std::string& key = vec[mid].ubi.substr(0, 3);

        if (key == input) {
            void searchByLeft(const std::string& input, const std::vector<Info>& vec, const int& mid, std::vector<Info>& output);
            output.push_back(vec[mid]);
            void searchByRight(const int& mid, const std::vector<Info>& vec, const std::string& key, std::vector<Info>& output);
            return output;
        }

        key < input ? left = mid + 1 : right = mid - 1;
    }

    return output;
}
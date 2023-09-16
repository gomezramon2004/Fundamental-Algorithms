#include "sequentialSearch.hpp"
#include <vector>

int busqSecuencial(const std::vector<int>& vec, int target) {
    int count{};
    for (auto &&i : vec) {
        ++count;
        if (i == target) {
            return count;
        }
    }
    return count;
}
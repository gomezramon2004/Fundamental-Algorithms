#pragma once
#include <vector>
#include "../parse/parse.hpp"

void searchByLeft(const std::string& input, const std::vector<Info>& vec, const int mid, std::vector<Info>& output);
void searchByRight(const std::string& input, const std::vector<Info>& vec, const int mid, std::vector<Info>& output);
std::vector<Info> binarySearch(const std::string& input, const std::vector<Info>& vec);
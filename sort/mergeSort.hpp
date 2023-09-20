#pragma once
#include <vector>
#include "../parse/parse.hpp"

bool compareInfoByIndUbi(const Info& info1, const Info& info2);
void merge(std::vector<Info>& vec, int left, int mid, int right);
void mergeSort(std::vector<Info>& vec, int left, int right);
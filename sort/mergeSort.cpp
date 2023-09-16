#include "mergeSort.hpp"
#include <iostream>

int merge(std::vector<int>& vec, int left, int mid, int right, int& count) {
    int n1 = mid - left + 1, n2 = right - mid;
    std::vector<int> leftvec(n1), rightvec(n2);

    for (int i = 0; i < n1; i++) {
        leftvec[i] = vec[left + i];
    }
    for (int i = 0; i < n2; i++) {
        rightvec[i] = vec[mid + 1 + i];
    }

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        count++;
        if (leftvec[i] <= rightvec[j]) {
            vec[k] = leftvec[i];
            i++;
        } else {
            vec[k] = rightvec[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        vec[k] = leftvec[i];
        i++; k++;
    }

    while (j < n2) {
        vec[k] = rightvec[j];
        j++; k++;
    }

    return count;
}

int ordenaMerge(std::vector<int>& vec, int left, int right, int& count) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        ordenaMerge(vec, left, mid, count);
        ordenaMerge(vec, mid + 1, right, count);
        return merge(vec, left, mid, right, count);
    }
    return 0;
}

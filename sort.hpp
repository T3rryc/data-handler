#ifndef SORT_HPP
#define SORT_HPP

#include <vector>
#include "data.hpp"

// Comparator functions
bool compareByPrice(const Spacecraft& a, const Spacecraft& b) {
    return a.price < b.price;
}

bool compareByName(const Spacecraft& a, const Spacecraft& b) {
    return a.brand < b.brand;
}

bool compareByMaxSpeed(const Spacecraft& a, const Spacecraft& b) {
    return a.max_speed < b.max_speed;
}

bool compareByCruiseSpeed(const Spacecraft& a, const Spacecraft& b) {
    return a.cruise_speed < b.cruise_speed;
}

bool compareByReleaseYear(const Spacecraft& a, const Spacecraft& b) {
    return a.release_year < b.release_year;
}

void merge(std::vector<Spacecraft>& spacecraft_list, int left, int mid, int right, bool (*compare)(const Spacecraft&, const Spacecraft&)) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    std::vector<Spacecraft> L(n1);
    std::vector<Spacecraft> R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = spacecraft_list[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = spacecraft_list[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (compare(L[i], R[j])) {
            spacecraft_list[k] = L[i];
            i++;
        } else {
            spacecraft_list[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        spacecraft_list[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        spacecraft_list[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(std::vector<Spacecraft>& spacecraft_list, int left, int right, bool (*compare)(const Spacecraft&, const Spacecraft&)) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(spacecraft_list, left, mid, compare);
        mergeSort(spacecraft_list, mid + 1, right, compare);

        merge(spacecraft_list, left, mid, right, compare);
    }
}

#endif // SORT_HPP
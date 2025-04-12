//
// Created by Wh1tEW0lf13 on 12.04.2025.
//

#ifndef SHELLSORT_H
#define SHELLSORT_H
#include <cmath>
#include <iostream>
#include <ostream>

#endif //SHELLSORT_H

template<typename T>
class ShellSort {
    public:
        void ShellSorting(Vector<T> *border);
};


template<typename T>
void ShellSort<T>::ShellSorting(Vector<T> *border) {
    int k = floor(sqrt(border->GetSize()));
    while (k > 0) {
        int interspace = pow(2, k) - 1;
        for (int i = 0; i < interspace; i++) {

        }
    }
}
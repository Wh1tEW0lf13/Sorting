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
    int size = border->GetSize();
    for (int interspace = size/2; interspace > 0; interspace/=2) {
        for (int i = interspace; i < size; i++) {
            T temp = border->GetValue(i);
            int j;
            for (j = i; j >= interspace && temp < border->GetValue(j - interspace); j-= interspace) {
                border->ChangeValue(j, border->GetValue(j - interspace));
            }
            border->ChangeValue(j, temp);
        }
    }
}
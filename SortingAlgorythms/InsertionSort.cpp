//
// Created by Wh1tEW0lf13 on 04.04.2025.
//

#include "InsertionSort.h"

#include "../Vector.h"

template<typename T>
void InsertSorting(Vector<T> *border) {
    for (int i = 1; i<border.GetSize(); i++) {
        int j = i - 1;
        while (j >= 0) {
            if (border[j] > border[j+1]) {
                int temp = border[j];
                border[j] = border[j+1];
                border[j+1] = temp;
                j--;
            }
            else
                break;
        }
    }
}

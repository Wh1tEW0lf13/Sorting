//
// Created by Wh1tEW0lf13 on 04.04.2025.
//
#include "../Vector.h"
#ifndef QUICKSORT_H
#define QUICKSORT_H

template<typename T>
class QuickSort {
public:
    static void QuickSorting(Vector<T> *border);
private:
    static void Split(Vector<T> *border, int left, int right);
};

    template<typename T>
    void QuickSort<T>::Split(Vector<T> *border, int left, int right) {
        int pivot = (left+right)/2;
        int j;
        T pivotValue = border->GetValue(pivot);
        T temp = border->GetValue(right);
        border->ChangeValue(right, pivotValue);
        border->ChangeValue(pivot, temp);
        for (int i = j = left; i < right; i++) {
            if (border->GetValue(i) < pivotValue) {
                temp = border->GetValue(j);
                border->ChangeValue(j, border->GetValue(i));
                border->ChangeValue(i, temp);
                j++;
            }
        }
        border->ChangeValue(right, border->GetValue(j));
        border->ChangeValue(j, pivotValue);
        if (left < j - 1)
            Split(border, left, j-1);
        if (right > j + 1)
            Split(border, j+1, right);
    }


    template<typename  T>
    void QuickSort<T>::QuickSorting(Vector<T> *border) {
        Split(border, 0, border->GetSize()-1);
    }


#endif //QUICKSORT_H

//
// Created by Wh1tEW0lf13 on 11.04.2025.
//

#ifndef HEAPIFYSORT_H
#define HEAPIFYSORT_H
#include "../Vector.h"
#endif //HEAPIFYSORT_H
template<typename T>
class HeapifySort {
    public:
    static void HeapifySorting(Vector<T> *myBorder);
private:
};

template<typename T>
void heapify(Vector<T> *border, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && border->GetValue(left) > border->GetValue(largest))
        largest = left;

    if (right < n && border->GetValue(right) > border->GetValue(largest))
        largest = right;

    if (largest != i) {
        T temp = border->GetValue(i);
        border->ChangeValue(i, border->GetValue(largest));
        border->ChangeValue(largest, temp);
        heapify(border, n, largest);
    }
}

template<typename T>
void HeapifySort<T>::HeapifySorting(Vector<T> *myBorder) {
    int n = myBorder->GetSize();

    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(myBorder, n, i);
    }
    for (int i = n - 1; i > 0; i--) {
        T temp = myBorder->GetValue(i);
        myBorder->ChangeValue(i, myBorder->GetValue(0));
        myBorder->ChangeValue(0, temp);
        heapify(myBorder, i, 0);
    }
}
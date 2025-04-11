//
// Created by Wh1tEW0lf13 on 11.04.2025.
//
#include "../Vector.h"
#ifndef HEAPIFYSORT_H
#define HEAPIFYSORT_H

#endif //HEAPIFYSORT_H
template<typename T>
class HeapifySort {
    public:
    static void HeapifySorting(Vector<T> *myBorder);
private:
};

template<typename T>
void HeapifySort<T>::HeapifySorting(Vector<T> *myBorder) {
    int size = myBorder->GetSize();
    Vector<T> noSorted;
    for (int i = 0; i < size; i++) {
        noSorted.Add(myBorder->GetValue(i));
    }
    int n = size;
    while (n > 2) {
        for (int i = 1; i<n; i++) {
            int son = i; int parent = son / 2;
            int value = noSorted.GetValue(i);
            while ((parent > 0) && (value > noSorted.GetValue(parent))) {
                noSorted.ChangeValue(son,noSorted.GetValue(parent));
                son = parent; parent = son/2;
            }
            noSorted.ChangeValue(son,value);
            if (noSorted.GetValue(1)>noSorted.GetValue(2)) {
                if (noSorted.GetValue(0)<noSorted.GetValue(1)) {
                    T temp = noSorted.GetValue(0);
                    noSorted.ChangeValue(0, noSorted.GetValue(1));
                    noSorted.ChangeValue(1, temp);
                }
            }
            else
                if (noSorted.GetValue(0)<noSorted.GetValue(2)) {
                    T temp = noSorted.GetValue(0);
                    noSorted.ChangeValue(0, noSorted.GetValue(2));
                    noSorted.ChangeValue(2, temp);
                }
        }
        --n;
        T temp = noSorted.GetValue(0);
        noSorted.ChangeValue(0, noSorted.GetValue(n));
        noSorted.ChangeValue(n, temp);
        myBorder -> ChangeValue(n, noSorted.GetValue(n));
        noSorted.Remove(n);
    }
    if (noSorted.GetValue(0)>noSorted.GetValue(1)) {
        noSorted.ChangeValue(0, noSorted.GetValue(1));
        myBorder -> ChangeValue(1, noSorted.GetValue(0));
    }
    else {
        myBorder -> ChangeValue(0, noSorted.GetValue(0));
        myBorder -> ChangeValue(1, noSorted.GetValue(1));
    }
}
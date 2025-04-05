//
// Created by Wh1tEW0lf13 on 04.04.2025.
//

#ifndef INSERTIONSORT_H
#define INSERTIONSORT_H
#include "../Vector.h"

template<typename T>
class InsertionSort {
public:
   static void InsertionSorting(Vector<T> *border);
};

template<typename T>
void InsertionSort<T>::InsertionSorting(Vector<T> *border) {
   for (int i = 1; i<border->GetSize(); i++) {

      int j = i-1;
      while (j >= 0) {
         if (border->GetValue(j) > border->GetValue(j+1)) {
            int temp = border->GetValue(j);
            border->ChangeValue(j,border->GetValue(j+1));
            border->ChangeValue(j+1,temp);
            j--;
        }
         else
            break;
      }
   }
}

#endif //INSERTIONSORT_H

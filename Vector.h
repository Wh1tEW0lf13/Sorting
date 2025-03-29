//
// Created by Wh1tEW0lf13 on 19.03.2025.
//
#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include <cstdlib>
template <typename T>
class Vector {
private:
    T* border;
    size_t size;    //Size of the border
    size_t newPosition; //New value position
    void resize();
public:
    void InsertSort();

    Vector();
    ~Vector();
    void add(const T& value);
    [[nodiscard]] size_t getSize() const;

    T fillRandom(int size);

    T getValue(int index) const;
};

template<typename T>
void Vector<T>::InsertSort() {
    for (int i = 1; i<size; i++) {
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

template<typename T>
Vector<T>::Vector() {
    this -> size = 0;   //Border size
    this -> newPosition = 0;
    border = new T[size];   //Here I create new border.
}

template<typename T>
Vector<T>::~Vector() {
    delete[] border;    //Destroy border
}

template<typename T>
void Vector<T>::add(const T &value) {
    resize();
    border[this->newPosition] = value;
    ++this->newPosition;
}

template<typename T>
void Vector<T>::resize() {  //Here I increase size of the border, to put new value here
    size++;
    T* newBorder = new T[size];
    for (size_t i = 0; i < size; i++) {
        newBorder[i] = border[i];
    }
    delete[] border;
    border = newBorder;
}

template<typename T>
T Vector<T>::getValue(int index) const {    //Getting value here
    if (index>=size) {
        std::cout<<"IndexOutOfBoundException";
        exit(-2137);
    }
    return border[index];
}

template<typename T>
size_t Vector<T>::getSize() const {   //Simple getter for size
    return size;
}

template<typename T>
T Vector<T>::fillRandom(const int size) {   //It fills randomly the border with random values
    srand(time(nullptr));
    for (int i = 0; i < size; i++) {
        add(rand() % size);
    }
    return 0;
}

#endif
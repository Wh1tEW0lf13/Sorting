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
    void Resize();
public:

    Vector();
    ~Vector();
    void Add(const T& value);
    [[nodiscard]] size_t GetSize() const;

    T FillRandom(int size);

    void ChangeValue(int pointer);

    T GetValue(int index) const;
};

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
void Vector<T>::Add(const T &value) {
    Resize();
    border[this->newPosition] = value;
    ++this->newPosition;
}

template<typename T>
void Vector<T>::Resize() {  //Here I increase size of the border, to put new value here
    size++;
    T* newBorder = new T[size];
    for (size_t i = 0; i < size; i++) {
        newBorder[i] = border[i];
    }
    delete[] border;
    border = newBorder;
}

template<typename T>
T Vector<T>::GetValue(int index) const {    //Getting value here
    if (index>=size) {
        std::cout<<"IndexOutOfBoundException";
        exit(-2137);
    }
    return border[index];
}

template<typename T>
size_t Vector<T>::GetSize() const {   //Simple getter for size
    return size;
}

template<typename T>
T Vector<T>::FillRandom(const int size) {   //It fills randomly the border with random values
    srand(time(nullptr));
    for (int i = 0; i < size; i++) {
        Add(rand() % size);
    }
    return 0;
}
template<typename T>
void Vector<T>::ChangeValue(int pointer) {

}

#endif
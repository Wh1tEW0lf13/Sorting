//
// Created by Wh1tEW0lf13 on 19.03.2025.
//
#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include <random>
#include <limits>
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

    void ChangeValue(int pointer, T value);

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
    std::random_device rd;
    std::mt19937 gen(rd());
    for (int i = 0; i < size; i++) {
        if (std::is_same_v<T, int>) {
            std::uniform_int_distribution<> dis(std::numeric_limits<int>::denorm_min(), std::numeric_limits<int>::max());
            Add(dis(gen));
        }
        else if (std::is_same_v<T, float>) {
            std::uniform_real_distribution<> dis(std::numeric_limits<float>::denorm_min(), std::numeric_limits<float>::max());
            Add(dis(gen));
        }
        else if (std::is_same_v<T, double>) {
            std::uniform_real_distribution<> dis(std::numeric_limits<double>::denorm_min(), std::numeric_limits<double>::max());
            Add(dis(gen));
        }
        else if (std::is_same_v<T, char>) {
            std::uniform_real_distribution<> dis(std::numeric_limits<char>::denorm_min(), std::numeric_limits<char>::max());
            Add(dis(gen));
        }
        else
            std::cout<<"Bad type";
    }

    return 0;
}
template<typename T>
void Vector<T>::ChangeValue(int pointer, T value) {
    border[pointer] = value;
}

#endif
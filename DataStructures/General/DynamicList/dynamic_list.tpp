#pragma once
#include "dynamic_list.h"



// Utility functions
template<typename T>
void dynamic_list<T>::grow() {
    T* newData = new T[capacity * 2];
    for (int i = 0; i < size; i++) {
        newData[i] = data[i];
    }
    capacity *= 2;
    delete[] data;
    data = newData;
}
template<typename T>
void dynamic_list<T>::shrink() {
    if (capacity < CAPACITY) return; // Do not shrink if too small

    T* newData = new T[capacity / 2];
    for (int i = 0; i < size; i++) {
        newData[i] = data[i];
    }
    capacity /= 2;
    delete[] data;
    data = newData;
}




// Constructors
template<typename T>
dynamic_list<T>::dynamic_list() : data(nullptr), size(0), capacity(CAPACITY) { data = new T[capacity]; }  // O(1)

template<typename T>
dynamic_list<T>::dynamic_list(const dynamic_list &list) : size(list.size), capacity(list.capacity) {  // O(n)
    data = new T[capacity];
    for (int i = 0; i < size; i++) {
        data[i] = list.data[i];
    }
}

template<typename T>
dynamic_list<T>::dynamic_list(std::vector<T> v) : size(v.size()), capacity(v.capacity()) {  // O(n)
    data = new T[capacity];
    for (int i = 0; i < size; i++) {
        data[i] = v[i];
    }
}


// Add/Delete
template<typename T>
void dynamic_list<T>::append(T value) {  // O(1)
    if (size == capacity) {
        grow();
    }
    data[size++] = value;
}
template<typename T>
void dynamic_list<T>::prepend(T value) {  // O(n)
    size++;
    if (size == capacity) {
        grow();
    }
    for (int i = size - 1; i > 0; i--) {
        data[i] = data[i - 1];
    }
    data[0] = value;
}
template<typename T>
T dynamic_list<T>::pop() {
    if (is_empty()) {
        std::cerr << "List is empty!" << std::endl;
        exit(-1);
    }
    T returnVal = data[--size];
    if (size < capacity / 2) { shrink(); }
    return returnVal;
}
template<typename T>
void dynamic_list<T>::insert(T value, int index) {
    if (index < 0 || index > size) {
        std::cerr << "Index out of range!" << std::endl;
        exit(-1);
    }
    size++;
    if (size == capacity) grow();
    for (int i = size; i > index; i--) {
        data[i] = data[i - 1];
    }
    data[index] = value;
}
template<typename T>
void dynamic_list<T>::remove(T value) {
    for (int i = 0; i < size; i++) {
        if (data[i] == value) {
            for (int j = i; j < size; j++)
                data[j] = data[j + 1];
            size--;
            if (size < capacity / 2) shrink();
            return;
        }
    }
    std::cerr << "Value " << value << " does not exist in list!" << std::endl;
    exit(-1);
}


// Whole List operations
template<typename T>
void dynamic_list<T>::reverse() {
    size_t start = 0, end = size - 1;

    while (start < end) {
        T temp = data[start];
        data[start] = data[end];
        data[end] = temp;
        start++;
        end--;
    }
}
template<typename T>
void dynamic_list<T>::clear() {
    delete[] data;
    size = 0;
    capacity = CAPACITY;
    data = new T[capacity];
}


// Small functions
template<typename T>
bool dynamic_list<T>::contains(T value) const {
    for (int i = 0; i < size; i++)
        if (data[i] == value)
            return true;
    return false;
}
template<typename T>
bool dynamic_list<T>::is_empty() const {
    return size == 0;
}
template<typename T>
size_t dynamic_list<T>::count(T value) const {
    size_t count = 0;
    for (int i = 0; i < size; ++i) {
        if (data[i] == value) count++;
    }
    return count;
}
template<typename T>
int dynamic_list<T>::index(T value) const {
    for (int i = 0; i < size; ++i)
        if (data[i] == value) return i;
    return -1;
}


// Getters
template<typename T>
size_t dynamic_list<T>::get_size() const { return size; }
template<typename T>
size_t dynamic_list<T>::get_capacity() const { return capacity; }


// Assignment operator
template<typename T>
dynamic_list<T> &dynamic_list<T>::operator=(const dynamic_list& list) {
    if (this == &list) { return *this; }

    delete[] data;
    size = list.size;
    capacity = list.capacity;
    data = new T[capacity];
    for (int i = 0; i < size; i++) {
        data[i] = list.data[i];
    }
    return *this;
}

// Comparison Operators
template<typename T>
bool dynamic_list<T>::operator==(const dynamic_list &list) const {
    for (int i = 0; i < size && i < list.size; i++)
        if (data[i] != list.data[i]) return false;
    return true;
}
template<typename T>
bool dynamic_list<T>::operator!=(const dynamic_list &list) const {
    for (int i = 0; i < size && i < list.size; i++)
        if (data[i] != list.data[i]) return true;
    return false;
}

// Indexing operator
template<typename T>
T& dynamic_list<T>::operator[](int index) const {
    if (index < 0 || index >= size) {
        std::cerr << "Index out of bounds!" << std::endl;
        exit(-1);
    }
    return data[index];
}



// Input & Output
template<typename T>
std::ostream &operator<<(std::ostream &os, const dynamic_list<T> &list) {
    os << "[";
    for (int i = 0; i < list.size; i++) {
        if (i != 0) os << ", ";
        os << list.data[i];
    }

    os << "]";
    return os;
}
template<typename T>
std::istream& operator>>(std::istream& is, dynamic_list<T>& list) {
    list.clear();

    std::string line;
    if (!std::getline(is, line)) return is;

    std::istringstream iss(line);
    T value;
    while (iss >> value) {
        list.append(value);
    }

    return is;
}






// Destructor
template<typename T>
dynamic_list<T>::~dynamic_list() {
    delete[] data;
}


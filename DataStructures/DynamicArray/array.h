#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
#include <string>
#include <vector>

using std::vector;

template <typename T>
class Array
{
private:
    vector<T> array;

public:
    Array();
    Array(vector<T> &);

    // Append
    void append(T);
    // Count
    size_t count(T);
    // Index of some value
    int index(T);
    // Copy -> Return Copy of Array
    Array copy();
    // Insert -> at certain position
    bool insert(size_t, T);
    // Pop -> Pop last element
    T pop();
    // Remove -> Certain element
    void remove(T);
    // Reverse
    void reverse();
    // Sort
    void sort();
    // Clear
    void clear();

    // Contains
    bool contains(T);
    // Empty
    bool isEmpty();
    // Size
    size_t getSize();
    // GetItem []
    T get(size_t);
    // Capacity
    size_t getCapacity();
    // Equals
    bool equals(const Array);

    // Special Methods
    template <typename U>
    friend std::ostream &operator<<(std::ostream &, Array<U> &);
};

#include "Array.cpp"

#endif
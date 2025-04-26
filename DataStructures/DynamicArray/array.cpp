#ifndef ARRAY_CPP
#define ARRAY_CPP

#include "Array.h"
#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

// Constructors
template <typename T>
Array<T>::Array() { array = vector<T>{}; }

template <typename T>
Array<T>::Array(vector<T> &arr) { array = arr; }

// Append
template <typename T>
void Array<T>::append(T value) { array.push_back(value); }

// Count
template <typename T>
size_t Array<T>::count(T value)
{
    size_t total = 0;
    for (T el : array)
        if (el == value)
            total++;
    return total;
}

// Index of Value
template <typename T>
int Array<T>::index(T value)
{
    for (int i = 0; i < array.size(); i++)
        if (array[i] == value)
            return i;
    return -1;
}

// Copy
template <typename T>
Array<T> Array<T>::copy() { return Array<T>(array); }

// Insert
template <typename T>
bool Array<T>::insert(size_t index, T value)
{
    if (index < 0 || index > array.size())
        return false;
    array.insert(array.begin() + index, value);
    return true;
}

// Pop
template <typename T>
T Array<T>::pop()
{
    if (array.empty())
        throw std::runtime_error("Array is empty! IN pop..");
    else
    {
        T el = array[array.size() - 1];
        array.pop_back();
        return el;
    }
}

// Remove
template <typename T>
void Array<T>::remove(T element)
{
    auto pos = std::find(array.begin(), array.end(), (T)element);
    if (pos != array.end())
        array.erase(pos);
    // Remove all occurences
    // array.erase(std::remove(array.begin(), array.end(), element), array.end());
}

// Reverse
template <typename T>
void Array<T>::reverse()
{
    if (!isEmpty())
    {
        size_t start = 0;
        size_t end = getSize() - 1;
        while (start < end)
        {
            T temp = array[start];
            array[start] = array[end];
            array[end] = temp;
            start++;
            end--;
        }
    }
}

// Sort
template <typename T>
void Array<T>::sort()
{
    for (size_t i = 0; i < array.size(); i++)
    {
        for (size_t j = 0; j < array.size() - i - 1; j++)
        {
            if (array[j] > array[j + 1])
            {
                auto temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

// Clear
template <typename T>
void Array<T>::clear()
{
    array.clear();
}

// Contains
template <typename T>
bool Array<T>::contains(T element)
{
    for (T el : array)
        if (el == element)
            return true;
    return false;
}

// Empty
template <typename T>
bool Array<T>::isEmpty() { return getSize() == 0; }

// Size
template <typename T>
size_t Array<T>::getSize() { return array.size(); }

// GetItem
template <typename T>
T Array<T>::get(size_t index)
{
    if (index < 0 || index > array.size())
        throw std::out_of_range("Index out of bounds!");
    return array[index];
}

// Capacity
template <typename T>
size_t Array<T>::getCapacity() { return array.capacity(); }

// Equals
template <typename T>
bool Array<T>::equals(const Array ar)
{
    return array == ar.array;
}

// Display
template <typename T>
std::ostream &operator<<(std::ostream &os, Array<T> &ar)
{
    os << "[";
    for (size_t i = 0; i < ar.getSize(); i++)
        os << ar.array[i] << ", ";
    os << "]" << std::endl;
    return os;
}

#endif
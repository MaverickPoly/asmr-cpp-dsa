#pragma once
#include <stdexcept>

#include "queue.h"



template<typename T>
queue<T>::queue() : head(nullptr), size(0) {}


template<typename T>
void queue<T>::push(T value) {
    auto *newNode = new node<T>;
    newNode->value = value;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;
    } else {
        auto current = head;

        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }
    size++;
}


template<typename T>
T queue<T>::pop() {
    if (head == nullptr) {
        throw std::runtime_error("The queue is empty!");
    }
    T returnValue = peek();

    auto temp = head;
    head = head->next;
    delete temp;

    size--;
    return returnValue;
}
template<typename T>
T queue<T>::peek() {
    if (head == nullptr) {
        throw std::runtime_error("The queue is empty!");
    }
    return head->value;
}

template<typename T>
unsigned queue<T>::get_size() const {
    return size;
}
template<typename T>
bool queue<T>::is_empty() const {
    return size == 0;
}
template<typename T>
bool queue<T>::contains(T value) {
    node<T> *current = head;

    while (current != nullptr) {
        if (current->value == value)
            return true;
        current = current->next;
    }
    return false;
}


template <typename T>
std::ostream& operator<<(std::ostream& os, const queue<T>& q) {
    auto current = q.head;
    while (current != nullptr) {
        os << *current << " <- ";
        current = current->next;
    }
    return os;
}


template<typename T>
queue<T>::~queue() {
    auto current = head;
    while (current != nullptr) {
        auto temp = current;
        current = current->next;
        delete temp;
    }
}

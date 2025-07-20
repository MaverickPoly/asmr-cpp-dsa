#include "stack.h"

#include <stdexcept>


template<typename T>
stack<T>::stack() : top(nullptr), size(0) {}

template<typename T>
stack<T>::stack(T arr[], int size) {
    for (int i = size - 1; i >= 0; i++) {
        push(arr[i]);
    }
}


template<typename T>
void stack<T>::push(T element) {
    auto *newNode = new node<T>;
    newNode->next = top;
    newNode->value = element;
    top = newNode;
    size++;
}
template<typename T>
T stack<T>::pop() {
    if (top == nullptr) {
        throw std::runtime_error("Stack is empty");
    }
    T returnVal = peek();
    const node<T> *temp = top;
    top = top->next;
    size--;
    delete temp;
    return returnVal;
}
template<typename T>
T stack<T>::peek() {
    if (top == nullptr) {
        throw std::runtime_error("Stack is empty");
    }
    return top->value;
}


template<typename T>
bool stack<T>::isEmpty() const {
    return size == 0;
}


template<typename T>
unsigned stack<T>::get_size() const {
    return size;
}




template <typename T>
std::ostream& operator<<(std::ostream &os, const stack<T> &stack) {
    node<T> *current = stack.top;

    while (current != nullptr) {
        os << *current << " -> ";
        current = current->next;
    }
    return os;
}


template<typename T>
stack<T>::~stack() {
    std::cout << "Deleting stack..." << std::endl;
    auto current = top;
    while (current != nullptr) {
        auto temp = current;
        current = current->next;
        delete temp;
    }
}





#include "linked_list.h"

#include <stdexcept>


// Constructors
template<typename T>
linked_list<T>::linked_list() : head(nullptr), size(0) {}

template<typename T>
linked_list<T>::linked_list(const T arr[], const unsigned length) : head(nullptr), size(0) {
    for (unsigned i = 0; i < length; i++) {
        append(arr[i]);
    }
}


// Add
template<typename T>
void linked_list<T>::prepend(const T value) {
    node<T>* newNode = new node<T>;
    newNode->value = value;

    newNode->next = head;
    head = newNode;
    size++;
}
template<typename T>
void linked_list<T>::append(const T value) {
    if (head == nullptr) {
        prepend(value);
    } else {
        node<T>* newNode = new node<T>;
        newNode->value = value;
        newNode->next = nullptr;
        node<T>* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
        size++;
    }
}
template<typename T>
void linked_list<T>::insert(const unsigned pos, const T value) {
    if (pos > size) {
        throw std::out_of_range("Position out of range");
    }
    if (pos == 0) {
        prepend(value);
        return;
    }
    if (pos == size) {
        append(value);
        return;
    }

    node<T>* newNode = new node<T>;
    newNode->value = value;

    node<T>* current = head;
    unsigned i = 0;
    while (i + 1 != pos) {
        current = current->next;
        i++;
    }

    newNode->next = current->next;
    current->next = newNode;
    size++;
}



// Deletion
template<typename T>
T linked_list<T>::pop() {
    if (is_empty()) {
        throw std::out_of_range("The linked list is empty");
    }
    T returnValue = last();
    if (size == 1) {
        delete head;
        head = nullptr;
    } else {
        node<T>* current = head;

        while (current->next->next != nullptr) {
            current = current->next;
        }
        delete current->next;
        current->next = nullptr;
    }

    size--;
    return returnValue;
}
template<typename T>
T linked_list<T>::remove(unsigned index) {
    if (index >= size) {
        throw std::out_of_range("Index out of range");
    }
    if (index == 0) {
        T returnVal = head->value;
        const node<T>* temp = head;
        head = head->next;
        delete temp;
        size--;
        return returnVal;
    }

    node<T>* current = head;
    unsigned i = 0;
    while (i < index - 1) {
        current = current->next;
        i++;
    }
    T returnVal = current->next->value;
    const node<T>* temp = current->next;
    current->next = current->next->next;
    delete temp;
    size--;
    return returnVal;
}




// Look up
template<typename T>
T linked_list<T>::first() {
    return head->value;
}
template<typename T>
T linked_list<T>::last() {
    if (size == 0) {
        throw std::out_of_range("List is empty");
    }
    node<T>* current = head;

    while (current->next != nullptr) {
        current = current->next;
    }
    return current->value;
}




// Utils
template<typename T>
bool linked_list<T>::is_empty() const {
    return size == 0;
}
template<typename T>
unsigned linked_list<T>::get_size() const {
    return size;
}
template<typename T>
bool linked_list<T>::contains(const T value) const {
    node<T>* current = head;

    while (current != nullptr) {
        if (current->value == value) {
            return true;
        }
        current = current->next;
    }
    return false;
}
template<typename T>
void linked_list<T>::clear() {
    node<T>* current = head;
    while (current != nullptr) {
        node<T>* temp = current;
        current = current->next;
        delete temp;
    }
    head = nullptr;
    size = 0;
}



// Operators
template<typename T>
T linked_list<T>::operator[](const unsigned index) const {
    if (index >= size) {
        throw std::out_of_range("Index out of range");
    }

    node<T>* current = head;
    unsigned i = 0;
    while (i != index) {
        current = current->next;
        i++;
    }
    return current->value;
}
template<typename T>
linked_list<T> &linked_list<T>::operator=(const linked_list &other) {
    if (this == &other) return *this;
    clear();
    for (int i = other.size; i >= 0; ++i) {
        prepend(other[i]);
    }
    return *this;
}


template <typename T>
std::ostream& operator<<(std::ostream& os, const linked_list<T>& ll) {
    node<T>* current = ll.head;
    while (current != nullptr) {
        os << current->value << " -> ";
        current = current->next;
    }
    return os;
}


// Destructure
template<typename T>
linked_list<T>::~linked_list() {
    clear();
}


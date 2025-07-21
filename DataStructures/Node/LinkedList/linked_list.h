#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#include <iosfwd>

#include "../Node/node.h"


template <typename T>
class linked_list {
node<T>* head;
unsigned size;

public:
    linked_list();
    linked_list(const T arr[], const unsigned length);

    // Add
    void append(const T value);
    void prepend(const T value);
    void insert(const unsigned pos, const T value);

    // Deletion
    T pop();
    T remove(unsigned index);  // Delete the element at the index

    // Look up
    T first();
    T last();

    // Utils
    bool is_empty() const;
    unsigned get_size() const;
    bool contains(const T value) const;
    void clear();

    T operator[](const unsigned index) const;

    linked_list& operator=(const linked_list& other);

    template <typename U>
    friend std::ostream& operator<<(std::ostream& os, const linked_list<U>& ll);

    ~linked_list();
};


#include "linked_list.tpp"


#endif

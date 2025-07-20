#ifndef STACK_H
#define STACK_H
#include <iosfwd>

#include "../Node/node.h"


template<typename T>
class stack {
private:
    node<T>* top;
    unsigned size;

public:
    stack();
    stack(T arr[], int size);

    void push(T element);
    T pop();
    T peek();

    bool isEmpty() const;
    unsigned get_size() const;

    template <typename U>
    friend std::ostream& operator<<(std::ostream& os, const stack<U> &stack);

    ~stack();
};


#include "stack.tpp"
#endif
#ifndef NODE_H
#define NODE_H


template<typename T>
class node {
public:
    T value;
    node* next;

    friend std::ostream& operator<<(std::ostream &os, const node<T> &node) {
        return os << node.value;
    }
};


#endif
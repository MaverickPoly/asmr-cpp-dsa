#ifndef QUEUE_H
#define QUEUE_H
#include <iosfwd>

#include "../Node/node.h"


template <typename T>
class queue {
    node<T>* head;
    unsigned size;

public:
    queue();

    void push(T value);
    T pop();
    T peek();

    [[nodiscard]] unsigned get_size() const;
    [[nodiscard]] bool is_empty() const;
    bool contains(T value);

    template <typename U>
    friend std::ostream& operator<<(std::ostream& os, const queue<U>& q);

    ~queue();
};


#include "queue.tpp"


#endif //QUEUE_H

#ifndef DYNAMIC_LIST_H
#define DYNAMIC_LIST_H

#include <iosfwd>
#include <vector>
#include <iostream>
#include <sstream>

#define CAPACITY 10

template <typename T>
class dynamic_list {

    T* data = nullptr;
    size_t size;
    size_t capacity;

    void grow();
    void shrink();

public:
    dynamic_list();
    dynamic_list(const dynamic_list& list);
    explicit dynamic_list(std::vector<T> v);

    void append(T value);
    void prepend(T value);
    T pop();
    void insert(T value, int index);
    void remove(T value);

    void reverse();
    void clear();

    bool contains(T value) const;
    [[nodiscard]] bool is_empty() const;
    size_t count(T value) const; // Number of occurrences of value;
    int index(T value) const; // First index of value in list

    [[nodiscard]] size_t get_size() const;
    [[nodiscard]] size_t get_capacity() const;

    dynamic_list& operator=(const dynamic_list& list);

    bool operator==(const dynamic_list &) const;
    bool operator!=(const dynamic_list &) const;
    T& operator[](int index) const;

    template <typename U>
    friend std::ostream &operator<<(std::ostream &os, const dynamic_list<U> &list);
    template <typename U>
    friend std::istream& operator>>(std::istream& is, dynamic_list<U>& list);

    ~dynamic_list();
};

#include "dynamic_list.tpp"


#endif

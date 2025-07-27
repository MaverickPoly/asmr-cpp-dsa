#ifndef STR_H
#define STR_H

#include <iosfwd>
#include <vector>
#include <cstring>
#include <iostream>


#define CAPACITY 10


class str {
    char* _data{nullptr};
    size_t _size{0};
    size_t _capacity{0};

    void grow();
    void shrink();
    void from_nums(const std::string& s);
public:
    // Initializers
    str();
    str(char *);
    explicit str(int& number);
    explicit str(double& number);
    explicit str(long& number);
    explicit str(long long& number);
    explicit str(char& character);

    // Cases
    void upper() const;
    void lower() const;
    void title() const;

    void strip();
    void rstrip();
    void lstrip();
    [[nodiscard]] size_t replace(char c1, char c2) const;
    [[nodiscard]] str substr(int a, int b) const;
    void ljust(char c, int n);
    void rjust(char c, int n);

    std::vector<str> split(char c) const;

    [[nodiscard]] size_t count(char c) const;
    [[nodiscard]] int index(char c) const;

    // Booleans
    [[nodiscard]] bool is_empty() const;
    [[nodiscard]] bool ends_with(str s) const;
    [[nodiscard]] bool starts_with(str s) const;
    [[nodiscard]] bool contains(str s) const;

    // Is ..
    [[nodiscard]] bool islower() const;
    [[nodiscard]] bool isupper() const;
    [[nodiscard]] bool istitle() const;
    [[nodiscard]] bool isalpha() const;
    [[nodiscard]] bool isalnum() const;
    [[nodiscard]] bool isdecimal() const;
    [[nodiscard]] bool isdigit() const;
    [[nodiscard]] bool isspace() const;

    // Getters
    size_t size() const;
    size_t capacity() const;
    char* data() const;

    // Inserting & Removing & Getting & Setting
    void set(int index, char c) const;
    [[nodiscard]] char get(int index) const;
    void remove(int index);
    void insert(int index, char c);


    // Arithmetic Operators
    str operator+(const str& string) const;
    str& operator+=(const str& string) const;
    str& operator*(unsigned n);
    str& operator*=(unsigned n);

    // Equal
    bool operator==(const str& string) const;
    bool operator!=(const str& string) const;

    // Assignment
    str& operator=(const str& string);

    // Indexing operator
    char operator[](int index) const;

    // Output operator
    friend std::ostream& operator<<(std::ostream& os, const str& str);

    // Destructure
    ~str();
};


#endif //STR_H

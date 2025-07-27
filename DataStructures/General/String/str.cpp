#include "str.h"

#include <string>



// Private Utilities
void str::grow() {
    _capacity *= 2;
    char *newData = new char[_capacity];
    for (int i = 0; i < _size; ++i)
        newData[i] = _data[i];
    delete[] _data;
    _data = newData;
}
void str::shrink() {
    _capacity = _capacity / 2 + 1;
    char *newData = new char[_capacity];
    for (int i = 0; i < _size; ++i)
        newData[i] = _data[i];
    delete[] _data;
    _data = newData;
}

void str::from_nums(const std::string& s) {
    _size = s.size();
    _capacity = _size * 2;
    _data = new char[_capacity];

    for (int i = 0; i < _size; i++) {
        _data[i] = s[i];
    }
    _data[_size++] = '\0';
}





// Initializers
str::str() : _size(1), _capacity(CAPACITY) {
    _data = new char[_capacity];
    _data[0] = '\0';
}
str::str(char *text) {
    const size_t len = strlen(text);
    _size = len + 1;
    _capacity = len * 2;
    _data = new char[_capacity];
    for (int i = 0; i < len; i++) {
        _data[i] = text[i];
    }
    _data[len] = '\0';
}

str::str(int &number) {
    const std::string s = std::to_string(number);
    from_nums(s);
}
str::str(double &number) {
    const std::string s = std::to_string(number);
    from_nums(s);
}
str::str(long &number) {
    const std::string s = std::to_string(number);
    from_nums(s);
}
str::str(long long &number) {
    const std::string s = std::to_string(number);
    from_nums(s);
}
str::str(char &character) : _size(1), _capacity(CAPACITY) {
    _data = new char[_capacity];
    _data[0] = character;
}




// String Cases
void str::upper() const {
    for (int i = 0; i < _size; ++i)
        _data[i] = static_cast<char>(toupper( _data[i]));
}

void str::lower() const {
    for (int i = 0; i < _size; ++i)
        _data[i] = static_cast<char>(tolower( _data[i]));
}

void str::title() const {
    bool newWord = true;

    for (int i = 0; i < _size; ++i) {
        if (::isspace(_data[i])) {
            newWord = true;
        } else {
            if (newWord) {
                _data[i] = static_cast<char>(toupper(_data[i]));
                newWord = false;
            } else {
                _data[i] = static_cast<char>(tolower(_data[i]));
            }
        }
    }
}




// Main Functions
void str::strip() { rstrip(); lstrip(); }

void str::rstrip() {
    // newSize - number of spaces skipped
    // j - number of characters left
    if (_size <= 1) return;

    int j = static_cast<int>(_size) - 2;
    while (j >= 0 && ::isspace(_data[j])) {
        j--;
    }
    // ""
    // 'trail   '
    const size_t newSize = j + 2;
    char* newData = new char[newSize];
    for (int i = 0; i < newSize - 1; i++) {
        newData[i] = _data[i];
    }
    newData[newSize - 1] = '\0';
    delete[] _data;
    _data = newData;
    _size = newSize;

    if (_size < _capacity / 2) {shrink();}
}

void str::lstrip() {
    // j - number of spaces skipped
    // newSize = number of non-space characters

    if (_size <= 1) return;

    // "   lead\0"
    // _size = 8
    // j -> 3
    int j = 0;
    while (j < _size && ::isspace(_data[j])) {
        j++;
    }
    size_t newSize = _size - j;
    char* newData = new char[newSize];
    for (int i = 0; i < newSize; i++) {
        newData[i] = _data[j + i];
    }
    newData[newSize - 1] = '\0';
    delete[] _data;
    _data = newData;
    _size = newSize;

    if (_size < _capacity / 2) {shrink();}
}

size_t str::replace(const char c1, const char c2) const { // Replace c1 with c2
    size_t total = 0;
    for (int i = 0; i < _size; i++) {
        if (_data[i] == c1) {
            _data[i] = c2;
            total++;
        }
    }
    return total;
}

str str::substr(int a, int b) const {
    if (a < 0 || b >= _size || a >= b) {
        std::cerr << "Substr: indexes out of range!" << std::endl;
        exit(-1);
    }
    // 0-5
    size_t newSize = b - a;
    char* newData = new char[newSize + 1];
    for (int i = a; i < newSize; i++) {
        newData[i] = _data[i - a];
    }
    newData[newSize] = '\0';
    return newData;
}

void str::ljust(char c, int n) {
    if (n <= 0) return;
    const size_t newSize = _size + n;
    const size_t newCapacity = newSize * 2;
    char* newData = new char[newCapacity];
    for (int i = 0; i < _size - 1; i++) {
        newData[i] = _data[i];
    }
    for (int i = 0; i < n; i++) {
        newData[_size + i - 1] = c;
    }
    newData[newSize - 1] = '\0';
    _size = newSize;
    _capacity = newCapacity;
    delete[] _data;
    _data = newData;
}

void str::rjust(char c, int n) {
    if (n <= 0) return;
    const size_t newSize = _size + n;
    const size_t newCapacity = newSize * 2;
    char* newData = new char[newCapacity];
    for (int i = 0; i < n; i++) { newData[i] = c; }
    for (int i = 0; i < _size; i++) {
        newData[n + i] = _data[i];
    }
    _size = newSize;
    _capacity = newCapacity;
    delete[] _data;
    _data = newData;
}




std::vector<str> str::split(char c) const {
    std::vector<str> result;
    size_t start = 0;

    for (size_t i = 0; i < _size - 1; i++) {  // Exclude null terminator
        if (_data[i] == c) {
            size_t length = i - start;
            char* segment = new char[length + 1];
            for (size_t j = 0; j < length; j++) {
                segment[j] = _data[start + j];
            }
            segment[length] = '\0';
            result.emplace_back(segment);
            start = i + 1;
        }
    }

    // Add final segment (after last delimiter, or full string if no delimiter)
    if (start < _size - 1) {
        size_t length = _size - 1 - start;
        char* segment = new char[length + 1];
        for (size_t j = 0; j < length; j++) {
            segment[j] = _data[start + j];
        }
        segment[length] = '\0';
        result.emplace_back(segment);
    }

    return result;
}





size_t str::count(char c) const {
    size_t total = 0;
    for (int i = 0; i < _size; i++)
        if (_data[i] == c) total++;
    return total;
}

int str::index(char c) const {
    for (int i = 0; i < _size; i++)
        if (_data[i] == c) return i;
    return -1;
}




bool str::is_empty() const { return _size == 0; }

bool str::ends_with(str s) const {
    size_t s_size = s.size();
    if (s_size > _size) return false;
    // Hello -> llo
    for (size_t i = 0; i < s_size; i++) {
        if (_data[_size - s_size + i] != s.data()[i]) return false;
    }
    return true;
}

bool str::starts_with(str s) const {
    size_t s_size = s.size();
    if (s_size > _size) return false;
    for (size_t i = 0; i < s_size - 1; i++)
        if (_data[i] != s.data()[i]) return false;
    return true;
}

bool str::contains(str s) const { // O(n^2)
    size_t s_size = s.size() - 1;
    if (_size < s_size) return false;
    for (int i = 0; i <= static_cast<int>(_size - s_size - 1); i++) {
        bool match = true;
        for (int j = 0; j < s_size; j++) {
            if (_data[i + j] != s.data()[j]) {
                match = false;
                break;
            }
        }
        if (match) return true;
    }
    return false;
}





// Is ...
bool str::islower() const { // O(n)
    for (int i = 0; i < _size; i++)
        if (!::islower(_data[i])) return false;
    return true;
}

bool str::isupper() const { // O(n)
    for (int i = 0; i < _size; i++)
        if (!::isupper(_data[i])) return false;
    return true;
}

bool str::istitle() const {
    bool newWord = true;

    for (int i = 0; i < _size; ++i) {
        if (::isspace(_data[i])) {
            newWord = true;
        } else {
            if (newWord) {
                if (!::isupper(_data[i])) return false;
                newWord = false;
            } else {
                if (!::islower(_data[i])) return false;
            }
        }
    }
    return true;
}

bool str::isalpha() const {
    for (int i = 0; i < _size - 1; i++)
        if (!::isalpha(_data[i])) return false;
    return true;
}

bool str::isalnum() const {
    for (int i = 0; i < _size - 1; i++)
        if (!::isalnum(_data[i])) return false;
    return true;
}

bool str::isdecimal() const {
    if (!contains(str((char*)".")) || count('.') != 1) return false;
    for (int i = 0; i < _size - 1; i++)
        if (!::isdigit(_data[i]) || _data[i] != '.') return false;
    return true;
}

bool str::isdigit() const {
    for (int i = 0; i < _size - 1; i++)
        if (!::isdigit(_data[i])) return false;
    return true;
}

bool str::isspace() const {
    for (int i = 0; i < _size - 1; i++)
        if (!::isspace(_data[i])) return false;
    return true;
}





// Getters
size_t str::size() const { return _size;}
size_t str::capacity() const { return _capacity; }
char *str::data() const { return _data; }




// Inserting & Removing & Getting & Setting
void str::set(int index, char c) const {
    if (index < 0 || index >= _size) {
        std::cerr << "Index out of bounds!" << std::endl;
        exit(-1);
    }
    _data[index] = c;
}

char str::get(int index) const {
    if (index < 0 || index >= _size) {
        std::cerr << "Index out of bounds!" << std::endl;
        exit(-1);
    }
    return _data[index];
}

void str::remove(int index) {
    if (index < 0 || index >= _size) {
        std::cerr << "Index out of bounds!" << std::endl;
        exit(-1);
    }
    for (int i = index; i < _size - 1; ++i)
        _data[i] = _data[i + 1];
    _size--;
    if (_size < _capacity / 2) shrink();
}

void str::insert(int index, char c) {
    if (index < 0 || index >= _size) {
        std::cerr << "Index out of bounds!" << std::endl;
        exit(-1);
    }
    if (_size + 1 == _capacity) grow();
    for (size_t i = _size; i >= index; i--)
        _data[i] = _data[i - 1];
    _data[index] = c;
    _size++;
}





// Arithmetic Operators
str str::operator+(const str& s) const {
    size_t new_size = _size + s._size - 1;
    size_t new_capacity = new_size * 2;

    char* newData = new char[new_capacity];
    for (size_t i = 0; i < _size - 1; i++) {
        newData[i] = _data[i];
    }
    for (size_t i = 0; i < s._size; i++) {
        newData[i + _size - 1] = s._data[i];
    }

    str result;
    delete[] result._data;

    result._data = newData;
    result._size = new_size;
    result._capacity = new_capacity;

    return result;
}

str &str::operator+=(const str &s) const {
    const size_t new_size = _size + s._size - 1;

    size_t new_capacity = new_size * 2;
    char *newData = new char[new_capacity];

    for (int i = 0; i < _size - 1; i++)
        newData[i] = _data[i];
    for (int i = 0; i < s._size - 1; i++)
        newData[i + _size - 1] = s._data[i];

    newData[new_size - 1] = '\0';

    str result;
    delete result._data;
    result._data = newData;
    result._size = new_size;
    result._capacity = new_capacity;

    return result;
}

str &str::operator*(unsigned n) {
    if (n == 0) {
        delete[] _data;
        _capacity = CAPACITY;
        _size = 1;
        _data = new char[CAPACITY];
        return *this;
    }
    const size_t new_size = (_size - 1) * n + 1; // Accounting for null terminator
    _capacity = new_size;
    char *newData = new char[_capacity];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < _size - 1; j++) {
            newData[i * (_size - 1) + j] = _data[j];
        }
    }
    newData[new_size - 1] = '\0';
    delete[] _data;
    _data = newData;
    _size = new_size;
    return *this;
}

str &str::operator*=(unsigned n) {
    if (n == 0) {
        delete[] _data;
        _capacity = CAPACITY;
        _size = 1;
        _data = new char[CAPACITY];
        return *this;
    }
    const size_t new_size = (_size - 1) * n + 1; // Accounting for null terminator
    _capacity = new_size * 2;
    char *newData = new char[_capacity];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < _size - 1; j++) {
            newData[i * (_size - 1) + j] = _data[j];
        }
    }
    newData[new_size - 1] = '\0';
    delete[] _data;
    _data = newData;
    _size = new_size;
    return *this;
}




// Equality Operators
bool str::operator==(const str &s) const {
    if (_size != s.size()) return false;
    for (int i = 0; i < _size; i++)
        if (_data[i] != s._data[i]) return false;
    return true;
}

bool str::operator!=(const str &s) const {
    if (_size != s.size()) return true;
    for (int i = 0; i < _size; i++)
        if (_data[i] != s._data[i]) return true;
    return false;
}



// Assignment Operator
str& str::operator=(const str& string) {
    if (this ==  &string) return *this;
    delete[] _data;
    _size = string.size();
    _capacity = string.capacity();
    _data = new char[_capacity];
    for (int i = 0; i < _size; i++) {
        _data[i] = string.data()[i];
    }
    return *this;
}





// Indexing operator
char str::operator[](int index) const { return get(index); }




// Output Operator: <<
std::ostream &operator<<(std::ostream &os, const str &s) {
    for (int i = 0; i < s._size - 1; ++i)
        os << s._data[i];
    return os;
}




// Destructure
 str::~str() {
    std::cout << "[destruct] " << _data << std::endl;
    delete[] _data;
}

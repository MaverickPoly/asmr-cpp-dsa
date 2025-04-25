#ifndef CUSTOM_STRING_H
#define CUSTOM_STRING_H

#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;

class String
{
private:
    string data;

public:
    String();
    String(string str);

    // Capitalization
    String lower();
    String upper();
    String title();

    // Is SMTH
    bool isdigit();
    bool isalpha();
    bool isalnum();
    bool isspace();
    bool islower();
    bool isupper();

    // WIth
    bool endswith(const string &part) const;
    bool startswith(const string &part) const;

    // Find
    size_t find(char);
    size_t rfind(char);
    size_t replace(char, char);

    // Strip
    String strip();
    String rstrip();
    String lstrip();

    // Split & Join
    String join(vector<string>);
    vector<string> split(char);

    // Special Methods
    friend std::ostream &operator<<(std::ostream &os, const String &);
};

#endif
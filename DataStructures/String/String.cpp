#include <iostream>
#include "String.h"
#include <string>
#include <vector>
#include <cctype>

using std::cout;
using std::string;
using std::vector;

// Constructors
String::String()
{
    data = "";
}

String::String(string str)
{
    data = str;
}

// Capitalization
String String::lower()
{
    String res(*this);
    for (char &ch : res.data)
    {
        ch = std::tolower(static_cast<unsigned char>(ch));
    }
    return res;
}

String String::upper()
{
    String res(*this);
    for (char &ch : res.data)
        ch = std::toupper(static_cast<unsigned char>(ch));
    return res;
}

String String::title()
{
    String result(*this);
    bool newWord = true;

    for (char &c : result.data)
    {
        if (std::isalpha(static_cast<unsigned char>(c)))
        {
            if (newWord)
            {
                c = std::toupper(static_cast<unsigned char>(c));
                newWord = false;
            }
            else
            {
                c = std::tolower(static_cast<unsigned char>(c));
            }
        }
        else
        {
            newWord = true;
        }
    }
    return result;
}

// Is SMTH
bool String::isdigit()
{
    for (char ch : data)
    {
        if (!std::isdigit(static_cast<unsigned char>(ch)))
            return false;
    }
    return true;
}

bool String::isalpha()
{
    for (char ch : data)
    {
        if (!std::isalpha(static_cast<unsigned char>(ch)))
            return false;
    }
    return true;
}

bool String::isalnum()
{
    for (char ch : data)
    {
        if (!std::isalnum(static_cast<unsigned char>(ch)))
            return false;
    }
    return true;
}

bool String::isspace()
{
    for (char ch : data)
    {
        if (!std::isspace(static_cast<unsigned char>(ch)))
            return false;
    }
    return true;
}

bool String::islower()
{
    for (char ch : data)
    {
        if (std::isupper(static_cast<unsigned char>(ch)))
            return false;
    }
    return true;
}

bool String::isupper()
{
    for (char ch : data)
    {
        if (std::islower(static_cast<unsigned char>(ch)))
            return false;
    }
    return true;
}

// With
bool String::endswith(const string &part) const
{
    if (part.size() > data.size())
        return false;

    return std::equal(part.begin(), part.end(), data.end() - part.size());
}

bool String::startswith(const string &part) const
{
    if (part.size() > data.size())
        return false;
    return std::equal(part.begin(), part.end(), data.begin());
}

// Finds
// Return first found Index of char in string -> Not found -1
size_t String::find(char ch)
{
    size_t pos = data.find(ch);
    return pos == string::npos ? -1 : pos;
}

// Seek from end
size_t String::rfind(char ch)
{
    size_t pos = data.rfind(ch);
    return pos == string::npos ? -1 : pos;
}

size_t String::replace(char target, char element)
{
    size_t count = 0;
    for (size_t pos = 0; (pos = data.find(target, pos)) != string::npos; pos++)
    {
        data[pos] = element;
        count++;
    }
    return count;
}

// Strip
String String::strip()
{
    size_t end = data.find_last_not_of(" \t\n\r\f\v");
    data = (end == string::npos) ? "" : data.substr(0, end + 1);
    size_t start = data.find_first_not_of(" \t\n\r\f\v");
    data = (start == string::npos) ? "" : data.substr(start);
    return String(data);
}

String String::rstrip()
{
    size_t end = data.find_last_not_of(" \t\n\r\f\v");
    data = (end == string::npos) ? "" : data.substr(0, end + 1);
    return String(data);
}

String String::lstrip()
{
    size_t start = data.find_first_not_of(" \t\n\r\f\v");
    data = (start == string::npos) ? "" : data.substr(start);
    return String(data);
}

// Split & Join
String String::join(vector<string> vec)
{
    string res = "";
    int size = vec.size();
    for (int i = 0; i < size; i++)
    {
        res.append(vec[i]);
        if (i != size - 1)
            res.append(data);
    }
    return String(res);
}

vector<string> String::split(char delimiter = ' ')
{
    vector<string> res;
    string current;
    for (int i = 0; i < data.size(); i++)
    {
        char ch = data[i];
        if (ch == delimiter)
        {
            res.push_back(current);
            current = "";
        }
        else
        {
            current += ch;
        }
    }
    res.push_back(current);
    return res;
}

// Special Methods
std::ostream &operator<<(std::ostream &os, const String &str)
{
    os << str.data;
    return os;
}

#ifndef BOOL_H

#define BOOL_H

#include <iostream>
#include <string>
#include <vector>

class Bool
{
private:
    int state;

public:
    // Constructors
    Bool();
    Bool(int);
    Bool(short);
    Bool(long);
    Bool(double);
    Bool(float);
    Bool(char);
    Bool(unsigned);
    Bool(std::string);

    Bool operator==(const Bool &) const;
    Bool operator!=(const Bool &) const;

    friend std::ostream &operator<<(std::ostream &os, const Bool &);
};

#endif

#include "Bool.h"
#include <iostream>

// ====== Constructors
Bool::Bool()
{
    state = 0;
}
Bool::Bool(int val)
{
    state = val == 0 ? 0 : 1;
}
Bool::Bool(short val)
{
    state = val == 0 ? 0 : 1;
}
Bool::Bool(long val)
{
    state = val == 0 ? 0 : 1;
}
Bool::Bool(double val)
{
    state = val == 0 ? 0 : 1;
}
Bool::Bool(float val)
{
    state = val == 0 ? 0 : 1;
}
Bool::Bool(char val)
{
    state = val == '\0' ? 0 : 1;
}
Bool::Bool(unsigned val)
{
    state = val == 0 ? 0 : 1;
}
Bool::Bool(std::string val)
{
    state = val == "" ? 0 : 1;
}

// Operators
Bool Bool::operator==(const Bool &b) const
{
    return Bool(state == b.state);
}

Bool Bool::operator!=(const Bool &b) const
{
    return Bool(state != b.state);
}

std::ostream &operator<<(std::ostream &os, const Bool &b)
{
    os << (b.state ? "true" : "false");
    return os;
}

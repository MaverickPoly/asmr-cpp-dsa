#include <iostream>
#include "Bool.h"
#include <string>

using std::cout;
using std::endl;

int main(void)
{
    Bool i(3);
    Bool sh(short(0));
    Bool lo(long(1000));
    Bool doub(double(3.141592));
    Bool floa(float(0.0));
    Bool ch1('A');
    Bool ch2('\0');
    Bool unsign(unsigned(10));
    Bool str1(std::string("Hello"));
    Bool str2(std::string(""));

    cout << "Int: " << i << endl;
    cout << "Short: " << sh << endl;
    cout << "Long: " << lo << endl;
    cout << "Double: " << doub << endl;
    cout << "Float: " << floa << endl;
    cout << "Char 1: " << ch1 << endl;
    cout << "Char 2: " << ch2 << endl;
    cout << "Unsigned: " << unsign << endl;
    cout << "String 1: " << str1 << endl;
    cout << "String 2: " << str2 << endl;

    cout << endl;

    cout << (i == sh) << endl;
    cout << (lo == doub) << endl;
    cout << (floa == ch1) << endl;
    cout << (ch2 == unsign) << endl;
    cout << (str1 == str2) << endl;

    return 0;
}

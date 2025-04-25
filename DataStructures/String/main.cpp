#include <iostream>
#include "String.h"

using std::cout;
using std::endl;

int main(void)
{
    String str1 = String("3432789");
    String str2 = String("HelloworDLKSMAd");
    String str3 = String("hello1s2");
    String str4 = String(" \n  \t  ");
    String str5 = String("INSERT INTO");
    String str6 = String("пРРРРивеТ");

    cout << "Is digit: " << str1.isdigit() << endl;
    cout << "Is alpha: " << str2.isalpha() << endl;
    cout << "Is alnum: " << str3.isalnum() << endl;
    cout << "Is space: " << str4.isspace() << endl;
    cout << "Is upper: " << str5.isupper() << endl;
    cout << "Is lower: " << str6.islower() << endl;

    cout << endl;
    vector<string> str_elements = {"Hello", "World", "!"};
    String joined = String(" ").join(str_elements);
    cout << joined << endl;

    vector<string> splitted = joined.split(' ');
    for (auto el : splitted)
        cout << el;

    cout << endl
         << endl;

    String str7 = String("  \t Hi!");
    String str8 = String("Hi!  \n\n  ");
    String str9 = String("  \t \t  Hi!  \n\n  ");

    cout << "LStrip: " << str7.lstrip() << endl;
    cout << "RStrip: " << str8.rstrip() << endl;
    cout << "Strip: " << str9.strip() << endl;

    String str10 = String("Altair Tech");
    String str11 = String("Maverick Polymath");

    cout << "Endswith: " << str10.endswith("Tech") << endl;
    cout << "Startswith: " << str11.startswith("Ma") << endl;

    cout << endl
         << endl;

    String str12 = String("Find n in this string!");
    String str13 = String("Right find string!");

    cout << "Find n: " << str12.find('n') << endl;
    cout << "RFind i: " << str13.rfind('i') << endl;

    cout << endl;

    cout << "Upper: " << String("Uppercase this String!").upper() << endl;
    cout << "Lower: " << String("LOWERCASE THiS String!").lower() << endl;
    cout << "Title: " << String("title this String!").title() << endl;

    return 0;
}
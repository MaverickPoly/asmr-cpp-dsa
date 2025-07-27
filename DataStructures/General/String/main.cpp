#include <iostream>
#include "str.h"

using namespace std;

int main() {
    cout << "---- str class tests ----\n\n";

    str s1((char*)"hello");
    cout << "Initial string: " << s1 << endl;

    // Append via +
    str s2((char*)" world");
    str combined = s1 + s2;
    cout << "After + operator (hello + world): " << combined << endl;

    // Append via +=
    s1 += s2;
    cout << "After += operator: " << s1 << endl;

    // Multiplication
    str repeated((char*)"ha");
    repeated *= 3;
    cout << "After *= 3 on 'ha': " << repeated << endl;

    // Replace
    str banana((char*)"banana");
    size_t replaced = banana.replace('a', 'o');
    cout << "After replacing 'a' with 'o' in 'banana': " << banana << ", replacements: " << replaced << endl;


    // Strip
    str spaced((char*)"  test  ");
    spaced.strip();
    cout << "After strip(): '" << spaced << "'" << endl;

    // rstrip
    str r((char*)"trail   ");
    r.rstrip();
    cout << "After rstrip(): '" << r << "'" << endl;

    // lstrip
    str l((char*)"   lead");
    l.lstrip();
    cout << "After lstrip(): '" << l << "'" << endl;

    // Index and count
    str fruits((char*)"banana");
    cout << "Count of 'a' in 'banana': " << fruits.count('a') << endl;
    cout << "Index of 'n' in 'banana': " << fruits.index('n') << endl;

    // Substring
    str hello((char*)"Python awesome");
    str sub = hello.substr(0, 6);
    cout << "Substring (0, 6): " << sub << " - " << sub.size() << endl;


    // Justify
    str j1((char*)"hi");
    j1.ljust('-', 5);
    cout << "After ljust('-', 5): " << j1 << endl;

    str j2((char*)"hi");
    j2.rjust('-', 5);
    cout << "After rjust('-', 5): " << j2 << endl;



    // TODO: Fix here:

    // Split
    // str csv((char*)"a,b,c");
    // auto parts = csv.split(',');
    // cout << "Split 'a,b,c' by ',': ";
    // for (auto& part : parts) cout << part << " ";
    // cout << endl;

    cout << endl;
    // TODO: Fix above:


    // Booleans
    str alpha((char*)"Hello123");
    cout << "'Hello123' isalnum: " << (alpha.isalnum() ? "Yes" : "No") << endl;
    cout << "'Hello123' isalpha: " << (alpha.isalpha() ? "Yes" : "No") << endl;

    str num((char*)"123");
    cout << "'123' isdigit: " << (num.isdigit() ? "Yes" : "No") << endl;

    str space((char*)"   ");
    cout << "All spaces isspace: " << (space.isspace() ? "Yes" : "No") << endl;

    // Contains, starts_with, ends_with
    str big((char*)"hello world");
    cout << "'hello world' contains 'lo': " << (big.contains(str((char*)"lo")) ? "Yes" : "No") << endl;
    cout << "'hello world' starts with 'he': " << (big.starts_with(str((char*)"he")) ? "Yes" : "No") << endl;
    cout << "'hello world' ends with 'ld': " << (big.ends_with(str((char*)"ld")) ? "Yes" : "No") << endl;

    cout << endl;

    // Insert, remove, set, get
    str mod((char*)"helo");
    mod.insert(2, 'l');
    cout << "After insert(2, 'l'): " << mod << endl;

    mod.remove(1);
    cout << "After remove(1): " << mod << endl;

    mod.set(1, 'a');
    cout << "After set(1, 'a'): " << mod << endl;

    cout << "mod.get(1): " << mod.get(1) << endl;

    // Indexing
    cout << "mod[0]: " << mod[0] << ", mod[2]: " << mod[2] << endl;

    // Comparison
    str cmp1((char*)"hello");
    str cmp2((char*)"hello");
    str cmp3((char*)"world");

    cout << "'hello' == 'hello': " << (cmp1 == cmp2 ? "Yes" : "No") << endl;
    cout << "'hello' != 'world': " << (cmp1 != cmp3 ? "Yes" : "No") << endl;

    cmp1 = "Do not Look up";
    cout << cmp1 << endl;

    return 0;
}

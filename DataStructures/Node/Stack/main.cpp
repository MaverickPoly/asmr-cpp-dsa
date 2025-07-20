#include <iostream>

#include "stack.h"


using namespace std;


int main() {
    stack<int> st1;

    cout << "Is empty: " << st1.isEmpty() << endl;
    cout << "Size: " << st1.get_size() << endl;
    cout << st1 << endl;


    st1.push(5);
    st1.push(4);
    st1.push(7);
    st1.push(6);
    st1.push(9);
    cout << st1 << endl;
    cout << "Is empty: " << st1.isEmpty() << endl;
    cout << "Size: " << st1.get_size() << endl << endl;

    cout << "Peek: " << st1.peek() << endl;
    cout << "Pop: " << st1.pop() << endl;
    cout << "Pop: " << st1.pop() << endl;
    cout << "Pop: " << st1.pop() << endl << endl;

    cout << st1 << endl;
    cout << "Is empty: " << st1.isEmpty() << endl;
    cout << "Size: " << st1.get_size() << endl;

    return 0;
}

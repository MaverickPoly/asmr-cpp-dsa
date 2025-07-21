#include <iostream>
#include <string>

#include "queue.h"


using namespace std;

int main() {
    queue<string> q{};

    cout << "Size: " << q.get_size() << endl;
    cout << "Is Empty: " << q.is_empty() << endl;
    cout << "Contains H: " << q.contains("H") << endl;

    cout << q << endl;

    q.push("Hello");
    q.push("world");
    q.push("!.?");
    q.push("My");
    q.push("name is:");
    q.push("Ahmed");

    cout << "Size: " << q.get_size() << endl;
    cout << "Is Empty: " << q.is_empty() << endl;
    cout << "Contains world: " << q.contains("world") << endl;
    cout << q << endl << endl;

    cout << "Peek: " << q.peek() << endl;
    cout << "Pop: " << q.pop() << endl;
    cout << "Pop: " << q.pop() << endl;
    cout << "Pop: " << q.pop() << endl;
    cout << "Peek: " << q.peek() << endl;

    cout << "Size: " << q.get_size() << endl;
    cout << "Is Empty: " << q.is_empty() << endl;
    cout << q << endl;

    return 0;
}

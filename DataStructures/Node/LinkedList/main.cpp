#include <iostream>

#include "linked_list.h"


using namespace std;

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    linked_list<int> ll {arr, 5};

    cout << "Size: " << ll.get_size() << endl;
    cout << "Is Empty: " << ll.is_empty() << endl;
    cout << "Contains 4: " << ll.contains(4) << endl;
    cout << "Contains 10: " << ll.contains(10) << endl;

    ll.append(7);
    ll.append(8);
    ll.insert(5, 6);

    cout << ll << endl << endl;

    ll.prepend(0);
    ll.insert(ll.get_size(), 10);
    cout << ll << endl;
    cout << "First: " << ll.first() << endl;
    cout << "Last: " << ll.last() << endl << endl;

    cout << "Pop: " << ll.pop() << endl;
    cout << "Pop: " << ll.pop() << endl;
    cout << "Remove 4: " << ll.remove(4) << endl;
    cout << "Remove last: " << ll.remove(ll.get_size() - 1) << endl;

    cout << ll << endl << endl;

    cout << ll[0] << endl;
    cout << ll[3] << endl;
    cout << ll[5] << endl;

    ll.clear();
    cout << "Size: " << ll.get_size() << endl;
    cout << "Is Empty: " << ll.is_empty() << endl;
    cout << ll << endl;

    return 0;
}

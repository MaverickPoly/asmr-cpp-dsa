#include <iostream>

#include "dynamic_list.h"


using namespace std;

int main() {
    dynamic_list<int> list;

    cout << "Initial list (should be empty): " << list << endl;

    // Append test
    list.append(10);
    list.append(20);
    list.append(30);
    cout << "After appending 10, 20, 30: " << list << endl;

    // Prepend test
    list.prepend(5);
    cout << "After prepending 5: " << list << endl;

    // Insert test
    list.insert(15, 2);
    cout << "After inserting 15 at index 2: " << list << endl;

    // Contains test
    cout << "List contains 20: " << (list.contains(20) ? "Yes" : "No") << endl;
    cout << "List contains 99: " << (list.contains(99) ? "Yes" : "No") << endl;

    // Index test
    cout << "Index of 30: " << list.index(30) << endl;

    // Count test
    list.append(10);
    cout << "After appending another 10: " << list << endl;
    cout << "Count of 10: " << list.count(10) << endl;

    // Reverse test
    list.reverse();
    cout << "After reversing: " << list << endl;

    // Pop test
    const int popped = list.pop();
    cout << "After popping (value = " << popped << "): " << list << endl;

    // Remove test
    list.remove(15);
    cout << "After removing 15: " << list << endl;

    // Clear test
    list.clear();
    cout << "After clearing: " << list << endl;

    // Rebuild list from vector
    vector<int> vec = {1, 2, 3, 4};
    dynamic_list<int> list2(vec);
    cout << "List created from vector: " << list2 << endl;

    // Test assignment
    dynamic_list<int> list3;
    list3 = list2;
    cout << "Assigned list3 = list2: " << list3 << endl;

    // Test comparison
    cout << "list2 == list3: " << (list2 == list3 ? "True" : "False") << endl;
    list3.append(99);
    cout << "After appending 99 to list3: " << list3 << endl;
    cout << "list2 != list3: " << (list2 != list3 ? "True" : "False") << endl;

    // Test indexing
    cout << "Element at index 2 of list3: " << list3[2] << endl;

    // Input test
    dynamic_list<int> list4;
    cout << "Enter values to input into list4 (e.g. 10 20 30):";
    cin >> list4;
    cout << "You entered: " << list4 << endl;

    return 0;
}

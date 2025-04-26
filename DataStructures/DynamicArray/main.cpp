#include <iostream>
#include <vector>
#include "Array.h"

using std::cout;
using std::endl;

int main(void)

{
    vector<int> vec = {1, 2, 3, 4, 6};
    Array<int> array = Array<int>(vec);
    array.append(1);
    array.append(6);
    array.append(7);
    cout << "Count 1: " << array.count(1) << endl;
    cout << "Index of 1: " << array.index(1) << endl;
    cout << "Index of 3: " << array.index(3) << endl;
    cout << "Index of not exist: " << array.index(432) << endl;

    auto arrCopy = array.copy();
    cout << "Copy: " << arrCopy << endl;

    cout << array;

    array.insert(4, 5);
    array.insert(0, 0);
    array.insert(9, 8);
    cout << array;

    cout << "Pop: " << array.pop() << endl;
    cout << "Pop: " << array.pop() << endl;

    array.remove(6);

    cout << array;

    cout << endl
         << "---- Sort" << endl;
    array.sort();
    cout << array;

    cout << "Contains 0: " << array.contains(0) << endl;
    cout << "Contains 7: " << array.contains(7) << endl;

    cout << "Size: " << array.getSize() << endl;
    cout << "Capacity: " << array.getCapacity() << endl;
    cout << "Get Item: " << array.get(1) << ", ";
    cout << "Get Item: " << array.get(4) << ", ";
    cout << "Get Item: " << array.get(8) << endl;

    arrCopy = array.copy();
    cout << "Equals: " << array.equals(arrCopy) << endl;

    cout << endl
         << "Reverse:" << endl;
    array.reverse();
    cout << array;

    cout << endl
         << "Clear:" << endl;
    array.clear();
    cout << array;

    return 0;
}

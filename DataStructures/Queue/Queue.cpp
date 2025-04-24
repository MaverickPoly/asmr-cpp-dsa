#include <iostream>

using std::cout;
using std::endl;

template <typename T>
class Node
{

public:
    T value;
    Node *next;

    Node(T value)
    {
        this->value = value;
        this->next = nullptr;
    }
};

template <typename T>
class Queue
{
private:
    Node<T> *head;
    Node<T> *tail;
    unsigned size;

public:
    Queue()
    {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }

    /*
    head <- val <- val <- val <- tail
    */

    // Push
    void push(T value)
    {
        Node<T> *node = new Node<T>(value);
        if (head == nullptr)
        {
            cout << "Head = nullptr" << endl;
            head = node;
            tail = node;
        }
        else
        {
            node->next = tail;
            tail = node;
        }
        size++;
    }

    // removeFirst
    void removeFirst()
    {
        if (head == nullptr)
        {
            throw std::runtime_error("Queue is empty!");
        }
        else if (size == 1)
        {
            delete head;
            head = tail = nullptr;
        }
        else
        {
            Node<T> *current = tail;
            while (current->next->next)
            {
                current = current->next;
            }
            delete head;
            current->next = nullptr;
            head = current;
        }
        size--;
    }

    // removeLast
    void removeLast()
    {
        if (tail == nullptr)
        {
            throw std::runtime_error("Queue is empty!");
        }
        else if (size == 1)
        {
            delete tail;
            tail = head = nullptr;
        }
        else
        {
            Node<T> *target = tail->next;
            delete tail;
            tail = target;
        }
        size--;
    }

    // First - Head
    T getFirst() const { return head->value; }

    // Last - Tail
    T getLast() const { return tail->value; }

    // Get Size
    unsigned getSize() const { return this->size; }

    // Is Empty
    bool isEmpty() const { return this->size == 0; }

    // Print
    void print()
    {
        Node<T> *current = tail;
        while (current != nullptr)
        {
            cout << current->value << " -> ";
            current = current->next;
        }
        cout << endl;
    }

    // Clear
    void clear()
    {
        Node<T> *current = tail;
        while (current != nullptr)
        {
            Node<T> *next = current->next;
            delete current;
            current = next;
        }
        head = tail = nullptr;
        size = 0;
    }

    // Destructure
    ~Queue()
    {
        Node<T> *current = tail;
        while (current != nullptr)
        {
            Node<T> *next = current->next;
            delete current;
            current = next;
        }
    }
};

int main(void)
{
    Queue<char> *q = new Queue<char>();

    cout << "Size: " << q->getSize() << endl;
    cout << "Is Empty: " << q->isEmpty() << endl;

    q->push('a');
    q->push('b');
    q->push('c');
    q->push('d');
    q->push('e');

    q->print();

    cout << "Last: " << q->getLast() << endl;
    cout << "First: " << q->getFirst() << endl;

    q->removeFirst();
    q->removeLast();

    q->print();

    cout << "Size: " << q->getSize() << endl;
    cout << "Is Empty: " << q->isEmpty() << endl;

    return 0;
}

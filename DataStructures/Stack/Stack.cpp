#include <iostream>

using std::cout;
using std::endl;

class Node
{
public:
    int value;
    Node *next;

    Node(int value)
    {
        this->value = value;
        this->next = nullptr;
    }
};

class Stack
{
private:
    Node *head;
    unsigned size;

public:
    Stack()
    {
        head = nullptr;
        size = 0;
    }

    // Push
    void push(int value)
    {
        Node *node = new Node(value);
        if (head == nullptr)
        {
            head = node;
        }
        else
        {
            Node *current = head;
            while (current->next != nullptr)
            {
                current = current->next;
            }
            current->next = node;
        }
        size++;
    }

    // Pop
    int pop()
    {
        int returnVal;
        if (head == nullptr)
        {
            throw std::runtime_error("Stack is empty!");
        }
        else if (size == 1)
        {
            returnVal = head->value;
            delete head;
            head = nullptr;
        }
        else
        {
            Node *current = head;
            while (current->next->next != nullptr)
            {
                current = current->next;
            }
            returnVal = current->next->value;
            delete current->next;
            current->next = nullptr;
        }
        return returnVal;
    }

    // Peek
    int peek() const
    {
        if (head == nullptr)
        {
            throw std::runtime_error("Stack is empty!");
        }
        else
        {
            Node *current = head;
            while (current->next != nullptr)
            {
                current = current->next;
            }
            return current->value;
        }
    }

    // Print
    void print() const
    {
        Node *current = head;
        while (current != nullptr)
        {
            cout << current->value << " -> ";
            current = current->next;
        }
        cout << endl;
    }

    // Get Size
    unsigned getSize() const { return size; }

    // Is Empty
    bool isEmpty() const { return size == 0; }

    // Clear
    void clear()
    {
        Node *current = head;
        while (current != nullptr)
        {
            Node *next = current->next;
            delete current->next;
            current = next;
        }
        head = nullptr;
        size = 0;
    }

    ~Stack()
    {
        Node *current = head;
        while (current != nullptr)
        {
            Node *next = current->next;
            delete current;
            current = next;
        }
    }
};

int main(void)
{
    Stack *stack = new Stack();

    cout << "Size: " << stack->getSize() << endl;
    cout << "Is Empty: " << stack->isEmpty() << endl;

    stack->push(1);
    stack->push(2);
    stack->push(3);
    stack->push(4);
    stack->push(5);
    stack->push(6);

    stack->print();

    cout << "Size: " << stack->getSize() << endl;
    cout << "Is Empty: " << stack->isEmpty() << endl;

    cout << "Peek: " << stack->peek() << endl;
    cout << "Pop: " << stack->pop() << endl;
    cout << "Peek: " << stack->peek() << endl;
    cout << "Pop: " << stack->pop() << endl;

    cout << "Peek: " << stack->peek() << endl;

    stack->print();

    cout << "Size: " << stack->getSize() << endl;
    cout << "Is Empty: " << stack->isEmpty() << endl;

    delete stack;

    return 0;
}

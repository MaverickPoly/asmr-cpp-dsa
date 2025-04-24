#include "iostream"

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

class LinkedList
{
    Node *head;
    unsigned size;

public:
    LinkedList()
    {
        this->head = nullptr;
        this->size = 0;
    }

    // Add to the end
    void append(int value)
    {
        Node *node = new Node(value);
        if (head == nullptr)
        {
            head = node;
        }
        else
        {
            Node *current = this->head;
            while (current->next)
            {
                current = current->next;
            }
            current->next = node;
        }
        size++;
    }

    // Add to start
    void prepend(int value)
    {
        Node *node = new Node(value);
        node->next = head;
        head = node;
        size++;
    }

    // Delete last and return it
    int pop()
    {
        int returnVal = peek();

        if (head == nullptr)
        {
            throw std::runtime_error("List is empty!");
        }
        else if (size == 1)
        {
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
            delete current->next;
            current->next = nullptr;
        }

        size--;
        return returnVal;
    }

    // Return Last
    int peek() const
    {
        if (head == nullptr)
        {
            throw std::runtime_error("List is empty!");
        }
        Node *current = head;
        while (current->next)
        {
            current = current->next;
        }
        return current->value;
    }

    // Size
    int getSize()
    {
        return this->size;
    }

    // Is Empty
    bool isEmpty()
    {
        return this->size == 0;
    }

    // Index of a value, -1 if not found
    int indexOf(int value)
    {
        if (head == nullptr)
        {
            return -1;
        }
        int i = 0;
        Node *current = head;
        while (current)
        {
            if (current->value == value)
            {
                return i;
            }
            i++;
            current = current->next;
        }
        return -1;
    }

    // Remove value if found
    bool remove(int value)
    {
        if (size == 0)
        {
            return false;
        }
        else if (head->value == value)
        {
            head = head->next;
            size--;
            return true;
        }
        else
        {
            Node *current = head;
            while (current->next)
            {
                if (current->next->value == value)
                {
                    current->next = current->next->next;
                    size--;
                    return true;
                }
                current = current->next;
            }
        }
        return false;
    }

    // Get Value at specific index
    int getItem(int index)
    {
        if (head == nullptr)
        {
            throw std::runtime_error("List is empty!");
        }
        int i = 0;
        Node *current = head;
        while (current)
        {
            if (i == index)
            {
                return current->value;
            }
            i++;
            current = current->next;
        }
        throw std::runtime_error("Item not found!");
    }

    void clearList()
    {
        Node *current = this->head;
        while (current != nullptr)
        {
            Node *next = current->next;
            delete current;
            current = next;
        }
        head = nullptr;
        size = 0;
    }

    // Display whole data structure
    void print()
    {
        Node *current = head;
        while (current)
        {
            std::cout << current->value << " -> ";

            current = current->next;
        }
        cout << endl;
    }

    // Destructure
    ~LinkedList()
    {
        Node *current = this->head;
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
    LinkedList *ll = new LinkedList();

    cout << "Size: " << ll->getSize() << endl;
    cout << "Is empty: " << ll->isEmpty() << endl;

    ll->append(5);
    ll->append(7);
    ll->append(8);
    ll->append(9);
    ll->append(10);
    ll->prepend(4);
    ll->prepend(3);

    ll->print();

    cout << "Pop: " << ll->pop() << endl;
    cout << "Is empty: " << ll->isEmpty() << endl;
    cout << "Peek: " << ll->peek() << endl;
    cout << "Get Item 3: " << ll->getItem(3) << endl;
    cout << "Get Item 5: " << ll->getItem(5) << endl;
    // cout << "Get Item 6: " << ll->getItem(6) << endl; // -> Error
    cout << "Index of 9: " << ll->indexOf(9) << endl;
    cout << "Remove 8: " << ll->remove(8) << endl;
    cout << "Remove 9: " << ll->remove(9) << endl;
    cout << "Remove 3: " << ll->remove(3) << endl;

    ll->print();
    cout << "Size: " << ll->getSize() << endl;

    ll->clearList();

    ll->print();
    cout << "Size: " << ll->getSize() << endl;

    delete ll;
    return 0;
}

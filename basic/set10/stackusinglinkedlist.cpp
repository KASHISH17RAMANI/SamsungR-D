#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

void push(Node *&top, int value)
{
    Node *newNode = new Node();
    newNode->data = value;
    newNode->next = top;
    top = newNode;
}

void pop(Node *&top)
{
    if (top == nullptr)
    {
        cout << "Stack is empty, cannot pop." << endl;
        return;
    }
    Node *temp = top;
    top = top->next;
    delete temp;
}

int peek(Node *top)
{
    if (top == nullptr)
    {
        cout << "Stack is empty." << endl;
        return -1;
    }
    return top->data;
}

bool isEmpty(Node *top)
{
    return top == nullptr;
}

int main()
{
    Node *stackTop = nullptr; // head is working like top

    push(stackTop, 10);
    push(stackTop, 20);
    push(stackTop, 30);

    cout << "Top element: " << peek(stackTop) << endl;

    pop(stackTop);
    cout << "Top element after pop: " << peek(stackTop) << endl;

    pop(stackTop);
    pop(stackTop);
    pop(stackTop);

    cout << "Is stack empty? " << (isEmpty(stackTop) ? "Yes" : "No") << endl;

    return 0;
}

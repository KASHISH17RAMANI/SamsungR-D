#include <iostream>
#include <climits>
using namespace std;

struct node
{
    int val;
    struct node *next;
    node(int val)
    {
        this->val = val;
        this->next = NULL;
    }
};

node *front = NULL;
node *rear = NULL;
int size = 0;

void enqueue(int x)
{
    node *temp = new node(x);
    if (front == NULL && rear == NULL)
    {
        front = temp;
        rear = temp;
        size++;
    }
    else
    {
        size++;
        rear->next = temp;
        rear = temp;
    }
}

int dequeue()
{
    if (front == NULL && rear == NULL)
    {
        return INT_MIN;
    }
    else
    {
        if (front != NULL)
        {
            size--;
            int temp = front->val;
            front = front->next;
            return temp;
        }
        else
        {
            return INT_MIN;
        }
    }
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        enqueue(t);
    }
    dequeue();
    dequeue();
    node *f = front;
    while (f != NULL)
    {
        cout << f->val << " ";
        f = f->next;
    }

    cout << size << endl;
    return 0;
}

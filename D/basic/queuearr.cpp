#include <iostream>
using namespace std;

const int MAXX = 100;
int que[MAXX];
int front = 0;
int rear = -1;
int capacity = MAXX;

void enqueue(int x)
{
    if (rear == capacity - 1)
    {
        return;
    }
    else
    {
        que[++rear] = x;
    }
}

int dequeue()
{
    if (front > rear)
    {
        return -1000000;
    }
    else
    {
        int x = que[0];
        for (int i = 0; i < rear; i++)
        {
            que[i] = que[i + 1];
        }
        rear--;
        return x;
    }
}


int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        enqueue(x);
    }+

    for (int i = front; i <= rear;i++){
        cout << que[i] << " ";
    }
    cout << dequeue() << endl;
    for (int i = front; i <= rear; i++)
    {
        cout << que[i] << " ";
    }

    return 0;
}
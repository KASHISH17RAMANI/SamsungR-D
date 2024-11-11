#include <iostream>
using namespace std;

class MyQueue
{
private:
    int N;
    int rear, front;
    int *arr;
    int cnt = 0;

public:
    MyQueue(int n)
    {
        N = n;
        arr = new int[N];
        rear = -1;
        front = -1;
    }

    bool isempty()
    {
        return cnt == 0;
    }

    void push(int val)
    {
        if (cnt == N)
        {
            cout << "Queue is full\n";
            return;
        }
        rear = (rear + 1) % N;
        arr[rear] = val;
        if (cnt == 0)
            front = rear;
        cnt++;
    }

    void pop()
    {
        if (isempty())
        {
            cout << "Queue is empty\n";
            return;
        }
        front = (front + 1) % N;
        cnt--;
        if (cnt == 0)
        {
            rear = -1;
            front = -1;
        }
    }

    void print()
    {
        if (isempty())
        {
            cout << "Queue is empty\n";
            return;
        }
        int itr = front;
        for (int i = 0; i < cnt; i++)
        {
            cout << arr[itr] << " ";
            itr = (itr + 1) % N;
        }
        cout << endl;
    }

    ~MyQueue()
    {
        delete[] arr;
    }
};

int main()
{
    MyQueue q(1000);
    q.push(1);
    q.print();
    q.pop();
    q.print();
}

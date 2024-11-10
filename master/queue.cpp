struct node
{
    int x;
    int y;
    int level;
};

node q[1000];
int front = 0;
int back = 0;

void init()
{
    front = back = 0;
}

void push(int x, int y, int level)
{
    q[back].x = x;
    q[back].y = y;
    q[back].level = level;
    back++;
}

node pop()
{
    return q[front++];
}

bool empty()
{
    return (front == back);
}
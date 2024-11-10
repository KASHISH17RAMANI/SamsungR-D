// Company S has developed an industrial endoscope available to
// explore inner part of the decrepit water pipes. It is possible to
// explore the inner part of the pipes putting the endoscope in a
// certain part of the pipe. The endoscope can be moved in the pipe
// only. Meanwhile, when the pipes are connected, if the length of
// the endoscope is long enough to explore, then it can inspect the
// connected pipes. However, we cannot observe every pipe because
// the length of the endoscope is limited.

// When the map of the ground water pipe, the location where the
// endoscope to out in, and the length of the endoscope is given,
// calculate the number of pipe which are available to explore. Length
// of endoscope means the range upto which endoscope can explore. There
// are seven kind of pipes, and description for each pipe are shown
// below:

// S.No	Pipe	Connected to
// 1		    Up, Down, Left, Right
// 2		    Up, Down
// 3		    Left, Right
// 4		    Up, Right
// 5		    Down, Right
// 6		    Down, Left
// 7		    Up, Left
// When the map of the groundwater pipe, the location where the
// endoscope to out in, and the length of the endoscope is given,
// calculate the number of the pipe which are available to explore.
// Length of endoscope means the range up to which endoscope can
// explore.

// Input
// In the first line, T, the number of total test cases are given.
// From the second line, T test cases are given. In the first line of
// each test case, N, the height of the map of the groundwater pipes,
// M, the width, R, the vertical location of the water pipe where to
// put in the endoscope, C, the horizontal location of it, and the
// length of the endoscope L are given. In the following N lines,
// information about the map of the groundwater pipe is given. Each
// line has M numbers. Each number (from 1 to 7) means the type of
// water pipe for that point. 0 means there is no water pipe buried
// in that place.

// Output
// Print the respective answer for T test cases in total for T lines.
// The answer is the number of water pipes which is available to observe
// using the endoscope.

// Constraints
// 1≤ T ≤100
// 1≤ N, M ≤50
// 0≤ X < N
// 0≤ Y < M
// 1≤ L ≤ 20

#include <iostream>
using namespace std;

int row, col, x, y, l;
int map[10000][10000];
int visited[10000][10000];

struct node
{
    int x, y, l;
};

node que[1000000];
int front = 0;
int back = 0;

void push(node temp)
{
    que[back] = temp;
    back++;
}

node pop()
{
    return que[front++];
}

bool empty()
{
    return front == back;
}

bool is_valid(int x, int y)
{
    return (x >= 0 && x < row && y >= 0 && y < col);
}

bool left(int x, int y)
{
    return (map[x][y] == 1 || map[x][y] == 3 || map[x][y] == 6 || map[x][y] == 7);
}

bool right(int x, int y)
{
    return (map[x][y] == 1 || map[x][y] == 3 || map[x][y] == 4 || map[x][y] == 5);
}

bool up(int x, int y)
{
    return (map[x][y] == 1 || map[x][y] == 2 || map[x][y] == 4 || map[x][y] == 7);
}

bool down(int x, int y)
{
    return (map[x][y] == 1 || map[x][y] == 2 || map[x][y] == 6 || map[x][y] == 5);
}

int solve(int x, int y, int l)
{
    int ans = 0;
    push({x, y, l});
    visited[x][y] = 1;
    while (!empty())
    {
        node cur = pop();
        int x = cur.x;
        int y = cur.y;
        int l = cur.l;
        if (l == 0)
        {
            continue;
        }
        ans++;
        if (is_valid(x, y - 1) && left(x, y) && right(x, y - 1) && visited[x][y - 1] == 0)
        {
            push({x, y - 1, l - 1});
            visited[x][y - 1] = 1;
        }
        if (is_valid(x, y + 1) && right(x, y) && left(x, y + 1) && visited[x][y + 1] == 0)
        {
            push({x, y + 1, l - 1});
            visited[x][y + 1] = 1;
        }
        if (is_valid(x-1, y) && up(x, y) && down(x-1, y) && visited[x-1][y] == 0)
        {
            push({x-1, y, l - 1});
            visited[x-1][y] = 1;
        }
        if (is_valid(x+1, y ) && down(x, y) && up(x+1, y) && visited[x+1][y ] == 0)
        {
            push({x+1, y , l - 1});
            visited[x+1][y] = 1;
        }
    }
    return ans;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> row >> col >> x >> y >> l;
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                cin >> map[i][j];
                visited[i][j] = 0;
            }
        }
        if(map[x][y] > 0){
            cout << solve(x, y, l) << endl;
        }
        else{
            cout << 0 << endl;
        }
    }
    return 0;
}


// 1
// 5 6 2 1 3
// 0 0 5 3 6 0
// 0 0 2 0 2 0 
// 3 3 1 3 7 0
// 0 0 0 0 0 0
// 0 0 0 0 0 0
// o/p - 5

// 1 
// 5 6 2 2 6
// 3 0 0 0 0 3
// 2 0 0 0 0 6
// 1 3 1 1 3 1
// 2 0 2 0 0 2
// 0 0 4 3 1 1
// o/p - 15
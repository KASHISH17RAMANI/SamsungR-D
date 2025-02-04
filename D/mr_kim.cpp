// Mr. Kim has to deliver refrigerators to N customers. From
// the office, he is going to visit all the customers and then
// return to his home.
// Each location of the office, his home, and the customers
// is given in the form of integer coordinates (x,y) (0≤x≤100,
// 0≤y≤100) .
// The distance between two arbitrary locations (x1, y1) and
// (x2, y2) is computed by |x1-x2| + |y1-y2|, where |x| denotes
// the absolute value
// of x; for instance, |3|=|-3|=3. The locations of the office,
// his home, and the customers are all distinct. You should
// plan an optimal way
// to visit all the N customers and return to his among all
// the possibilities.
// You are given the locations of the office, Mr. Kim’s home,
// and the customers; the number of the customers is in the
// range of 5 to 10.
// Write a program that, starting at the office, finds a
// (the) shortest path visiting all the customers and returning
// to his home.
// Your program only have to report the distance of a (the)
// shortest path.

// Constraints
// 5≤N≤10. Each location (x,y) is in a bounded grid, 0≤x≤100, 0≤y≤100, and x, y are integers.

// Input
// You are given 10 test cases. Each test case consists of two lines; the first line has N, the number of the customers, and the
// following line enumerates the locations of the office, Mr. Kim’s home, and the customers in sequence. Each location consists of
// the coordinates (x,y), which is represented by ‘x y’.

// Output

// Output the 10 answers in 10 lines. Each line outputs the distance of a (the) shortest path. Each line looks like ‘#x answer’
// where x is the index of a test case. ‘#x’ and ‘answer’ are separated by a space.

// I/O Example

// Input (20 lines in total. In the first test case, the locations of the office and the home are (0, 0) and (100, 100) respectively,
// and the locations of the customers are (70, 40), (30, 10), (10, 5), (90, 70), (50, 20).)
// 5 ← Starting test case #1
// 0 0 100 100 70 40 30 10 10 5 90 70 50 20
// 6 ← Starting test case #2
// 88 81 85 80 19 22 31 15 27 29 30 10 20 26 5 14
// 10 ← Starting test case #3
// 39 9 97 61 35 93 62 64 96 39 36 36 9 59 59 96 61 7 64 43 43 58 1 36
// Output (10 lines in total)

// #1 200

// #2 304

// #3 366

#include <iostream>
#include <climits>
using namespace std;

int x[20];
int y[20];
int n;
int ans;

int abs(int x)
{
    return x > 0 ? x : -x;
}

int distance(int i, int j)
{
    return abs(x[i] - x[j]) + abs(y[i] - y[j]);
}

void optimal_path(int i, bool visited[], int nodes, int value)
{
    if (n == nodes)
    {
        ans = min(ans, value + distance(i, n + 1));
    }
    for (int j = 1; j <= n; j++)
    {
        if (!visited[j])
        {
            visited[j] = true;
            optimal_path(j, visited, nodes + 1, value + distance(i, j));
            visited[j] = false;
        }
    }
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        ans = INT_MAX;
        cin >> n;
        cin >> x[n + 1] >> y[n + 1] >> x[0] >> y[0];
        for (int i = 1; i <= n; i++)
        {
            cin >> x[i] >> y[i];
        }
        bool visited[n + 2] = {false};
        optimal_path(0, visited, 0, 0);
        cout << ans << endl;
    }

    return 0;
}

// 3
// 5
// 0 0 100 100 70 40 30 10 10 5 90 70 50 20
// 6
// 88 81 85 80 19 22 31 15 27 29 30 10 20 26 5 14
// 10
// 39 9 97 61 35 93 62 64 96 39 36 36 9 59 59 96 61 7 64 43 43 58 1 36
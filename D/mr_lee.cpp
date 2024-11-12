// Mr. Lee has to travel various offices abroad to assist
// branches of each place. But he has a problem.
// The airfare would be real high as all offices he has to
// visit are in foreign countries. He wants to visit every
// location only one time and return home with the lowest
// expense. Help this company-caring man calculate the lowest
// expense.

// Input format
// Several test cases can be included in the inputs. T, the
// number of cases is given in the first row of the inputs.
// After that, the test cases as many as T (T ≤ 30) are given
// in a row. N, the number of offices to visit is given on
// the first row per each test case. At this moment, No. 1
// office is regarded as his company (Departure point).
// (1 ≤ N ≤ 12) Airfares are given to move cities in which
// branches are located from the second row to N number rows.
// i.e. jth number of ith row is the airfare to move from
// ith city to jth city. If it is impossible to move between
// two cities, it is given as zero.

// Output format
// Output the minimum airfare used to depart from his company, visit all offices, and then return his company on the
// first row per each test case.

// Example of Input

// 3
// 5
// 0 14 4 10 20
// 14 0 7 8 7
// 4 5 0 7 16
// 11 7 9 0 2
// 18 7 17 4 0
// 5
// 9 9 2 9 5
// 6 3 5 1 5
// 1 8 3 3 3
// 6 0 9 6 8
// 6 6 9 4 8
// 3
// 0 2 24
// 3 0 2
// 0 4 0

// Example of Output

// 30
// 18
// 31

#include <iostream>
#include <climits>
using namespace std;

int n, result;
void mincost(int **arr,bool *visited,int count,int cost,int source)
{
    if(count == n-1){
        if(arr[source][0] != 0){
            result = min(result, cost + arr[source][0]);
        }
        return;
    }
    for (int i = 0; i < n;i++){
        if(!visited[i] && arr[source][i] != 0){
            visited[i] = true;
            mincost(arr, visited, count + 1, cost + arr[source][i], i);
            visited[i] = false;
        }
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        int **arr = new int *[n];
        for (int i = 0; i < n; i++)
        {
            arr[i] = new int[n];
        }
        bool *visited = new bool[n];
        for (int i = 0; i < n; i++)
        {
            visited[i] = false;
            for (int j = 0; j < n; j++)
            {
                cin >> arr[i][j];
            }
        }
        result = INT_MAX;
        visited[0] = true;
        mincost(arr, visited, 0, 0, 0);
        result != INT_MAX ? cout << result << endl : cout << "-1\n";
    }
    return 0;
}
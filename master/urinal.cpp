/*
It is a well-researched fact that men in a restroom generally prefer to maximize their distance from already occupied stalls, by occupying the middle of the longest sequence of unoccupied places

10
10 1
10 2
10 3
10 4
10 5
10 6
10 7
10 8
10 9
10 10
output is the following

0000100000
0000100100
0100100100
0100100110
0100110110
0110110110
0110110111
0110111111
0111111111
1111111111

VERIFIED AND TESTED
*/

#include <iostream>
using namespace std;

void solve(int n, int k, int *a)
{

    for (int person = 1; person <= k; person++)
    {

        int last = 0;
        int len = 0;
        int ans = 0;

        for (int j = 0; j < n; j++)
        {

            if (a[j] == 0)
                len++;
            if (a[j] == 1)
                len = 0;
            if (len >= ans)
            {
                last = j;
                ans = len;
            }
        }

        int s = last - ans + 1;
        int mid = (s + last) / 2;
        a[mid] = 1;
        // cout<<ans<<" "<<s<<" "<<last<<endl;
    }
}

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        int k;
        cin >> n >> k;
        int a[n];
        for (int i = 0; i < n; i++)
            a[i] = 0;
        solve(n, k, a);
        for (int i = 0; i < n; i++)
            cout << a[i];
        cout << endl;
    }

    return 0;
}
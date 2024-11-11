// You are given an array of integers which represents positions available and an integer c(cows).
// Now you have to choose c positions such that minimum difference between cows is maximized.
// For example,
// 1 3 5 8 10
// c=3

// Output: 4
// 1 5 10

#include <bits/stdc++.h>
using namespace std;

bool solve(int x, int a[], int n, int k)
{
    int current_cow = 1;  
    int last_position = a[0];
    for (int i = 1; i < n; i++)
    {
        if (a[i] - last_position >= x)
        {
            current_cow++;
            last_position = a[i];
            if (current_cow >= k)
            {
                return true; 
            }
        }
    }
    return false;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        int a[n];
        for (int j = 0; j < n; j++)
        {
            cin >> a[j];
        }

        sort(a, a + n);

        int low = 1;                
        int high = a[n - 1] - a[0];
        int answer = 0;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (solve(mid, a, n, k))
            {
                answer = mid; 
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }

        cout << answer << endl;
    }

    return 0;
}
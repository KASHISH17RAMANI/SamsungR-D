/*
Farmer John has built a new long barn, with N (2 <= N <= 100,000) stalls. The stalls are located along a straight line at positions x1,...,xN (0 <= xi <= 1,000,000,000).

His C (2 <= C <= N) cows don't like this barn layout and become aggressive towards each other once put into a stall. To prevent the cows from hurting each other, FJ wants to assign the cows to the stalls, such that the minimum distance between any two of them is as large as possible. What is the largest minimum distance?
Input
t – the number of test cases, then t test cases follows.
* Line 1: Two space-separated integers: N and C
* Lines 2..N+1: Line i+1 contains an integer stall location, xi
Output
For each test case output one integer: the largest minimum distance.
*/

#include <bits/stdc++.h>
using namespace std;
int ans;
void aggcow(int n, int c, int a[], int l, int h)
{
    if (h >= l)
    {
        int mid = (h + l) / 2;
        // cout<<l<<" "<<mid<<" "<<h<<endl;
        int k = 0;
        int cnt = 1;
        for (int i = 1; i < n; i++)
        {
            if (a[i] - a[k] >= mid)
            {
                cnt++;
                k = i;
            }
        }
        // cout<<cnt<<endl;
        if (cnt >= c)
        {
            ans = mid;
            aggcow(n, c, a, mid + 1, h);
        }
        else
        {
            // cout<<mid<<"is to high"<<endl;
            aggcow(n, c, a, l, mid - 1);
        }
    }
    else
        return;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, c;
        cin >> n >> c;
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        sort(a, a + n);
        aggcow(n, c, a, 0, 10e9);
        cout << ans << endl;
    }
}
#include <iostream>
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    int k;
    cin >> k;
    int l = 0, r = n - 1;
    int cnt = n - k + 1, p = 0, ans = -1;
    while (l <= r)
    {
        if (abs(v[r]) > abs(v[l]))
        {
            ans = v[r];
            r--;
        }
        else
        {
            ans = v[l];
            l++;
        }
        p++;
        if (p == cnt)
            break;
    }
    cout << ans;
    return 0;
}
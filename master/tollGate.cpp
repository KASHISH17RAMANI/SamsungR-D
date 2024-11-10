#include <iostream>
using namespace std;

int n;
int cost[25];
int mens[25];

int ans;

void solve(int index, int one, int two, int three, int total)
{

    // optimization
    if (total > ans)
        return;

    int menAvailable = one + two + three;

    // base case
    if (index == n - 1)
    {
        if (menAvailable >= mens[n - 1])
            ans = min(ans, total);
        else
            ans = min(ans, total + cost[n - 1]);
        return;
    }

    // recursive case
    // hire the men
    solve(index + 1, one + mens[index], two, three, total + 2 * cost[index]);
    // pay the cost
    solve(index + 1, one, two, three, total + cost[index]);
    // fight the men
    if (menAvailable >= mens[index])
    {
        if (two + three < mens[index])
            one = menAvailable - mens[index];
        if (three < mens[index])
            two = (two + three <= mens[index]) ? 0 : two - mens[index] + three;
        solve(index + 1, 0, one, two, total);
    }
}

int main()
{

    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> mens[i] >> cost[i];

    ans = 1000000;

    solve(0, 0, 0, 0, 0);
    cout << ans << endl;
    return 0;
}
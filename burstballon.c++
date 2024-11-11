#include <iostream>
#include <climits>
using namespace std;

int dp[300][300]; // Static 2D array for memoization

int func(int left, int right, int *v)
{
    if (left > right)
    {
        return 0;
    }
    if (dp[left][right] != -1)
    {
        return dp[left][right];
    }

    int ans = INT_MIN;
    for (int last = left; last <= right; last++)
    {
        int coins = v[last] * v[left - 1] * v[right + 1] +
                    func(left, last - 1, v) +
                    func(last + 1, right, v);
        ans = max(ans, coins);
    }

    return dp[left][right] = ans;
}

int maxCoins(int N, int *arr)
{
    // Initialize dp array with -1
    for (int i = 0; i < 300; ++i)
    {
        for (int j = 0; j < 300; ++j)
        {
            dp[i][j] = -1;
        }
    }

    // Create a new array `v` with extra padding
    int *v = new int[N + 2];
    v[0] = 1;
    v[N + 1] = 1;

    for (int i = 0; i < N; i++)
    {
        v[i + 1] = arr[i];
    }

    int result = func(1, N, v);
    delete[] v; // Free dynamically allocated memory
    return result;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;

        int *arr = new int[N];
        for (int i = 0; i < N; i++)
        {
            cin >> arr[i];
        }

        cout << maxCoins(N, arr) << endl;

        delete[] arr; // Free dynamically allocated memory
    }
    return 0;
}

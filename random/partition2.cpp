#include <iostream>
#include <vector>
using namespace std;

int f(int idx, int sum, int arr[], int n, int totalSum,
      vector<vector<int>> &dp)
{
    if (idx == n)
    {
        // One subset sum is 'sum' and the other is
        // 'totalSum - sum'
        return abs((totalSum - sum) - sum);
    }

    if (dp[idx][sum] != -1)
    {
        // If the result for the current index
        // and sum is already computed, return it
        return dp[idx][sum];
    }

    // Include the current element in the sum
    int pick = f(idx + 1, sum + arr[idx], arr, n, totalSum, dp);

    // Exclude the current element from the sum
    int notPick = f(idx + 1, sum, arr, n, totalSum, dp);

    // Store the minimum result in the memoization table and
    // return it
    return dp[idx][sum] = min(pick, notPick);
}

int findMin(int arr[], int n)
{
    int totalSum = 0;
    for (int i = 0; i < n; i++)
    {
        totalSum += arr[i];
    }

    // Create a memoization table initialized with -1
    vector<vector<int>> dp(n + 1,
                           vector<int>(totalSum + 1, -1));

    // Call the recursive function 'f'
    return f(0, 0, arr, n, totalSum, dp);
}

int main()
{
    int arr[] = {3, 1, 4, 2, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Find the minimum difference between two sets
    cout << "The minimum difference of 2 sets is "
         << findMin(arr, n);

    return 0;
}

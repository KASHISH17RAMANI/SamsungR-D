#include <iostream>
using namespace std;

int dp[100][100];

/*
For n = 0, 1, 2, 3, … values of Catalan numbers are 1, 1, 2, 5, 14, 42, 132, 429, 1430, 4862, …. So are numbers of Binary Search Trees.

here the concept of binomial coefficient is used that is
C(n, k) = C(n-1, k-1) + C(n-1, k)
C(n, 0) = C(n, n) = 1
*/
int bst(int n, int k)
{
    if (k == 0 || k == n)
        return 1;
    if (dp[n][k] != -1)
        return dp[n][k];
    dp[n][k] = bst(n - 1, k - 1) + bst(n - 1, k);
    return dp[n][k];
}

// to calculate the binary trees just multiply n! to the number of bst's
int main()
{

    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int A = 2 * n;
    int B = n;
    for (int i = 0; i < 100; i++)
        for (int j = 0; j < 100; j++)
            dp[i][j] = -1;
    cout << bst(A, B) / (n + 1) << endl;
    return 0;
}
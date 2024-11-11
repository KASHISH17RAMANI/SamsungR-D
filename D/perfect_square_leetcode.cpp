// Given an integer n, return the least number of perfect square
// numbers that sum to n.

// A perfect square is an integer that is the square of an integer;
// in other words, it is the product of some integer with itself.
// For example, 1, 4, 9, and 16 are perfect squares while 3 and 11 are not .
// Input: n = 12
// Output: 3
// Explanation: 12 = 4 + 4 + 4.

int num_squares(int n){
    int dp[n + 1];
    for (int i = 0; i < n + 1;i++){
        dp[i] = 1e9;
    }
    dp[0] = 0;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j * j <= i;j++){
            dp[i] = min(dp[i], 1 + dp[i - j * j]);
        }
    }
    return dp[n];
}


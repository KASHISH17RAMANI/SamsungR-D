// Given n balloons, indexed from 0 to n-1. Each balloon is painted with a number on it represented by array nums. 
// You are asked to burst all the balloons. If the you burst balloon i you will get nums[left] * nums[i] * nums[right] coins.
// Here left and right are adjacent indices of i. After the burst, the left and right then becomes adjacent.

// Find the maximum coins you can collect by bursting the balloons wisely.
// Input: [3,1,5,8]
// Output: 167 

//leet_code

#include<bits/stdc++.h>
using namespace std;

// int solve(int i,int j,vector<int>&nums,vector<vector<int>>&dp){
//     if(i>j){
//         return 0;
//     }
//     if(dp[i][j] != -1){
//         return dp[i][j];
//     }
//     int max_coins = INT_MIN;
//     for (int k = i; k <= j;k++){
//         int coins = nums[i - 1] * nums[k] * nums[j + 1];
//         int remaining_coins = solve(i, k - 1, nums, dp) + solve(k + 1, j, nums, dp);
//         max_coins = max(max_coins, coins + remaining_coins);
//     }
//     return dp[i][j] = max_coins;
// }

// int max_coins(vector<int>&nums){
//     int n = nums.size();
//     nums.insert(nums.begin(), 1);
//     nums.push_back(1);
//     vector<vector<int>> dp(n + 2, vector<int>(n + 2, -1));
//     return solve(1, n, nums, dp);
// }

int max_coins(vector<int> &nums)
{
    int n = nums.size();
    nums.insert(nums.begin(), 1);
    nums.push_back(1);
    vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));

    for (int i = n; i >= 1;i--){
        for(int j=1;j<=n;j++){
            if(i>j){
                continue;
            }
            int maxi = INT_MIN;
            for (int ind = i; ind <= j;ind++){
                int coins = nums[i - 1] * nums[ind] * nums[j + 1];
                int remaining_coins = dp[i][ind-1] + dp[ind+1][j];
                maxi = max(maxi, coins + remaining_coins);
            }
            dp[i][j] = maxi;
        }
    }

    return dp[1][n];
}

int main(){
    int n;
    cin >> n;
    vector<int> nums;
    for (int i = 0; i < n;i++){
        int x;
        cin >> x;
        nums.push_back(x);
    }
    cout << max_coins(nums) << endl;
    return 0;
}
class Solution
{
public:
    int dp[305][305];
    int burst(vector<int> &nums, int left, int right)
    {
        if (left + 1 == right)
        {
            return 0;
        }
        if (dp[left][right] != -1)
            return dp[left][right];

        int maxCoins = 0;
        for (int i = left + 1; i < right; ++i)
        {
            int coins = nums[left] * nums[i] * nums[right] + burst(nums, left, i) + burst(nums, i, right);
            maxCoins = max(maxCoins, coins);
        }
        return dp[left][right] = maxCoins;
    }

    int maxCoins(vector<int> &nums)
    {
        memset(dp, -1, sizeof(dp));
        int n = nums.size();
        vector<int> extended_nums(n + 2, 1);
        for (int i = 1; i <= n; ++i)
        {
            extended_nums[i] = nums[i - 1];
        }
        return burst(extended_nums, 0, n + 1);
    }
};
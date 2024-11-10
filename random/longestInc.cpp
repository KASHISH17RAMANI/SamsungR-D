int longestSubsequence(int n, int a[])
{
    vector<int> ans;
    for (int i = 0; i < n; ++i)
    {
        auto it = lower_bound(ans.begin(), ans.end(), a[i]);
        if (it == ans.end())
        {
            ans.push_back(a[i]);
        }
        else
        {
            ans[it - ans.begin()] = a[i];
        }
    }
    return ans.size();
}
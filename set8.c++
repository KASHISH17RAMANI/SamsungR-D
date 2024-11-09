#include <iostream>
#include <climits>

using namespace std;

// } Driver Code Ends
// User function Template for C++

int kLevelSum(string s, int k)
{
    // code here
    // stack<char>st;
    int n = s.length();
    int ans = 0;
    int level = -1;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(')
        {
            // st.push(s[i]);
            ++level;
        }
        else if (s[i] == ')')
        {
            // while(st.top()!='(')
            // {
            //     st.pop();
            // }
            // st.pop();
            --level;
        }
        else
        {
            int num = 0;
            while (i < n && (s[i] != '(' && s[i] != ')'))
            {
                //    st.push(s[i]);
                num = num * 10 + (s[i] - '0');
                ++i;
            }
            --i;
            if (level == k)
            {
                ans += num;
            }
        }
    }
    return ans;
}

;

int main()
{
    string s;
    cin >> s;
    int k;
    cin >> k;
    int ans = kLevelSum(s, k);
    cout << ans;
    return 0;
}

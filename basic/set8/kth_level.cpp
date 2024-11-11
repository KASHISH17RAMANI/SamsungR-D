#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
    int kLevelSum(string s, int k)
    {
        int n = s.length();
        int ans = 0;
        int level = -1;          // Initial level is -1
        int levelSum[100] = {0}; // Array to store the sum for each level

        for (int i = 0; i < n; i++)
        {
            if (s[i] == '(')
            {
                level++; // Enter a new level
            }
            else if (s[i] == ')')
            {
                level--; // Exit a level
            }
            else
            {
                // Parse the number from the string
                int num = 0;
                while (i < n && s[i] != '(' && s[i] != ')')
                {
                    num = num * 10 + (s[i] - '0'); // Construct the number digit by digit
                    i++;
                }
                i--; // Adjust 'i' because it will be incremented in the loop

                // If the current level is k, add the number to the answer
                if (level == k)
                {
                    ans += num;
                }
            }
        }

        return ans;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s = {};
        int k;
        cin >> s >> k;

        Solution ob;
        cout << ob.kLevelSum(s, k) << endl;
    }
    return 0;
}

/*
3
(0(5(6()())(4()(9()())))(7(1()())(3()())))
1
(0(5(6()())(4()(9()())))(7(1()())(3()())))
2
(0(5(6()())(4()(9()())))(7(1()())(3()())))
3

Answers
12 14 9

// VERIFIED ON ABOVE TEST CASES WORKING FINE

*/

#include <iostream>
using namespace std;

int solve(char s[], int k)
{

    int lvl = -1;
    int ans = 0;

    int i = 0;
    while (s[i] != '\0')
    {

        if (s[i] == '(')
            lvl++;

        else if (s[i] == ')')
            lvl--;

        else if (lvl == k)
            ans += s[i] - '0';

        i++;
    }

    return ans;
}

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        char s[100];
        cin >> s;
        int k;
        cin >> k;
        cout << solve(s, k) << endl;
    }
    return 0;
}
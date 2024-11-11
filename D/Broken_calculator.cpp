// [Assuming each digit can be used only once]

// You are given old touch smartphone numbers having dial pad and calculator app.
// Aim: The goal is to type a number on the dial pad.
// But as the phone is old, some of the numbers and some operations can’t be touched.
// For eg. 2,3,5,9 keys are not responding, i.e you cannot use them
// But you can always make a number using other numbers and operations in Calculator. There could be multiple ways of making a number
// Calculator have 1-9 and +,-,\*,/,= as operations. Once you have made the number in Calculator you can copy the number and use it.
// You have to find the minimum number of touches required to obtain a number.
// Input:
// There will be multiple Test cases.Each test case will consist of 4 lines
// 1) The first line will consist of N, M, O
// N: no of keys working in Dialpad (out of 0,1,2,3,4,5,6,7,8,9)
// M:types of operations supported (+,-,*,/)
// O: Max no of touches allowed
// 2) second line of input contains the digits that are working e.g 0,2,3,4,6.
// 3) Third line contains the valued describing operations, 1(+),2(-),3(*),4(/)
// 4) fourth line contains the number that we want to make .
// Output:
// Output contains 1 line printing the number of touches required to make the number
// Sample Test Case:
// 1                   // No of test cases
// 5 3 5            // N ,M, O
// 1 2 4 6 0     // digits that are working (total number of digits = N),
// 1 2 3         // describing operations allowed (1–> ‘+’, 2–> ‘-‘, 3–> ‘*’ , 4–> ‘/’ )(total number is equals to M)
// 5                 // number we want to make
// Answer 3
// How 4? 1+4=, “=” is also counted as a touch
// 2nd Sample Case
// 3                   // No of Test cases
// 6 4 5            // N ,M, O
// 1 2 4 6 9 8  // digits that are working (total number of digits = N),
// 1 2 3 4        // describing operations allowed (1–> +, 2–> -, 3–> , 4–>/)
// 91                // number we want to make
// 6 3 5 // 2nd test case
// 0 1 3 5 7 9
// 1 2 4 // +, -, / allowed here
// 28
// 5 2 10
// 1 2 6 7 8
// 2 3               // -, allowed
// 981
// Output:
// 2        // 91 can be made by directly entering 91 as 1,9 digits are working, so only 2 operations
// 5            // 35-7=, other ways are 1+3*7=
// INTEGER_MAX_VALUE          //No ways

#include <iostream>
#include <vector>
#include <unordered_map>
#include <climits>
#include <string>
#include <algorithm>

using namespace std;

int ans = INT_MAX;

void getMinSteps(int target, unordered_map<int, int> &output, int cur_level, vector<int> &workingNumber, int o, int signs[])
{
    if (workingNumber.size() == 0)
    {
        // If no more numbers to process, return
        return;
    }

    // Loop over each working number and try operations
    for (int i = 0; i < workingNumber.size(); i++)
    {
        int cur_ele = workingNumber[i];
        // Remove current number from the working list
        workingNumber.erase(workingNumber.begin() + i);

        unordered_map<int, int> new_output;
        new_output[cur_ele] = 1; // initialize with the current number

        for (auto &entry : output)
        {
            int val = entry.first;
            int level = entry.second; // current level for this value

            // Add operation
            if (signs[0] == 1)
            {
                int newAdd = cur_ele + val;
                int newFreq = level + 3;
                if (new_output.find(newAdd) == new_output.end() || new_output[newAdd] > newFreq)
                {
                    new_output[newAdd] = newFreq;
                }
                if (newAdd == target && newFreq <= o)
                {
                    ans = min(ans, newFreq);
                }
            }

            // Subtract operation
            if (signs[1] == 1)
            {
                int newAdd = abs(cur_ele - val);
                int newFreq = level + 3;
                if (new_output.find(newAdd) == new_output.end() || new_output[newAdd] > newFreq)
                {
                    new_output[newAdd] = newFreq;
                }
                if (newAdd == target && newFreq <= o)
                {
                    ans = min(ans, newFreq);
                }
            }

            // Multiply operation
            if (signs[2] == 1)
            {
                int newAdd = cur_ele * val;
                int newFreq = level + 3;
                if (new_output.find(newAdd) == new_output.end() || new_output[newAdd] > newFreq)
                {
                    new_output[newAdd] = newFreq;
                }
                if (newAdd == target && newFreq <= o)
                {
                    ans = min(ans, newFreq);
                }
            }

            // Divide operation
            if (signs[3] == 1)
            {
                if (val != 0 && cur_ele >= val)
                {
                    if (cur_ele % val == 0)
                    {
                        int newAdd = cur_ele / val;
                        int newFreq = level + 3;
                        if (new_output.find(newAdd) == new_output.end() || new_output[newAdd] > newFreq)
                        {
                            new_output[newAdd] = newFreq;
                        }
                        if (newAdd == target && newFreq <= o)
                        {
                            ans = min(ans, newFreq);
                        }
                    }
                }
                else
                {
                    if (cur_ele != 0 && val % cur_ele == 0)
                    {
                        int newAdd = val / cur_ele;
                        int newFreq = level + 3;
                        if (new_output.find(newAdd) == new_output.end() || new_output[newAdd] > newFreq)
                        {
                            new_output[newAdd] = newFreq;
                        }
                        if (newAdd == target && newFreq <= o)
                        {
                            ans = min(ans, newFreq);
                        }
                    }
                }
            }

            // Concatenate as strings
            string one = to_string(cur_ele);
            string two = to_string(val);
            int newAdd = stoi(one + two);
            int newFreq = level + 1;
            if (new_output.find(newAdd) == new_output.end() || new_output[newAdd] > newFreq)
            {
                new_output[newAdd] = newFreq;
            }
            if (newAdd == target && newFreq <= o)
            {
                ans = min(ans, newFreq);
            }

            // Reverse concatenation as strings
            newAdd = stoi(two + one);
            if (new_output.find(newAdd) == new_output.end() || new_output[newAdd] > newFreq)
            {
                new_output[newAdd] = newFreq;
            }
            if (newAdd == target && newFreq <= o)
            {
                ans = min(ans, newFreq);
            }
        }

        // Add back the original numbers into the new_output map
        for (auto &entry : output)
        {
            int val = entry.first;
            int level = entry.second;
            if (new_output.find(val) == new_output.end())
            {
                new_output[val] = level;
            }
            else
            {
                new_output[val] = min(new_output[val], level);
            }
        }

        // Recurse with the new output map and the updated working list
        getMinSteps(target, new_output, cur_level + 1, workingNumber, o, signs);

        // Restore the current number back to the working list
        workingNumber.insert(workingNumber.begin() + i, cur_ele);
    }
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, m, o;
        cin >> n >> m >> o;

        vector<int> workingNumber(n);
        for (int i = 0; i < n; i++)
        {
            cin >> workingNumber[i];
        }

        int signs[4] = {0}; // For add, subtract, multiply, divide
        for (int i = 0; i < m; i++)
        {
            int num;
            cin >> num;
            signs[num - 1] = 1;
        }

        int target;
        cin >> target;

        unordered_map<int, int> output;
        getMinSteps(target, output, 1, workingNumber, o, signs);

        cout << ans << endl;
        ans = INT_MAX; // Reset the answer for the next test case
    }

    return 0;
}
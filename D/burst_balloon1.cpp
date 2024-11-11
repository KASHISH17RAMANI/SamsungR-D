// There are n balloons and n bullets and each balloon is assigned with a particular number (point).
// Whenever a particular balloon is shot the no of points increases by
// 1.the multiplication of point assigned to balloon on left and that of right side.
// 2.point assigned to left if no right exists
// 3.point assigned to right if no left exists.
// 4.the point assigned to itself if no other balloon exists.

// You have to output the maximum no of points possible.

// Input
// 1 2 3 4

// Output
// 20


#include <iostream>
using namespace std;

int max_coins(int arr[], int sz)
{
    int nums[sz + 2]; // Create an array to store the transformed values (with 1 at the boundaries)
    int n = 1;        // Start from 1 because nums[0] will be 1 (boundary)

    for (int i = 0; i < sz; i++)
    {
        if (arr[i] > 0)
        {
            nums[n] = arr[i]; // Put the value from arr into nums
            n++;
        }
    }
    nums[0] = nums[n] = 1; // Set the boundary values to 1
    n++;                   // Increase n by 1 to account for the extra boundary

    int dp[n][n] = {};

    // Fill the DP table for increasing sub array lengths
    for (int j = 2; j < n; j++)
    { // Sub array lengths from 2 to n-1
        for (int left = 0; left < n - j; left++)
        {                         // Try all possible left indices
            int right = left + j; // Calculate the right index of the current sub array

            // Try all possible positions i to burst the last balloon between left and right
            for (int i = left + 1; i < right; i++)
            {
                // If left == 0 and right == n-1, it's the outermost subproblem (bursting the first or last balloon)
                if (left == 0 && right == n - 1)
                {
                    dp[left][right] = max(
                        nums[left] * nums[i] * nums[right] + dp[left][i] + dp[i][right],
                        dp[left][right]);
                }
                // For the inner subproblems, calculate the optimal solution
                else
                {
                    dp[left][right] = max(
                        nums[left] * nums[right] + dp[left][i] + dp[i][right],
                        dp[left][right]);
                }
            }
        }
    }
    return dp[0][n - 1]; // Return the result from dp[0][n-1], which holds the max coins
}

int main()
{
    int sz;
    cin >> sz;   // Take the number of balloons as input
    int arr[sz]; // Declare the array to store balloon values
    for (int i = 0; i < sz; i++)
    {
        cin >> arr[i]; // Input the values of the balloons
    }

    // Call the function and print the result
    int ans = max_coins(arr, sz);
    cout << ans << endl;
    return 0;
}



// #include<iostream>
// using namespace std;

// int max_coins(int arr[],int sz){
//     int nums[sz + 2];
//     int n = 1;
//     for (int i = 0; i < sz; i++)
//     {
//         if (arr[i] > 0)
//         {
//             nums[n] = arr[i];
//             n++;
//         }
//     }
//     nums[0] = nums[n] = 1;
//     n++;
//     int dp[n][n] = {};
//     for (int j = 2; j < n;j++){
//         for (int left = 0; left < n - j;left++){
//             int right = left + j;
//             for (int i = left + 1; i < right;i++){
//                 if(left == 0 && right == n-1){
//                     dp[left][right] = max(nums[left] * nums[i] * nums[right] + dp[left][i] + dp[i][right], dp[left][right]);
//                 }
//                 else{
//                     dp[left][right] = max(nums[left]  * nums[right] + dp[left][i] + dp[i][right], dp[left][right]);
//                 }
//             }
//         }
//     }
//     return dp[0][n - 1];
// }

// int main(){
//     int sz;
//     cin >> sz;
//     int arr[sz];
//     for (int i = 0; i < sz;i++){
//         cin >> arr[i];
//     }

//     int ans = max_coins(arr, sz);
//     cout << ans << endl;
//     return 0;
// }
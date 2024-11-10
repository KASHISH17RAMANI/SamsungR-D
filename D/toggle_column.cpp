// It was a 3 hours coding round which had one question to solve and the
// maximum number of submissions allowed was 50, but we could compile it
// as much as we want. No STL is allowed.
// The question was :
// A binary matrix of nxm was given, you have to toggle any column k
// number of times so that you can get the maximum number of rows having
//  all 1’s.
// for eg, n=3, m=3,
//             1 0 0
//             1 0 1
//             1 0 0
// if k=2, then we will toggle column 2 and 3 once and we will get rows
// 1 and 3 with 1 1 1 and 1 1 1 i.e. all 1’s so answer is 2 as there are 2
// rows with all 1’s.

// if k=3, then we will toggle column 2 thrice and we will get row 2 with
//  1 1 1 i.e. all 1’s so answer is 1 as there is 1 row with all 1’s.

// #include <iostream>
// using namespace std;

// int grid[100][100];
// int temp[100][100];
// int maxi = -1;

// void restore(int grid[][100], int row, int col)
// {
//     for (int i = 0; i < row; i++)
//     {
//         for (int j = 0; j < col; j++)
//         {
//             grid[i][j] = temp[i][j];
//         }
//     }
// }

// int calculate_number_of_row_with_all_one(int grid[][100], int row, int col)
// {
//     int all_one = 0;
//     int ct = 0;
//     for (int i = 0; i < row; i++)
//     {
//         for (int j = 0; j < col; j++)
//         {
//             if (grid[i][j] == 1)
//             {
//                 all_one++;
//             }
//             if (all_one == col)
//             {
//                 ct++;
//             }
//         }
//         all_one = 0;
//     }
//     return ct;
// }

// void flip_col(int grid[][100], int row, int col, int k)
// {
//     for (int i = 0; i < row; i++)
//     {
//         if (grid[i][k] == 1)
//         {
//             grid[i][k] = 0;
//         }
//         else if (grid[i][k] == 0)
//         {
//             grid[i][k] = 1;
//         }
//     }
// }

// void combination_util(int arr[], int data[], int start, int end, int index, int r, int row, int col)
// {
//     if (index == r)
//     {
//         for (int j = 0; j < r; j++)
//         {
//             flip_col(grid, row, col, data[j]);
//         }
//         if (maxi < calculate_number_of_row_with_all_one(grid, row, col))
//         {
//             maxi = calculate_number_of_row_with_all_one(grid, row, col);
//         }
//         restore(grid, row, col);
//         return;
//     }
//     for (int i = start; i <= end && end - i + 1 >= r - index; i++)
//     {
//         data[index] = arr[i];
//         combination_util(arr, data, i + 1, end, index + 1, r, row, col);
//     }
// }

// void print_combination(int arr[], int n, int r, int row, int col)
// {
//     int data[r];
//     combination_util(arr, data, 0, n - 1, 0, r, row, col);
// }

// int main()
// {
//     int t = 0;
//     cin >> t;
//     while (t--)
//     {
//         int row, col, s;
//         cin >> row >> col >> s;
//         int arr[col];

//         for (int i = 0; i < col; i++)
//         {
//             arr[i] = i;
//         }

//         for (int i = 0; i < row; i++)
//         {
//             for (int j = 0; j < col; j++)
//             {
//                 cin >> grid[i][j];
//                 temp[i][j] = grid[i][j];
//             }
//         }

//         maxi = calculate_number_of_row_with_all_one(temp, row, col);

//         if (s % 2 == 0 && s >= col)
//         {
//             for (int i = 2; i <= col; i += 2)
//             {
//                 print_combination(arr, col, i, row, col);
//                 restore(grid, row, col);
//             }
//         }

//         if (s % 2 != 0 && s >= col)
//         {
//             for (int i = 1; i <= col; i += 2)
//             {
//                 print_combination(arr, col, i, row, col);
//                 restore(grid, row, col);
//             }
//         }

//         if (s % 2 == 0 && s < col)
//         {
//             for (int i = 2; i <= s; i += 2)
//             {
//                 print_combination(arr, col, i, row, col);
//                 restore(grid, row, col);
//             }
//         }

//         if (s % 2 != 0 && s < col)
//         {
//             for (int i = 1; i <= s; i += 2)
//             {
//                 print_combination(arr, col, i, row, col);
//                 restore(grid, row, col);
//             }
//         }

//         cout << maxi << endl;
//     }

//     return 0;
// }

// #include <iostream>
// #include <cstring>
// #include <climits>
// using namespace std;

// int main()
// {
//     int n, m, k;
//     cin >> n >> m >> k;
//     int mat[n][m];

//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < m; j++)
//         {
//             cin >> mat[i][j];
//         }
//     }
//     int ans = INT_MIN;

//     // A helper function to convert a row to a unique string representation
//     // and find the frequency of each row pattern
//     int freq[n * m];
//     memset(freq, 0, sizeof(freq));

//     // Storing frequency of each row pattern in the matrix
//     for (int i = 0; i < n; i++)
//     {
//         int rowHash = 0;
//         for (int j = 0; j < m; j++)
//         {
//             rowHash = (rowHash << 1) | mat[i][j]; // Using bitwise shift to create a unique hash for the row
//         }
//         freq[rowHash]++; // Increment the frequency of this unique row pattern
//     }

//     // Check each unique row pattern and calculate the number of zeros
//     for (int i = 0; i < n * m; i++)
//     {
//         if (freq[i] > 0)
//         {
//             int num_zeros = 0;
//             // Calculate the number of zeros in the current pattern
//             for (int j = 0; j < m; j++)
//             {
//                 if ((i & (1 << (m - 1 - j))) == 0)
//                 { // Check each bit if it's 0
//                     num_zeros++;
//                 }
//             }

//             // If the number of zeros is <= k and (k - num_zeros) is even
//             if (num_zeros <= k && (k - num_zeros) % 2 == 0)
//             {
//                 ans = max(ans, freq[i]); // Update the answer with the maximum frequency
//             }
//         }
//     }

//     // Output the result
//     cout << "Maximum Rows that can be 1 are: " << ans << endl;

//     return 0;
// }

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

// Function to count the number of zeros in a binary string
int countZeros(const string &row)
{
    int count = 0;
    for (char c : row)
    {
        if (c == '0')
        {
            count++;
        }
    }
    return count;
}

int main()
{
    int n, m, k;
    cin >> n >> m >> k; // Input dimensions of the matrix and number of toggles allowed

    // Matrix input
    vector<vector<int>> mat(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> mat[i][j];
        }
    }

    // We will store the frequency of each row in the form of a string
    vector<pair<string, int>> rowFreq; // Each entry stores (row string, frequency)

    // Convert rows to strings and count their frequencies
    for (int i = 0; i < n; i++)
    {
        string row = "";
        for (int j = 0; j < m; j++)
        {
            row += to_string(mat[i][j]); // Convert each cell to a string
        }

        // Check if this row already exists
        bool found = false;
        for (int j = 0; j < rowFreq.size(); j++)
        {
            if (rowFreq[j].first == row)
            {
                rowFreq[j].second++; // Increment the frequency if it already exists
                found = true;
                break;
            }
        }

        if (!found)
        {
            rowFreq.push_back({row, 1}); // Add new row with frequency 1
        }
    }

    // Now find the maximum frequency of rows that can be toggled to have k or fewer zeros
    int ans = INT_MIN;

    for (int i = 0; i < rowFreq.size(); i++)
    {
        // Count zeros in the current row string
        int numZeros = countZeros(rowFreq[i].first);

        if (numZeros <= k && (k - numZeros) % 2 == 0)
        {
            ans = max(ans, rowFreq[i].second); // Update the maximum frequency
        }
    }

    cout << "Maximum Rows that can be 1 are: " << ans << endl;

    return 0;
}

// 1
// 3 3 2
// 1 0 0 
// 1 0 1
// 1 0 0 
// 2 - o/p

// 1
// 3 3 1
// 1 0 0 
// 1 0 1
// 1 0 0 
// 1 -o/p

// ((k - num_zero )%2 == 0  && num_zero <= k)-- we convert to all 1 in row
// ans = max(ans,f)
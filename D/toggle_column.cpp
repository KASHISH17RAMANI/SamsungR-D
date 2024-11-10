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

#include <iostream>
using namespace std;

int grid[100][100];
int temp[100][100];
int maxi = -1;

void restore(int grid[][100], int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            grid[i][j] = temp[i][j];
        }
    }
}

int calculate_number_of_row_with_all_one(int grid[][100], int row, int col)
{
    int all_one = 0;
    int ct = 0;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (grid[i][j] == 1)
            {
                all_one++;
            }
            if (all_one == col)
            {
                ct++;
            }
        }
        all_one = 0;
    }
    return ct;
}

void flip_col(int grid[][100], int row, int col, int k)
{
    for (int i = 0; i < row; i++)
    {
        if (grid[i][k] == 1)
        {
            grid[i][k] = 0;
        }
        else if (grid[i][k] == 0)
        {
            grid[i][k] = 1;
        }
    }
}

void combination_util(int arr[], int data[], int start, int end, int index, int r, int row, int col)
{
    if (index == r)
    {
        for (int j = 0; j < r; j++)
        {
            flip_col(grid, row, col, data[j]);
        }
        if (maxi < calculate_number_of_row_with_all_one(grid, row, col))
        {
            maxi = calculate_number_of_row_with_all_one(grid, row, col);
        }
        restore(grid, row, col);
        return;
    }
    for (int i = start; i <= end && end - i + 1 >= r - index; i++)
    {
        data[index] = arr[i];
        combination_util(arr, data, i + 1, end, index + 1, r, row, col);
    }
}

void print_combination(int arr[], int n, int r, int row, int col)
{
    int data[r];
    combination_util(arr, data, 0, n - 1, 0, r, row, col);
}

int main()
{
    int t = 0;
    cin >> t;
    while (t--)
    {
        int row, col, s;
        cin >> row >> col >> s;
        int arr[col];

        for (int i = 0; i < col; i++)
        {
            arr[i] = i;
        }

        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                cin >> grid[i][j];
                temp[i][j] = grid[i][j];
            }
        }

        maxi = calculate_number_of_row_with_all_one(temp, row, col);

        if (s % 2 == 0 && s >= col)
        {
            for (int i = 2; i <= col; i += 2)
            {
                print_combination(arr, col, i, row, col);
                restore(grid, row, col);
            }
        }

        if (s % 2 != 0 && s >= col)
        {
            for (int i = 1; i <= col; i += 2)
            {
                print_combination(arr, col, i, row, col);
                restore(grid, row, col);
            }
        }

        if (s % 2 == 0 && s < col)
        {
            for (int i = 2; i <= s; i += 2)
            {
                print_combination(arr, col, i, row, col);
                restore(grid, row, col);
            }
        }

        if (s % 2 != 0 && s < col)
        {
            for (int i = 1; i <= s; i += 2)
            {
                print_combination(arr, col, i, row, col);
                restore(grid, row, col);
            }
        }

        cout << maxi << endl;
    }

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
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int abs(int n)
{
    return (n < 0) ? -n : n;
}

int main()
{
    int t;
    cin >> t;

    while (t-- > 0)
    {
        int n;
        cin >> n;
        bool allNeg = true;
        vector<int> arr(n);

        // Reading array elements and checking if all are negative
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            if (arr[i] > 0)
                allNeg = false;
        }

        // If all elements are negative, the smallest missing positive is 1
        if (allNeg)
        {
            cout << "1" << endl;
            continue;
        }

        // Partitioning the array into negatives and non-negative numbers
        int i = 0, j = n - 1;
        while (i < j)
        {
            if (arr[i] < 0)
                i++;
            else if (arr[j] >= 0)
                j--;
            else if (arr[i] >= 0 && arr[j] < 0)
            {
                swap(arr[i], arr[j]);
                i++;
                j--;
            }
        }

        // Find the index of the first positive number
        for (int i1 = 0; i1 < n; i1++)
        {
            if (arr[i1] >= 0)
            {
                i = i1;
                break;
            }
        }

        // max_positive represents the range of positive integers we are considering
        int max_positive = n - i;

        // Marking the corresponding index negative if the element is found
        for (int x = i; x < n; x++)
        {
            if (abs(arr[x]) > max_positive)
                continue;

            int index = i + abs(arr[x]) - 1;
            if (arr[index] > 0)
                arr[index] = -arr[index];
            else if (arr[index] == 0)
                arr[index] = -10000001; // Used as a marker for zero
        }

        bool ansFound = false;

        // Find the first missing positive integer
        for (int z = i; z < n; z++)
        {
            if (arr[z] >= 0)
            {
                cout << z - i + 1 << endl;
                ansFound = true;
                break;
            }
        }

        // If no missing element is found, it means all numbers from 1 to max_positive are present
        if (!ansFound)
            cout << max_positive + 1 << endl;
    }

    return 0;
}
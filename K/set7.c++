#include <iostream>
using namespace std;

// Function to check if a number contains "ominous" digits (3 or 4)
bool isSellable(int num)
{
    while (num)
    {
        int t = num % 10;
        if (t == 3 || t == 4)
        {
            return false; // Not sellable if it has ominous digit
        }
        num /= 10;
    }
    return true; // Sellable if no ominous digits found
}

// Function to count sellable products in the range [s, e]
int countSellableProducts(int s, int e, int k)
{
    int count = 0;
    for (int i = s; i <= e; i++)
    {
        if (isSellable(i))
        {
            ++count; // Increment count if product is sellable
        }
    }
    return count;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int s, e, k;
        cin >> s >> e >> k;

        int count = countSellableProducts(s, e, k);
        cout << count << endl;
    }

    return 0;
}

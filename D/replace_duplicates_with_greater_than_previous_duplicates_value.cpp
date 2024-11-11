// Input : arr = {1, 2, 2, 5, 8, 8, 8} 
// Output : 1 2 3 5 8 9 10 
// 8 is replaced with 9 (A non-existing element greater than 8). Next, duplicate occurrence of 8 is replaced with 10.


// Input : arr = {1, 2, 5, 7, 8, 8, 7} 
// Output : 1 2 5 7 8 9 10


// Input : arr = {9, 9, 9, 9, 9} 
// Output : 9 10 11 12 13 


#include<bits/stdc++.h>
using namespace std;

void solve(int arr[],int n){
    unordered_set<int> s;
    for (int i = 0; i < n;i++){
        if(s.find(arr[i]) == s.end()){
            s.insert(arr[i]);
        }
        else{
            for (int j = arr[i] + 1; j < INT_MAX;j++){
                if(s.find(j) == s.end()){
                    arr[i] = j;
                    s.insert(j);
                    break;
                }
            }
        }
    }
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n;i++){
        cin >> arr[i];
    }
    solve(arr, n);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}
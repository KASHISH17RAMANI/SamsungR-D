// There are N pots. Every pots has some water in it. They may be partially filled. 
// Every pot is associated with overflow number O which tell how many minimum no. of stones required 
// for that pot to overflow. The crow know O1 to On(overflow no. for all the pots). Crow wants some K 
// pots to be overflow. So the task is minimum number of stones he can make K pots overflow in worst case.

// Array of overflow no--. {1,...,On}
// Number of pots--n
// No of pots to overflow-- k

// Let say two pots are there with overflow no.s {5,58}, and crow has to overflow one pot(k=1). 
// So crow will put 5 stones in pot with overflow no.(58), it will not overflow, then he will put in 
// pot with overflow no.(5), hence the total no. of stones to make overflow one pot is=10.


#include<iostream>
#include<algorithm>
using namespace std;

int k, n;

void merge(int a[],int left,int mid,int right){
    int i = 0;
    int j = 0;
    int k=left;
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int l[n1];
    int r[n2];
    for (int i = 0; i < n1;i++){
        l[i] = a[left+i];
    }
    for (int j = 0; j < n2;j++){
        r[j] = a[mid + 1 + j];
    }
    while(i<n1 && j<n2){
        if(l[i] <= r[j]){
            a[k] = l[i];
            i++;
        }
        else
        {
            a[k] = r[j];
            j++;
        }
        k++;
    }
    while(i<n1){
        a[k++] = l[i++];
    }
    while(j<n2){
        a[k++] = r[j++];
    }
}

void mergesort(int a[],int left,int right){
    if (left<right){
        int mid = left + (right - left) / 2;
        mergesort(a, left, mid);
        mergesort(a, mid + 1, right);
        merge(a, left, mid, right);
    }
}


int min_crow_pot_stone(int arr[]){
    int total_stone = 0;
    for (int i = n - 1; i > 0;i--){
        arr[i] = max(0, arr[i] - arr[i - 1]);
    }
    for (int i = 0; i < k;i++){
        total_stone += (arr[i] * (n - i));
    }
    return total_stone;
}

int main(){
    cin >> n;
    int arr[n + 1];
    for (int i = 0;i<n;i++){
        cin >> arr[i];
    }
    cin >> k;
    mergesort(arr, 0, n - 1);
    cout << min_crow_pot_stone(arr);
    return 0;
}


// 2
// 5 58
// 1
// o/p - 10

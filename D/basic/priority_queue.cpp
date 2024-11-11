#include<iostream>
using namespace std;

const int MAX = 100;
int priority_queue[MAX];
int size = -1;

void enqueue(int x){
    size++;
    priority_queue[size] = x;
}

int peek(){
    int highest = -10000000;
    int ind = -1;
    for (int i = 0; i <= size;i++){
        if(highest < priority_queue[i]){
            highest = priority_queue[i];
            ind = i;
        }
        else if (ind >-1 && priority_queue[ind] < priority_queue[i]){
            highest = priority_queue[i];
            ind = i;
        }
    }
    return ind;
}

int dequeue(){
    int ind = peek();
    int x = priority_queue[ind];
    for (int i = ind; i < size;i++){
        priority_queue[i] = priority_queue[i + 1];
    }
    size--;
    return x;
}

int main(){
    int n;
    cin >> n;
    for (int i = 0; i < n;i++){
        int x;
        cin >> x;
        enqueue(x);
    }
    cout<<dequeue()<<endl;

    for (int i = 0; i <= size;i++){
        cout << priority_queue[i] << " ";
    }
    return 0;
}
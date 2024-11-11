#include<iostream>
using namespace std;
const int MAXX = 100;
int st[MAXX];
int top = -1;
bool push(int x){
    if(top >= MAXX-1){
        return false;
    }
    else{
        st[++top] = x;
        return true;
    }
}
int pop(){
    if(top < 0){
        return -1000000;
    }
    else{
        int x = st[top--];
        return x;
    }
}
int peek(){
    if (top < 0)
    {
        return -1000000;
    }
    else
    {
        int x = st[top];
        return x;
    }
}

int main(){
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        push(x);
    }
    cout << peek() << endl;
    cout << pop() << endl;
    cout << peek() << endl;

    cout << pop() << endl;
    cout << peek() << endl;

    cout << pop() << endl;
    cout << peek() << endl;

    cout << pop() << endl;
    cout << peek() << endl;

    cout << pop() << endl;
    cout << peek() << endl;
}
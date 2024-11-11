// You want to cut a piece of paper by a certain fixed rule to make some pieces of white or 
// blue colored square paper with various sizes.  
 
// If the size of the entire paper is N×N (N = 2^K; 1 <= K <= 7; K = natural number), the cutting rules
// are as below.
 
// ‘If the entire piece of paper is not colored the same, cut the middle part horizontally and vertically 
// to divide it into the same sized four pieces of paper, 
// (N/2)×(N/2), as with I, II, III, IV in < FIG. 2 >. 

// For each I, II, III and IV, cut and divide again in the same way if one entire piece of paper 
// is not colored the same, and make them into the same sized four pieces of paper. Continue until each and 
// every piece of paper has only one color of white or blue.’
 
// When you finish, < FIG. 3 > shows the first division of < FIG. 1 > and < FIG. 4 > 
// shows the final version of 9 pieces of white paper and 7 pieces of blue paper of various sizes.
 
// If the length of an edge of the first given piece of paper, N, and 
// the color information (white or blue) inside each square are given, create a calculation program
//  that assesses how many white/blue pieces of paper are.
 
// Time limit: 1 second (java: 2 seconds) 
 
// [Input]
 
// Input may include many test cases. The number of test cases, T, is given on the first line of input and then the amount of T of test cases is given in a line. (T <= 30)
// The length of an edge of the first given piece of paper, N, is given for the first line of each test case.
// From the next line through to the amount of N lines, the color information is given separately as blanks. 0 indicates white and 1 indicates blue.
 
// [Output]
 
// For each test case, you should print "Case #T" in the first line where T means the case number. 
 
// For each test case, you should output the number of white pieces of paper and blue pieces of paper separately as blanks on the first line of each test case.
 
// [I/O Example]
// Input 
// 2
// 8
// 1 1 0 0 0 0 1 1
// 1 1 0 0 0 0 1 1
// 0 0 0 0 1 1 0 0
// 0 0 0 0 1 1 0 0
// 1 0 0 0 1 1 1 1
// 0 1 0 0 1 1 1 1 
// 0 0 1 1 1 1 1 1
// 0 0 1 1 1 1 1 1
 
 
// 16
// 1 0 0 1 0 0 0 0 0 0 1 1 0 1 1 1
// 1 1 0 1 0 1 1 0 0 0 0 0 0 0 0 0
// 0 0 0 0 1 0 1 1 1 1 0 0 1 0 0 1
// 1 1 0 0 1 0 0 1 0 0 1 0 1 1 1 0
// 0 1 1 1 0 0 1 1 0 0 1 0 0 1 1 1
// 1 0 1 1 0 0 0 1 0 1 0 1 0 0 1 1
// 1 1 1 1 1 1 0 0 1 1 1 1 1 0 0 0
// 1 1 0 1 0 1 0 0 1 0 1 1 1 0 0 1
// 1 1 1 1 1 1 0 0 1 0 1 1 0 1 1 0
// 1 0 0 1 1 1 0 0 0 0 1 1 1 1 0 0
// 1 0 0 1 1 1 1 0 0 0 1 1 0 1 0 1
// 1 1 1 0 1 1 0 0 1 1 1 1 1 1 0 1
// 1 1 1 1 1 1 0 0 0 0 1 1 1 1 0 0
// 1 1 1 1 1 1 0 1 1 1 1 1 1 1 0 0
// 1 1 0 0 0 0 0 0 1 1 0 1 1 0 0 0
// 1 1 0 0 1 1 0 0 0 1 1 1 1 0 0 0
 
 
 
// Output
 
// Case #1
// 9 7
 
// Case #2
// 88 99


#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int MAX = 129;
int white = 0;
int blue = 0;

bool check_same(bool arr[MAX][MAX],int i,int j,int sz){
    bool color = arr[i][j];
    for (int k = i; k < sz + i;k++){
        for (int l = j; l < j + sz;l++){
            if (arr[k][l] != color){
                return false;
            }
        }
    }
    return true;
}

void solve(bool arr[MAX][MAX],int sz,int i,int j){
    bool same = check_same(arr,i,j,sz);
    if(!same){
        solve(arr, sz / 2, i, j);
        solve(arr, sz / 2, i + sz / 2, j);
        solve(arr, sz / 2, i, j + sz / 2);
        solve(arr, sz / 2, i + sz / 2, j + sz / 2);
    }
    else{
        (arr[i][j]) ? ++blue : ++white;
    }
}

int main(){
    int t;
    cin >> t;
    while(t--){
        white = 0;
        blue = 0;
        int sz;
        cin >> sz;
        bool arr[MAX][MAX];
        for (int i = 0; i < sz;i++){
            for (int j = 0; j < sz;j++){
                cin >> arr[i][j];
            }
        }
        solve(arr, sz, 0, 0);
        cout << white << " " << blue << endl;
    }
}
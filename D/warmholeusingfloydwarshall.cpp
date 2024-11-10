// There is one spaceship. X and Y co-odinate of source of spaceship and destination spaceship is given.
// There are N number of warmholes; each warmhole has 5 values. First 2 values are starting co-ordinate
// of warmhole and after that value no. 3 and 4 represents ending co-ordinate of warmhole and last 5th 
// value is represents cost to pass through this warmhole. Now these warmholes are bi-directional. Now 
// the to go from (x1,y1) to (x2,y2) is abs(x1-x2)+abs(y1-y2). The main problem here is to find minimum 
// distance to reach spaceship from source to destination co-ordinate using any number of warm-hole. 
// It is ok if you wont use any warmhole.


#include<iostream>
using namespace std;

struct node{
    int x;
    int y;
    node(int x,int y){
        this->x = x;
        this->y = y;
    }
};

int abs(int x){
    return (x < 0) ? -x : x;
}

int find_distance(struct node *first,struct node *second){
    return (abs(first->x - second->x) + abs(first->y - second->y));
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int warmhole;
        cin >> warmhole;

        int node1 = 2 * warmhole + 2;
        node *location[node1];
        int cost[node1][node1];
        for (int i = 0; i < node1;i++){
            for (int j = 0; j < node1;j++){
                cost[i][j] = -1;
            }
        }

        // source
        int source_x,source_y;
        cin >> source_x >> source_y;
        node *source = new node(source_x, source_y);
        location[0] = source;

        // destination
        int destination_x, destination_y;
        cin >> destination_x >> destination_y;
        node *destination = new node(destination_x, destination_y);
        location[node1 - 1] = destination;

        // warmhole
        for (int i = 0; i < warmhole;i++){
            int x1, y1;
            cin >> x1 >> y1;
            node *temp1 = new node(x1, y1);
            int x2, y2;
            cin >> x2 >> y2;
            node *temp2 = new node(x2, y2);
            int w;
            cin >> w;
            location[2 * i + 1] = temp1;
            location[2 * i + 2] = temp2;
            cost[2 * i + 1][2 * i + 2] = w;
            cost[2 * i + 2][2 * i + 1] = w;
        }

        // initialise cost matrix
        for (int i = 0; i < node1;i++){
            for (int j = 0; j < node1;j++){
                if(cost[i][j] == -1){
                    cost[i][j] = find_distance(location[i], location[j]);
                }
            }
        }

        // floyd Warshall
        for (int k = 0; k < node1;k++){
            for (int i = 0; i < node1;i++){
                for (int j = 0; j<node1;j++){
                    if(i == k || j == k){
                        continue;
                    }
                    cost[i][j] = min(cost[i][j], cost[i][k] + cost[k][j]);
                }
            }
        }
        cout << cost[0][node1 - 1] << endl;
    }
    return 0;
}

// 1
// 3
// 0 0 100 100 
// 1 2 120 120 2
// 4 5 120 100 3
// 6 8 150 180 4
// 32 -- output
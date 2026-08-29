#include <bits/stdc++.h>
using namespace std;

vector<int> V[11]; // taken 11 for mapping 10 inputs easily

// for weighted graph need another adjacency list

int main(){
    int n,e;
    cin >> n >> e;
    for(int i=0; i < e; i++){
        int a,b;
        cin >> a >> b;
        V[a].push_back(b);
        V[b].push_back(a);
    }

    for(int i = 1; i <= n ; i++){
        cout << i << " -> ";
        for(int j=0; j < V[i].size();j++){
            cout << V[i][j] << " ";
        }
         cout << endl;
    }
}

/* SAMPLE INPUT
10 13

1 2
1 3
1 4
4 7
7 3
3 8
7 9
7 8
8 5
9 10
5 10
10 6
2 6
*/

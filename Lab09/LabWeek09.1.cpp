#include <bits/stdc++.h>
using namespace std;

vector<int> V[100];
vector<int> C[100];


int main(){
    int n,e;
    cin >> n >> e;
    for(int i=0; i < e; i++){
        int a,b,cost;
        cin >> a >> b >> cost;
        V[a].push_back(b);
        V[b].push_back(a);

        C[a].push_back(cost);
        C[b].push_back(cost);
    }
    // for bi-directional graph
    for(int i = 1; i <= n ; i++){
        cout << i << " -> ";
        for(int j=0; j < V[i].size();j++){
            cout << V[i][j] << " ";
        }
         cout << endl;
    }
    // for weighted adjacency graph
    for(int i = 1; i <= n ; i++){
        cout << i << " -> ";
        for(int j=0; j < C[i].size();j++){
            cout << C[i][j] << " ";
        }
         cout << endl;
    }
}


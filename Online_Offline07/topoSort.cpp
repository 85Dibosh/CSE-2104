#include <bits/stdc++.h>
using namespace std;

void DFS_Visit(int v,const vector<vector<int>> &G, vector<bool> &visited,stack<int> &s){
    visited[v] = true;

    for(int w: G[v]){
        if(!visited[w]){
            DFS_Visit(w,G,visited,s);
        }
    }
    s.push(v);
}

void topoSort(int n,const vector<vector<int>> &G){
    vector<bool> visited(n+1,false);
    stack<int> s;

    for(int i = 1; i <= n; i++ ){
        if(!visited[i]){
            DFS_Visit(i,G,visited,s);
        }
    }

    cout << "Topo Order: ";
    while(!s.empty()){
        cout << s.top() <<" ";
        s.pop();
    }
    cout << endl;
}

int main(){
    int n, e;
    cout << "Enter number of vertices: ";
    cin >> n;
    cout << "Enter number of edges: ";
    cin >> e;

    vector<vector<int>> G(n+1);

    for(int i = 0; i < e; i++){
        int a,b;
        cin >> a >> b;
        G[a].push_back(b);
    }

    topoSort(n,G);

}

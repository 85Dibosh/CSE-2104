#include <bits/stdc++.h>
using namespace std;

vector<int> G[100];

void BFS(int v){
    vector<bool> marked(100,false);
    queue<int> q;
    q.push(v);
    while(!q.empty()){
        v = q.front();
        q.pop();
        if(!marked[v]){
            cout << v << " ";
            marked[v] = true;
            for(int i = 0; i < G[v].size();i++){
                int w = G[v][i];
                if(!marked[w]){
                    q.push(w);
                }
            }
        }
    }
}

int main(){
    int n,e;
    cout << "Enter number of vertices: ";
    cin >> n;
    cout << "Enter number of edges: ";
    cin >> e;

    cout << "Enter nodes: " << endl;
    for(int i = 0; i < e; i++ ){
        int a,b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    cout << "Enter starting node: ";
    int start;
    cin >> start;
    cout << "BFS: ";
    BFS(start);
}

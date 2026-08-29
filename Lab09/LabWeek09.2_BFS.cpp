#include <bits/stdc++.h>
using namespace std;

vector<int> G[11]; // taken 11 for mapping 10 inputs easily


void BFS(int v){
    vector<bool> marked(11,false);
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

void DFS(int v){
    vector<bool> marked(11,false);
    stack<int> s;
    s.push(v);

    while(!s.empty()){
        v = s.top();
        s.pop();
        if(!marked[v]){
            cout << v << " ";
            marked[v] = true;
            for(int i = 0; i < G[v].size();i++){
                int w = G[v][i];
                if(!marked[w]){
                    s.push(w);
                }
            }
        }
    }
}
int main(){
    int n,e;
    cin >> n >> e;
    for(int i=0; i < e; i++){
        int a,b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    for(int i = 1; i <= n ; i++){
        cout << i << " -> ";
        for(int j=0; j < G[i].size();j++){
            cout << G[i][j] << " ";
        }
         cout << endl;
    }
    cout << "Enter starting node: ";
    int start;
    cin >> start;
    cout << "BFS: ";
    BFS(start);
    cout << endl;
    cout << "DFS: ";
    DFS(start);
}


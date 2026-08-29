#include <bits/stdc++.h>
using namespace std;

vector<int> G[100];

vector<bool> markedR(100,false);
void DFS_Recursive(int v){
    cout << v << " ";
    markedR[v]=true;

    for(int i = 0; i < G[v].size(); i++){
        int w = G[v][i];
        if(!markedR[w]){
            DFS_Recursive(w);
        }
    }
}
void DFS(int v){
    vector<bool> marked(100,false);
    stack<int> s;
    s.push(v);
    while(!s.empty()){
        v = s.top();
        s.pop();
        if(!marked[v]){
            cout << v << " ";
            marked[v] = true;
            for(int i = G[v].size() - 1; i >= 0; i--){
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
    cout << "DFS: ";
    DFS(start);
    cout << endl << "DFS Recursive: ";
    DFS_Recursive(start);
}


#include<bits/stdc++.h>
using namespace std;

bool hasCycleBFS(int n, const vector<vector<int>> &G){
    vector<bool> marked(n,false);
    for(int i = 1 ; i <= n; i++){
        if(!marked[i]){
            queue<pair<int,int>> q;
            q.push({i,-1});
            marked[i] = true;

            while(!q.empty()){
                int u = q.front().first;
                int parent = q.front().second;
                q.pop();

                for(int v : G[u] ){
                    if(marked[v] && v != parent){
                        return true;
                    }
                    else if(!marked[v]){
                        marked[v] = true;
                        q.push({v,u});
                    }
                }
            }
        }
    }
    return false;
}

int main(){
    int n, e;
    cout << "Enter number of vertices: ";
    cin >> n;
    cout << "Enter number of edges: ";
    cin >> e;

    vector<vector<int>> G(n+1);
    cout << "Enter edges (u v):" << endl;
    for (int i = 0; i < e; i++) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    if (hasCycleBFS(n, G)) {
        cout << "Cycle detected!" << endl;
    } else {
        cout << "No cycle detected." << endl;
    }


}

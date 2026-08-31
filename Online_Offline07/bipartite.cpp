#include<bits/stdc++.h>
using namespace std;

bool isBipartiteBFS(int start, const vector<vector<int>> &G, vector<int> &color1){
    queue<int> q;
    color1[start] = 0;
    q.push(start);

    while(!q.empty()){
        int v = q.front();
        q.pop();

        for(int w : G[v]){
            if(color1[w] == -1){
                color1[w] = 1 - color1[v];
                q.push(w);
            }
            else if( color1[w] == color1[v]){
                return false;
            }
        }
    }
    return true;
}

bool isBipartiteR(int start, int c, const vector<vector<int>> &G, vector<int> &color3){
    color3[start] = 0;

    for(int w : G[start]){
        if(color3[w] == -1){
            if(!isBipartiteR(w,1-c,G,color3)){
                return false;
            }   else if(color3[w] == color3[start]){
                return false;
            }
        }
    }
    return true;
}

bool isBipartiteDFS(int start, const vector<vector<int>> &G, vector<int> &color2){
    stack<int> s;
    color2[start = 0];
    s.push(start);

    while(!s.empty()){
        int v = s.top();
        s.pop();
        for(int w : G[v]){
            if(color2[w] == -1){
                color2[w] = 1 - color2[v];
            }else if(color2[w] == color2[v]){
                return false;
            }
        }
    }
    return true;
}
int main(){
    int n, e;
    cout << "Enter number of vertices: ";
    cin >> n;
    cout << "Enter number of edges: ";
    cin >> e;

    vector<vector<int>> G(n + 1);
    vector<int> color1(n+1,-1);
    vector<int> color2(n+1,-1);
    vector<int> color3(n+1,-1);

    cout << "Enter edges (u v):" << endl;
    for (int i = 0; i < e; i++) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    cout << "\nResults:\n";
    if(isBipartiteBFS(n,G,color1) == true){
        cout << "Bi" <<endl;
    }else{
        cout << " Not Bi " << endl;
    }

    if(isBipartiteDFS(n,G,color2) == true){
        cout << "Bi" <<endl;
    }else{
        cout << " Not Bi " << endl;
    }

    if(isBipartiteR(n,0,G,color3) == true){
        cout << "Bi" <<endl;
    }else{
        cout << " Not Bi " << endl;
    }



}

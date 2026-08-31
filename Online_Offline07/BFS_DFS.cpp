#include <bits/stdc++.h>
using namespace std;

vector<int> G[100];
vector<bool> mark(100,false);

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
                for(int i = 0; i < G[v].size(); i++){
                    int w = G[v][i];
                    if(!marked[w]){
                        q.push(w);
                    }
                }
        }
    }
}

void DFSR(int v){
    cout << v << " ";
    mark[v] = true;
    for(int i = 0; i < G[v].size(); i++){
        int w = G[v][i];
        if(!mark[w]){
            DFSR(w);
        }
    }
}

void DFSI(int v){
    vector<bool> marked(100,false);
    stack<int> s;
    s.push(v);

    while(!s.empty()){
        v = s.top();
        s.pop();
        if(!marked[v]){
            cout << v << " ";
            marked[v] = true;
            for(int i = G[v].size()-1; i >= 0; i--){
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

    for(int i = 0; i < e; i++){
        int a,b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    int start;
    cin >> start;

    DFSI(start);
    cout << endl;
    DFSR(start);
    cout << endl;
    BFS(start);
    cout << endl;
}

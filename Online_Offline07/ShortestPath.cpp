#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

void findShortestPath(int src, int dest, int n, const vector<vector<int>>& G) {
    vector<int> dist(n + 1, -1);
    vector<int> parent(n + 1, -1);
    queue<int> q;

    // Initialize source
    dist[src] = 0;
    q.push(src);

    bool reached = false;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        if (u == dest) {
            reached = true;
            break;
        }

        for (int v : G[u]) {
            if (dist[v] == -1) { // Unvisited
                dist[v] = dist[u] + 1;
                parent[v] = u;
                q.push(v);
            }
        }
    }

    if (!reached) {
        cout << "No path exists between " << src << " and " << dest << ".\n";
        return;
    }

    // Backtrack from dest to src to reconstruct the path
    vector<int> path;
    for (int curr = dest; curr != -1; curr = parent[curr]) {
        path.push_back(curr);
    }
    reverse(path.begin(), path.end());

    // Print results
    cout << "Shortest distance: " << dist[dest] << "\n";
    cout << "Path: ";
    for (size_t i = 0; i < path.size(); i++) {
        cout << path[i] << (i + 1 < path.size() ? " -> " : "");
    }
    cout << "\n";
}

int main() {
    int n, e;
    cout << "Enter number of vertices: ";
    cin >> n;
    cout << "Enter number of edges: ";
    cin >> e;

    vector<vector<int>> G(n + 1);

    cout << "Enter edges (u v):" << endl;
    for (int i = 0; i < e; i++) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u); // Remove this line if the graph is directed
    }

    int src, dest;
    cout << "Enter source and destination: ";
    cin >> src >> dest;

    findShortestPath(src, dest, n, G);

    return 0;
}

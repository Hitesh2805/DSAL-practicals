#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Graph {
    int v;
    vector<vector<int>> adj;

    Graph(int vertices) : v(vertices), adj(vertices) {}

    void addEdge(int u, int w) {
        adj[u].push_back(w);
        adj[w].push_back(u);
    }

    void BFS(int start) {
        vector<bool> visited(v, false);
        queue<int> q;
        visited[start] = true;
        q.push(start);

        while (!q.empty()) {
            int node = q.front(); q.pop();
            cout << node << " ";
            for (int neigh : adj[node])
                if (!visited[neigh]) {
                    visited[neigh] = true;
                    q.push(neigh);
                }
        }
    }
};

int main() {
    int v, e, u, w;
    cin >> v >> e;
    Graph g(v);
    while (e--) {
        cin >> u >> w;
        g.addEdge(u, w);
    }
    g.BFS(0);
    return 0;
}

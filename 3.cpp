#include <iostream>
using namespace std;

int adj[10][10], count[10], visited[10], queue[10], front = 0, rear = 0, n;

void addEdge(int u, int v) {
    adj[u][count[u]++] = v;
    adj[v][count[v]++] = u; // for undirected graph
}

void bfs(int start) {
    queue[rear++] = start;
    visited[start] = 1;
    while (front < rear) {
        int node = queue[front++];
        cout << node << " ";
        for (int i = 0; i < count[node]; i++) {
            int next = adj[node][i];
            if (!visited[next]) {
                queue[rear++] = next;
                visited[next] = 1;
            }
        }
    }
}

int main() {
    int edges, u, v;
    cout << "Enter nodes and edges: ";
    cin >> n >> edges;
    for (int i = 0; i < edges; i++) {
        cin >> u >> v;
        addEdge(u, v);
    }
    cout << "BFS traversal: ";
    bfs(0); // start from node 0
    return 0;
}
// OUTPUT
Enter nodes and edges: 4 4
0 1
0 2
1 3
2 3
BFS traversal: 0 1 2 3

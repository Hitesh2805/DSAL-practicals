#include <iostream>
using namespace std;

int graph[10][10], visited[10], n;

void dfs(int node) {
    visited[node] = 1;
    cout << node << " ";
    for (int i = 0; i < n; i++)
        if (graph[node][i] && !visited[i])
            dfs(i);
}

int main() {
    int edges, u, v;
    cout << "Enter nodes and edges: ";
    cin >> n >> edges;
    for (int i = 0; i < edges; i++) {
        cin >> u >> v;
        graph[u][v] = graph[v][u] = 1; 
    cout << "DFS traversal: ";
    dfs(0); 
    return 0;
}


/// OUTPUT 
Enter nodes and edges: 4 4
0 1
0 2
1 3
2 3
DFS traversal: 0 1 3 2 

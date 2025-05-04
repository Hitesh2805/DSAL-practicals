#include <iostream>
using namespace std;

int graph[10][10], visited[10], stack[10], top = -1, n;

void dfs(int start) {
    stack[++top] = start;
    while (top != -1) {
        int node = stack[top--];
        if (!visited[node]) {
            cout << node << " ";
            visited[node] = 1;
            for (int i = n - 1; i >= 0; i--)
                if (graph[node][i] && !visited[i])
                    stack[++top] = i;
        }
    }
}

int main() {
    int edges, u, v;
    cout << "Enter nodes and edges: ";
    cin >> n >> edges;
    for (int i = 0; i < edges; i++) {
        cin >> u >> v;
        graph[u][v] = graph[v][u] = 1;
    }
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

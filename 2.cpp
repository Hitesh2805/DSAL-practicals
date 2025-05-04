#include <iostream>
#include <stack>
using namespace std;

#define MAX 10

int G[MAX][MAX], visited[MAX], n;

void DFS_non_recursive(int start) {
    stack<int> s;
    s.push(start);

    while (!s.empty()) {
        int current = s.top();
        s.pop();

        if (!visited[current]) {
            cout << current << " ";
            visited[current] = 1;
        }

        // Push all adjacent unvisited vertices (higher to lower for consistent order)
        for (int i = n - 1; i >= 0; i--) {
            if (G[current][i] == 1 && !visited[i]) {
                s.push(i);
            }
        }
    }
}

int main() {
    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter the adjacency matrix:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> G[i][j];
        }
    }

    // Initialize visited array
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }

    cout << "DFS traversal starting from vertex 0:" << endl;
    DFS_non_recursive(0);

    return 0;
}

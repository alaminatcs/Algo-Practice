#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+7; vector<int> adj[N];
bool visited[N]; int level[N];

void bfs(int parent) {
    queue<int> q; q.push(parent);
    visited[parent] = true; level[parent] = 0;
    while (!q.empty()) {
        parent = q.front(); q.pop();
        for (auto child : adj[parent]) {
            if (visited[child] == false) {
                q.push(child); visited[child] = true;
                level[child] = level[parent] + 1;
            }
        }
    }
}

int main() {
    int vertices, edges; cin >> vertices >> edges;
    for (int i = 1; i <= edges; i++) {
        int parent, child; cin >> parent >> child;
        adj[parent].push_back(child); adj[child].push_back(parent);
    }
    int node; cin >> node; bfs(1);
    cout << "Level of " << node << " = " << level[node] << "\n";
    return 0;
}
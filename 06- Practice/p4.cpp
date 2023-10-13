#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+7; vector<int> adj[N];
bool visited[N]; int depth[N] = {0};

void dfs(int parent) {
    visited[parent] = true;
    for (auto child : adj[parent]) {
        if (visited[child] == false) {
            depth[child] =  max(depth[child], depth[parent]+1);
            visited[child] = true; dfs(child);
        }
    }
}
int main() {
    int vertices, edges; cin >> vertices >> edges;
    for (int i = 1; i <= edges; i++) {
        int parent, child; cin >> parent >> child;
        adj[parent].push_back(child);
        adj[child].push_back(parent);
    }
    dfs(1);
    int node; cin >> node;
    cout << "Depth of " << node << " = " << depth[node] << "\n";
    return 0;
}
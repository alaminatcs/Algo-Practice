#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+7; vector<int> adj[N];
bool visited[N]; int height[N] = {0};

void dfs(int parent) {
    visited[parent] = true;
    for (auto child : adj[parent]) {
        if (visited[child] == false) {
            dfs(child);
            height[parent] = max(height[child]+1, height[parent]);
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
    cout << "height of " << node << " = " << height[node];
    return 0;
}
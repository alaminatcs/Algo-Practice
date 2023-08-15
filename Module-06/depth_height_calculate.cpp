#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+7; vector<int> adj[N];
bool visited[N]; int depth[N], height[N];

void dfs(int parent) {
    visited[parent] = true;
    for (auto child : adj[parent]) {
        if (visited[child] == false) {
            depth[child] = depth[parent]+1; dfs(child);
            //if (height[child]+1 > height[parent]) height[parent] = height[child]+1;   //short in below
            height[parent] = max(height[parent], height[child]+1);
        } 
    }
}

int main() {
    int vertices, edges; cin >> vertices >> edges;
    for (int i = 1; i <= edges; i++) {
        int parent, child; cin >> parent >> child;
        adj[parent].push_back(child); adj[child].push_back(parent);
    }
    dfs(1);
    for (int i = 1; i <= vertices; i++) {
        cout << "Depth of vertice - " << i << ": " << depth[i] << "\n";
    }
    cout << "\n********************\n";
    for (int i = 1; i <= vertices; i++) {
        cout << "Height of vertice - " << i << ": " << height[i] << "\n";
    }
    return 0;
}
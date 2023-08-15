#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+7; vector<int> adj[N];
bool visited[N];
void dfs(int parent) {
    visited[parent] = true;
    for (auto child : adj[parent]) {
        if (visited[child] == false) dfs(child);
    }
    cout << parent << " ";
}
int main() {
    int vertices, edges; cin >> vertices >> edges;
    for (int i = 1; i <= edges; i++) {
        int parent, child; cin >> parent >> child;
        adj[parent].push_back(child); adj[child].push_back(parent);
    }
    dfs(1);
    return 0;
}
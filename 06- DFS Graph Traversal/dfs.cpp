#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+7;
vector<int> adj[N]; bool visited[N];

void dfs(int u) {
    // action into new parent node
    visited[u] = true; cout << u << " ";
    for (auto v : adj[u]) {
        // action into new child node
        if (visited[v] == false) dfs(v);
        // action after exiting child node
    }
    // action after exiting parent node
}

int main() {
    int n, m; cin >> n >> m;
    for (int i = 1; i <= m ; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v); adj[v].push_back(u);
    }
    cout << "visited order: "; dfs(1);
    cout << "\n\n";
    for (int i = 1; i <= n; i++) {
        cout << "Node " << i << ": status- " << visited[i] << "\n";
    }
    // for (int i = 1; i <= m; i++) {
    //     cout << i << ": ";
    //     for (auto var : adj[i]) {
    //         cout << var << " ";
    //     } cout << "\n";
    // }
    return 0;
}
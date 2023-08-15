#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+7; vector<int> adj[N];

void bfs (int parent, int destination) {
    bool visited[N] = {false}; int level[N] = {0};
    queue<int> q; q.push(parent); int rem = 0;
    visited[parent] = true; level[parent] = 0;
    while (!q.empty()) {
        parent = q.front(); q.pop();
        if (parent == destination) rem = 1;
        for (auto child : adj[parent]) {
            if (visited[child] == false) {
                q.push(child); visited[child] = true;
                level[child] = level[parent] + 1;
            }
        }
    }
    if (rem) cout << level[destination] << "\n";
    else cout << "-1\n";
}

int main() {
    int vertices, edges; cin >> vertices >> edges;
    for (int i = 1; i <= edges; i++) {
        int parent, child; cin >> parent >> child;
        adj[parent].push_back(child); adj[child].push_back(parent);
    }

    int q; cin >> q;
    for (int i = 1; i <= q; i++) {
        int s, d; cin >> s >> d; bfs(s, d);
    }
    return 0;
}
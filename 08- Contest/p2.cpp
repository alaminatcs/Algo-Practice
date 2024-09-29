#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+7; vector<int> adj[N];
bool visited[N] = {false}; int level[N];

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
    bfs(0); int l; cin >> l;
    if (l == 0) cout << "0\n";
    else {
        vector<int> res;
        for (int i = 0; i < N; i++) {
            if (level[i] == l) res.push_back(i);
        }
        if (res.size()) {
            for (auto var : res) cout << var << " ";
        }
        else cout << "-1\n";
    }
    return 0;
}
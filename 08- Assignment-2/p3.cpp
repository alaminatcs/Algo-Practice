#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+7; vector<int> adj[N];
bool visited[N]; int level[N] = {0};
vector<int> track[N];

void bfs(int parent) {
    queue<int> q; q.push(parent);
    visited[parent] = true; track[level[parent]].push_back(parent);
    while (!q.empty()) {
        parent = q.front(); q.pop();
        for (auto child : adj[parent]) {
            if (visited[child] == false) {
                q.push(child); visited[child] = true;
                level[child] = level[parent] + 1;
                track[level[child]].push_back(child);
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
    int k; cin >> k; bfs(k); cout << track[1].size() << "\n";
    return 0;
}
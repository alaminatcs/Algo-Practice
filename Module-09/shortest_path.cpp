#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+7; vector<int> adj[N];
bool visited[N]; int level[N], parent_track[N];

void bfs (int parent) {
    queue<int> q; q.push(parent);
    visited[parent] = true; level[parent] = 0;
    parent_track[parent] = -1;

    while (!q.empty()) {
        parent = q.front(); q.pop();
        for (auto child : adj[parent]) {
            if (visited[child] == false) {
                q.push(child); visited[child] = true;
                level[child] = level[parent] + 1;
                parent_track[child] = parent;
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
    int source, destination; cin >> source >> destination; bfs (source);

    cout << "Distance from source to destination: " << level[destination] << "\n";
    cout << "Distance path: "; vector<int> path;
    while (destination != -1) {
        path.push_back(destination);
        destination = parent_track[destination];
    }
    reverse(path.begin(), path.end());
    for (auto var : path) cout << var << " ";
    return 0;
}
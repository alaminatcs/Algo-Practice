#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+7; vector<int> adj[N];
bool visited[N]; int n = 0;

void dfs(int parent) {
    visited[parent] = true;
    for (auto child : adj[parent]) {
        if (visited[child] == false) {
            n++; dfs(child);
        }
    }
}
int main() {
    int vertices, edges; cin >> vertices >> edges;
    for (int i = 1; i <= edges; i++) {
        int parent, child; cin >> parent >> child;
        adj[parent].push_back(child);
    }
    int k, cnt = 0; cin >> k; dfs(k); cout << n << "\n";
    return 0;
}
/*
Problem Name: Building Roads.
Problem Link: https://cses.fi/problemset/task/1666
*/
#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+3; vector<int> adj[N];
vector<bool> visited(N, false);

void dfs(int p) {
    visited[p] = true;
    for (auto c : adj[p]) {
        if (!visited[c]) dfs(c);
    }
}

int main() {
    int n, m; cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b); adj[b].push_back(a);
    }
    vector<int> leader;
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            leader.push_back(i); dfs(i);
        }
    }
    cout << leader.size()-1 << "\n";
    for (unsigned int i = 1; i < leader.size(); i++) {
        cout << leader[i-1] << " " << leader[i] << "\n";
    }
    return 0;
}
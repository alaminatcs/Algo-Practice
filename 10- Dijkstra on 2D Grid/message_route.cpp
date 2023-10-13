/*
Problem Name: Message Route.
Problem Link: https://cses.fi/problemset/task/1667
*/
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+3; vector<int> adj[N];
vector<bool> visited(N, false);
int level[N], parent[N];

void bfs(int p) {
    queue<int> q; q.push(p); visited[p] = true;
    level[p] = 0; parent[p] = -1;
    while (!q.empty()) {
        p = q.front(); q.pop();
        for (auto c : adj[p]) {
            if (!visited[c]) {
                q.push(c); visited[c] = true;
                level[c] = level[p]+1; parent[c] = p;
            }
        }
    }
}

int main() {
    int n, m; cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int p, c; cin >> p >> c;
        adj[p].push_back(c); adj[c].push_back(p);
    }
    bfs(1);
    if (visited[n]) {
        cout << level[n]+1 << "\n";
        stack<int> s; int path = n;
        while (path != -1) {
            s.push(path); path = parent[path];
        }
        while (!s.empty()) {
            cout << s.top() << " "; s.pop();
        }
    }
    else cout << "IMPOSSIBLE\n";
    return 0;
}
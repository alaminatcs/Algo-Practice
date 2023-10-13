/*
Problem Name: adjacency matrix input.
Problem Link: 
*/
#include <bits/stdc++.h>
using namespace std;

const int N = 1e3+5;
vector<pair<int, int> > adjlist[N];

int main() {
    int n, m; cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v, w; cin >> u >> v >> w;    // w for weighted graph
        adjlist[u].push_back({v, w});
        adjlist[v].push_back({u, w});           // it'll be for undirected(u->v, v->u) graph
    }
    cout << "number: (connected with, weight)\n";
    for (int i = 1; i <= n; i++) {
        cout << i << ": ";
        for (int j = 0; j < adjlist[i].size(); j++) {
            cout << "(" << adjlist[i][j].first << ", " << adjlist[i][j].second << ") ";
        }
        cout << "\n";
    }
    return 0;
}
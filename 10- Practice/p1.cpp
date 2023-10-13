/*
Problem Name: You will be given an undirected weighted graph. At first you will be
given N, the number of nodes then you will be given M, the number of edges. The
value of nodes are from 1 to N. Next M lines will contain A, B and W which
means there is an edge from A to B where the cost is W. There will be no negative
weight in the graph.
Also, you will be given a source and a destination. You need to tell the shortest
distance between source and destination 
*/
#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
const int N = 1e3+3; vector<pii> adj[N];
bool visited[N]; int parent[N];
vector<int> dist(N, 1e5+3);

void bfs(int s) {
    priority_queue<pii, vector<pii>, greater<>> pq;
    parent[s] = -1; dist[s] = 0; pq.push({dist[s], s});
    while (!pq.empty()) {
        pii f = pq.top(); pq.pop();
        visited[f.second] = true;
        for (auto ch : adj[f.second]) {
            if (!visited[ch.second]) {
                int cur_d = dist[ch.second];
                int par_d = dist[f.second];
                if (cur_d > par_d + ch.first) {
                    parent[ch.second] = f.second;
                    dist[ch.second] = par_d + ch.first;
                    pq.push({dist[ch.second], ch.second});
                }
            }
        }
    }
}

void destination_path(int d) {
    if (d == -1) return;
    destination_path(parent[d]); cout << d << " ";
}

int main() {
    int n, m; cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int p, c, w; cin >> p >> c >> w;
        adj[p].push_back({w, c}); adj[c].push_back({w, p});
    }
    int s, d; cin >> s >> d;
    bfs(s); cout << dist[d] << "\n";
    //destination_path(d);
    return 0;
}
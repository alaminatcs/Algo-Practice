/*
Problem Name:  You will be given a directed weighted graph. At first you will be given
N, the number of nodes then you will be given M, the number of edges. The value
of nodes are from 1 to N. Next M lines will contain A, B and W which means there
is an edge from A to B where the cost is W. There will be no negative weight in the
graph.
Also, you will be given a source and a destination. You need to tell the shortest
distance between source and destination
*/
#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
const int N = 1e5+3; vector<pii> adj[N];
bool visited[N]; vector<int> dist(N, 1e7+9);

void bfs(int s) {
    priority_queue<pii, vector<pii>, greater<>> pq;
    dist[s] = 0; pq.push({0, s});
    while (!pq.empty()) {
        pii f = pq.top(); pq.pop();
        visited[f.second] = true;
        for (auto ch : adj[f.second]) {
            if(!visited[ch.second]) {
                int cur = dist[ch.second];
                int fut = dist[f.second] + ch.first;
                if (cur > fut) {
                    dist[ch.second] = fut;
                    pq.push({dist[ch.second], ch.second});
                }
            }
        }
    }
}

int main() {
    int n, m; cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int p, c, w; cin >> p >> c >> w;
        adj[p].push_back({w, c});
    }
    int s, d; cin >> s >> d; bfs(s);
    if(dist[d] != 1e7+9) cout << dist[d];
    else cout << "Not possible";
    return 0;
}
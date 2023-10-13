/*
Problem Name: Dijkstra Implementation.
*/
#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
const int N = 1e5+3; vector<pii> adj[N];
vector<int> cost(N, 1e5+3);
vector<bool> visited(N, false);

void dijkstra(int p) {
    priority_queue<pii, vector<pii>, greater<pii> > pq;
    cost[p] = 0; pq.push({cost[p], p});
    while (!pq.empty()) {
        p = pq.top().second; pq.pop();
        visited[p] = true;
        for (auto c : adj[p]) {
            if (!visited[c.second]) {
                int past_w = cost[c.second];
                int cur_w = cost[p] + c.first;
                if (past_w > cur_w) {
                    cost[c.second] = cur_w;
                    pq.push({cost[c.second], c.second});
                }
            }
        }
    }
}

int main() {
    int v, e; cin >> v >> e;
    for (int i = 1; i <= e; i++) {
        int p, c, w; cin >> p >> c >> w;
        adj[p].push_back({w, c}); adj[c].push_back({w, p});
    }
    int s, d; cin >> s >> d;
    dijkstra(s);
    cout << s << " to " << d << " min cost: " << cost[d];
    return 0;
}
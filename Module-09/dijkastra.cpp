#include <bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
const int N = 1e5 + 3;

vector<bool> visited(N);
vector<pair<int, int>> adj[N];
vector<int> dist(N, INFINITY);

void dijkstra(int source) {
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, source});

}

int main() {
    int vertices, edges; cin >> vertices >> edges;
    for (int i = 1; i < edges; i++) {
        int parent, child, dis; cin >> parent >> child >> dis;
        adj[parent].push_back({child, dis});
        adj[child].push_back({parent, dis});
    }
    dijkstra(1);
    return 0;
}
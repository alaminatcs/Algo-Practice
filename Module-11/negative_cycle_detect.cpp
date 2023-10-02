/*
Problem Name: Negative cycle detect using bellman ford algorithm.
*/
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+3;
typedef pair<int, int> pii;
vector<pair<pii, int>> adj;
vector<int> dist(N, N);
int cycle_point, parent[N];
bool rem = false;

void bellman_ford(int s, int n) {
    dist[s] = 0;
    for (int i = 1; i <= n; i++) {
        for(auto edge : adj) {
            int p = edge.first.first;
            int c = edge.first.second;
            int w = edge.second;
            if(dist[c] > dist[p]+w && dist[p] != N) {
                dist[c] = dist[p] + w; parent[c] = p;
                if (i == n) {
                    rem = true; cycle_point = c;
                }
            }
        }
    }
}

int main() {
    int n, m; cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int p, c, w; cin >> p >> c >> w;
        adj.push_back({{p, c}, w});
    }
    int source; cin >> source;
    bellman_ford(source, n);
    if (rem) {
        cout << "Negative Cycle remains\n";
        vector<int> res; res.push_back(cycle_point);

        int p = parent[cycle_point];
        while (p != cycle_point) {
            res.push_back(p); p = parent[p];
        }
        res.push_back(cycle_point);

        reverse(res.begin(), res.end());
        for (auto v : res) cout << v << " ";
        //for (int i = 1; i <= n; i++) cout << parent[i] << " ";
    }
    else cout << "No Negative Cycle remains\n";
    return 0;
}
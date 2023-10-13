/*
Problem Name: Bellman Ford Algorithm.
*/
#include <bits/stdc++.h>
using namespace std;

const int N = 1e3+5;
typedef pair<int, int> pii;
vector<pii> adj[N]; vector<int> dist(N, N);

void bellman_ford(int source, int n) {
    dist[source] = 0;
    for (int i = 1; i < n; i++) {
        /*                                      //self thought
        bool remainder = true; 
        queue<pii> q; q.push({dist[1], 1});
        while (!q.empty()) {
            pii p = q.front(); q.pop();
            for (auto ch : adj[p.second]) {
                q.push(ch); 
                int cur_d = dist[ch.second];
                int fut_d = dist[p.second] + ch.first;
                if (cur_d>fut_d &&  dist[p.second]!=N) {
                    dist[ch.second] = fut_d; remainder = false;
                }
            }
        }
        if (remainder) break;
        */

        for (int i = 1; i <= n; i++) {          //teacher thought
            for (auto ch : adj[i]) {
                int cur_d = dist[ch.second];
                int fut_d = dist[i] + ch.first;
                
                if(cur_d>fut_d && dist[i]!=N) {
                    dist[ch.second] = fut_d;
                }
            }
        }
    }
}

int main() {
    int n, m; cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int p, c, w; cin >> p >> c >> w;
        adj[p].push_back({w, c});
    }
    int source; cin >> source;
    bellman_ford(source, n);
    for (int i = 1; i <= n; i++) {
        cout << source <<" to " << i << " dist: ";
        if (dist[i] == N) cout << "no way\n";
        else cout << dist[i] << "\n";
    }
    return 0;
}

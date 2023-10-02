#include <bits/stdc++.h>
using namespace std;

const int N = 1e3+5;
typedef pair<int, int> pii;
vector<pii> adj[N]; vector<int> dist(N, N);

void bellman_ford(int source, int n) {
    dist[source] = 0;
    for (int i = 1; i < n; i++) {
        for (int i = 1; i <= n; i++) {
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
    int q; cin >> q;
    while (q--) {
        int d, dw; cin >> d >> dw;
        if (dist[d] <= dw) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}

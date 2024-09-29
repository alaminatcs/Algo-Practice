#include <bits/stdc++.h>
using namespace std;

#define lln long long
const lln N = 1e3+3;
const lln inf = 3e9+9;
typedef pair<lln, lln> pii;
vector<pair<pii, lln>> adj;
vector<lln> dist(N, inf); bool rem = false;

void bellman_ford(lln s, lln n) {
    dist[s] = 0;
    for (lln i = 1; i <= n; i++) {
        for(auto edg : adj) {
            lln p = edg.first.first;
            lln c = edg.first.second, w = edg.second;
            if ((dist[c] > dist[p]+w)  &&  dist[p]!=inf) {
                dist[c] = dist[p] + w;
                if (i==n) rem = true;
            }
        }
    }
}

int main() {
    // Write your code here
    lln n, m; cin >> n >> m;
    for (lln i = 1; i <= m; i++) {
        lln p, c, w; cin >> p >> c >> w;
        adj.push_back({{p, c}, w});
    }
    lln source; cin >> source;
    bellman_ford(source, n);
    lln tc; cin >> tc;
    if (rem) {
        while (tc--) {
            lln sample; cin >> sample;
        }
        cout << "Negative Cycle Detected\n";
    }
    else {
        while (tc--) {
            lln sample; cin >> sample;
            if (dist[sample] == inf) cout << "Not Possible\n";
            else cout << dist[sample] << "\n";
        }
    }
    return 0;
}
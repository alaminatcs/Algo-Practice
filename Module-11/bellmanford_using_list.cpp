/*
Problem Name: Bellman Frod using edge list; 
*/
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+3;
typedef pair<int, int> pii;
vector<pair<pii, int>> adj;
vector<int> dist(N, N);

void bellman_ford(int s, int n) {
    dist[s] = 0;
    for (int i = 1; i < n; i++) {
        bool rem = true;
        for(auto edg : adj) {
            int p = edg.first.first;
            int c = edg.first.second, w = edg.second;
            if (dist[c] > dist[p]+w  &&  dist[p]!=N) {
                dist[c] = dist[p] + w; rem = false;
            }
        }
        if(rem) break;
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
    for (int i = 1; i <= n; i++) {
        cout << source << " to " << i << " dist: ";
        if (dist[i] != N) cout << dist[i] << "\n";
        else cout << "no way\n";
    }
    return 0;
}
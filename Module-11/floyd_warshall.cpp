/*
Problem Name: Floyd Warshall Algorithm.
*/
#include <bits/stdc++.h>
using namespace std;

const int inf = 1e7+9;
int n, m, dist[1000][1000];

void dist_initialize() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if(i != j) dist[i][j] = inf;
        }
    }
}

void floyd_warshall() {
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
            }
        }
    }
}

int main() {
    cin >> n >> m;
    dist_initialize();
    for (int i = 1; i <= m; i++) {
        int p, c, w; cin >> p >> c >> w;
        dist[p][c] = w; //dist[c][p] = w;
    }

    floyd_warshall();
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (dist[i][j] == inf) cout << "X ";
            else cout << dist[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}
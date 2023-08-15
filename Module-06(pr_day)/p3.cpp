#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, m; cin >> n >> m;
    vector<int> adj[n+5];
    for (int i = 1; i <= m; i++) {
        int parent, child; cin >> parent >> child;
        adj[parent].push_back(child);
    }
    int mat[n][n] = {0};
    for (int i = 1; i <= n; i++) {
        for (auto ch : adj[i]) mat[i-1][ch-1] = 1;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) cout << mat[i][j] << " ";
        cout << "\n";
    }
    return 0;
}
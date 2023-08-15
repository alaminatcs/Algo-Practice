#include <bits/stdc++.h>
using namespace std;
int main() {
    int n; cin >> n; int mat[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) cin >> mat[i][j];
    }
    vector<int> adj[n+5];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (mat[i][j]) adj[i+1].push_back(j+1);
        }
    }
    for (int i = 1; i <=n; i++) {
        cout << "List " << i << " : ";
        for (auto child : adj[i]) cout << child << " ";
        cout << "\n";
    }
    return 0;
}
/*
Problem Name: Counting Rooms.
Problem Link: https://cses.fi/problemset/task/1192
*/
#include <bits/stdc++.h>
using namespace std;

int n, m; vector<string> adj;
bool visited[1005][1005] = {false};

void dfs(int i, int j) {
    if (i>=0 && i<n  &&  j>=0 && j<m) {
        if (adj[i][j] == '#') return;
        else {
            if (visited[i][j]) return;
            else visited[i][j] = true; 
        }
    }
    else return;
    dfs(i, j+1); dfs(i, j-1);
    dfs(i+1, j); dfs(i-1, j);
}
 
int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string s; cin >> s; adj.push_back(s);
    }
    int comp = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (adj[i][j] == 'A') {
                dfs(i, j); break;
            }
        }
    }
    cout << comp << "\n";
    return 0;
}
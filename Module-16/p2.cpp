#include <bits/stdc++.h>
using namespace std;

int n, m; vector<string> adj;
bool visited[1005][1005] = {false};

void dfs(int i, int j) {
    if (i>=0 && i<n  &&  j>=0 && j<m) {
        if (adj[i][j] == '-') return;
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
    int si, sj, di, dj; cin >> si >> sj >> di >> dj;
    dfs(si, sj);
    if (visited[di][dj]) cout << "YES\n";
    else cout << "NO\n";
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int n, m, cnt; vector<string> adj;
bool visited[1005][1005] = {false};

void dfs(int i, int j) {
    if (i>=0 && i<n  &&  j>=0 && j<m) {
        if (adj[i][j]=='.' && !visited[i][j]) {
            visited[i][j] = true; cnt++;
        }
        else return;
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
    vector<int> res;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (adj[i][j]=='.' && !visited[i][j]) {
                cnt = 0; dfs(i, j); res.push_back(cnt);
            }
        }
    }
    if (res.size()) {
        sort(res.begin(), res.end());
        cout << res[0] << "\n";
    }
    else cout << "-1\n";
    return 0;
}
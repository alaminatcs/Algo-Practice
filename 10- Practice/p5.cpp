/*
Problem Name: 
Problem Link: 
*/
#include <bits/stdc++.h>
using namespace std;

int n, m, si = -1, sj = -1, di = -1, dj = -1;
vector<string> adj; bool visited[1000][100];
int level[1000][1000]; pair<int, int> parent[1000][1000];
vector<pair<int, int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

bool isValid(int i, int j) {
    return i>=0 && i<n && j>=0 && j<m;
}

void bfs(int si, int sj) {
    queue<pair<int, int>> q; q.push({si, sj});
    level[si][sj] = 0; parent[si][sj] = {-1, -1};

    while (!q.empty()) {
        pair<int, int> f = q.front(); q.pop();
        visited[f.first][f.second] = true;
        for (auto d : dir) {
            int i = f.first + d.first, j = f.second + d.second;
            if (isValid(i, j) && !visited[i][j] && adj[i][j]!='x') {
                q.push({i, j}); parent[i][j] = {f.first, f.second};
                level[i][j] = level[f.first][f.second] + 1;
            }
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string s; cin >> s; adj.push_back(s);
        for (int j = 0; j < m; j++) {
            if (s[j] == 's') {
                si = i; sj = j;
            }
            else if (s[j] == 'e') {
                di = i; dj = j;
            }
        }
    }
    if (si != -1 && di != -1) {
        bfs(si, sj);
        if (!level[di][dj]) cout << "-1\n";
        else {
            cout << level[di][dj] << "\n";
            vector<char> res;
            int i = parent[di][dj].first;
            int j = parent[di][dj].second;
            while (true) {
                if (di == -1) break;

                if (i == di && j == dj-1) res.push_back('R');
                else if (i == di && j == dj+1) res.push_back('L');
                else if (i == di-1 && j == dj) res.push_back('D');
                else if (i == di+1 && j == dj) res.push_back('U');
                
                di = i; dj = j; i = parent[di][dj].first; 
                j = parent[di][dj].second;
            }
            reverse(res.begin(), res.end());
            for (auto ch : res) cout << ch;
        }
    }
    else cout << "-1\n";
    return 0;
}
/*
Problem Name: Labyrinth in building room map.
Problem Link: https://cses.fi/problemset/task/1193/
*/
#include <bits/stdc++.h>
using namespace std;

const int N = 1e3+5;
typedef pair<int, int> pii;
int n, m; vector<string> adj;
bool visited[N][N]; pii parent[N][N]; int level[N][N] = {0};
vector<pii> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

bool isValid(int i, int j) {
    return i>=0 && i<n && j>=0 && j<m;
}

void bfs(int si, int sj) {
    queue<pii> q; q.push({si, sj});
    visited[si][sj] = true; level[si][sj] = 0;
    parent[si][sj] = {-1, -1};
    while (!q.empty()) {
        pii f = q.front(); q.pop();
        for (auto d : dir) {
            int i = f.first + d.first;
            int j = f.second + d.second;
            if (isValid(i, j) && !visited[i][j] && adj[i][j]!='#') {
                q.push({i, j}); visited[i][j] = true;
                parent[i][j] = {f.first, f.second};
                level[i][j] = level[f.first][f.second] + 1;
            }
        }
    }
}

int main() {
    int si, sj, di, dj; cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string str; cin >> str;
        adj.push_back(str);
        for (int j = 0; j < str.size(); j++) {
            if (str[j] == 'A') {
                si = i; sj = j;
            }
            else if (str[j] == 'B') {
                di = i; dj = j;
            }
        }
    }
    bfs(si, sj);

    if (level[di][dj] == 0) cout << "NO\n";
    else {
        cout << "YES\n" << level[di][dj] << "\n";
        vector<char> res; pii d = parent[di][dj];
        int i = d.first, j = d.second, pi = di, pj = dj;
        while (adj[pi][pj] != 'A') {
            if (pi==i && pj==j+1) res.push_back('R');
            else if (pi==i && pj==j-1) res.push_back('L');
            else if (pi==i+1 && pj==j) res.push_back('D');
            else if (pi==i-1 && pj==j) res.push_back('U');

            pi = i; pj = j; d = parent[i][j];
            i = d.first; j = d.second;
        }
        reverse(res.begin(), res.end());
        for (auto ch : res) cout << ch;
    }
    return 0;
}
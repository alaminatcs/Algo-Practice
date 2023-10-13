/*
Problem Name: You are given a 2D grid which will contain only the characters ‘s’, ‘.’,
‘x’ and ‘e’. The size of the grid is N*M squares, where ‘s’ means where you should
start, ‘.’ means there is a path, ‘x’ means there is no path and ‘e’ means where you
should stop. You can walk left, right, up, and down through the cell of squares. You
need to tell the minimum number of steps you need to go from ‘S’ to ‘E’. There
will be exactly one ‘s’ and one ‘e’. If there is no path, print -1
*/
#include <bits/stdc++.h>
using namespace std;

int n, m, si = -1, sj = -1, di = -1, dj = -1;
vector<string> adj; bool visited[1000][1000];
int level[1000][1000] = {0};
vector<pair<int, int>> direc = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

bool isValid(int i, int j) {
    return i>=0 && i<n && j>=0 && j<m;
}

void bfs(int si, int sj) {
    queue<pair<int, int> > q; q.push({si, sj}); 
    level[si][sj] = 0;

    while (!q.empty()) {
        pair<int, int> f = q.front(); q.pop();
        visited[f.first][f.second] = true;

        for (auto d : direc) {
            int i = f.first + d.first, j = f.second + d.second;
            if (isValid(i, j) && !visited[i][j] && adj[i][j]!='x') {
                q.push({i, j}); level[i][j] = level[f.first][f.second] + 1;
            }
        }
    }
    if (!level[di][dj]) cout << "-1\n";
    else cout << level[di][dj] << "\n";
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string st; cin >> st; adj.push_back(st);
        for (int j = 0; j < m; j++) {
            if (st[j] == 's') {
                si = i; sj = j;
            }
            else if (st[j] == 'e') {
                di = i; dj = j;
            }
        }
    }
    if (si != -1 && dj != -1) bfs(si, sj);
    else cout << "-1\n";
    return 0;
}
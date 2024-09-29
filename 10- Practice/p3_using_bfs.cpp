/*
Problem Name: You are given a 2D grid which will contain only the characters ‘s’, ‘.’,
‘x’ and ‘e’. The size of the grid is N*M squares, where ‘s’ means where you should
start, ‘.’ means there is a path, ‘x’ means there is no path and ‘e’ means where you
should stop. You can walk left, right, up, and down through the cell of squares. You
need to say “YES” if you can go from ‘S’ to ‘E’. Otherwise print “NO”. There
will be exactly one ‘s’ and one ‘e’. If there is no path, print -1.

Note: Try to solve this using both BFS and DFS as you don’t need the shortest
distance. 
*/
#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
const int N = 1e3+5; vector<string> adj;
int n, m, si = -1, sj = -1, di = -1, dj = -1;
bool visited[N][N];

vector<pii> direc = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};

bool isValid(int i, int j) {
    return i>=0 && i<n && j>=0 && j<m;
}

bool bfs(int i, int j) {
    queue<pii> q; q.push({i, j});
    visited[i][j] = true; bool rem = false;
    while (!q.empty()) {
        pii f = q.front(); q.pop();
        for (auto d : direc) {
            int ni = d.first + f.first;
            int nj = d.second + f.second;
            if (isValid(ni, nj) && !visited[ni][nj]) {
                if (adj[ni][nj] != '#') {
                    if (adj[ni][nj] == 'B') return true;
                    visited[ni][nj] = true; q.push({ni, nj});
                }
            }
        }
    }
    return rem;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string s; cin >> s; adj.push_back(s);
        for (int j = 0; j < m; j++) {
            if (s[j] == 'A') {
                si = i; sj = j;
            }
            else if (s[j] == 'B') {
                di = i; dj = j;
            }
        }
    }

    bool res = false;
    if (si != -1 && di != -1) {
        res = bfs(si, sj);
        //dfs(si, sj); if(rem) res = true;
    }
    if (res) cout << "YES\n";
    else cout << "NO\n";
    return 0;
}
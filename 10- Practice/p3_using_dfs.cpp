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
bool visited[N][N]; bool res = false;
int n, m, si = -1, sj = -1, di = -1, dj = -1;
vector<pii> direc = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

bool isValid(int i, int j) {
    return i>=0 && i<n && j>=0 && j<m;
}

bool dfs(int i, int j) {
    if (isValid(i, j) && !visited[i][j] && adj[i][j]!='x') {
        visited[i][j] = true; if(res) return res;
        if (adj[i][j] == 'e') return res | true;
        for(auto d : direc) {
            int ni = i + d.first, nj = j + d.second; 
            res |= dfs(ni, nj);
        }
    }
    return res;
}

int main() {
    cin >> n >> m;
    for (unsigned int i = 0; i < n; i++) {
        string s; cin >> s; adj.push_back(s);
        for (unsigned int j = 0; j < m; j++) {
            if (s[j] == 's') {
                si = i; sj = j;
            }
            else if (s[j] == 'e') {
                di = i; dj = j;
            }
        }
    }
    if (si != -1 && di != -1) {
        res = dfs(si, sj);
        if (res) cout << "YES\n";
        else cout << "NO\n";
    }
    else cout << "NO\n";
    return 0;
}
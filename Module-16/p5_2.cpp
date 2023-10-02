/*
Problem Name: Knight move.
Problem Link: https://www.spoj.com/problems/NAKANJ/
*/
#include <bits/stdc++.h>
using namespace std;
int n, m, si, sj, di, dj;
vector<pair<int, int> > direc = {{2, 1}, {2, -1},
                                {-2, 1}, {-2, -1},
                                {1, 2}, {1, -2},
                                {-1, 2}, {-1, -2}};

bool isValid(int i, int j) {
    return i>=0 && i<n && j>=0 && j<m;
}

void bfs(int si, int sj, int di, int dj) {
    bool visited[n][m] = {false}; int level[n][m];
    queue<pair<int, int> > q; q.push({si, sj});
    level[si][sj] = 0; visited[si][sj] = true;
    while (!q.empty()) {
        pair<int, int> f = q.front(); q.pop();
        int i = f.first, j = f.second;
        for (auto d : direc) {
            int ni = i + d.first,  nj = j + d.second;
            if (isValid(ni, nj) && !visited[ni][nj]) {
                q.push({ni, nj}); visited[ni][nj] = true;
                level[ni][nj] = level[i][j] + 1;
            }
        }
    }
    cout << level[di][dj] << "\n";
}

int main() {
    int test; cin >> test;
    while (test--) {
        cin >> n >> m; cin >> si >> sj >> di >> dj;
        bfs(si, sj, di, dj);
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> dir = {{1, 1}, {1, -1}, {-1, 1}, {-1, -1}};

bool isValid(int i, int j, int &n, int &m) {
    return i >= 0 && i < n && j >= 0 && j < m;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    for (int test = 1; test <= t; test++) {
        int n, m, si = -1, sj = -1, di = -1, dj = -1;
        cin >> n >> m;
        int adj[n][m];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> adj[i][j];
                if (adj[i][j] == -1) {
                    si = i;
                    sj = j;
                } else if (adj[i][j] == -2) {
                    di = i;
                    dj = j;
                }
            }
        }

        if (si != -1 && di != -1) {
            bool visited[n][m] = {false};
            int level[n][m] = {0};

            queue<pair<int, int>> q;
            q.push({si, sj});
            visited[si][sj] = true;

            while (!q.empty()) {
                pair<int, int> f = q.front();
                q.pop();

                for (auto d : dir) {
                    int i = f.first + d.first, j = f.second + d.second;
                    if (isValid(i, j, n, m) && !visited[i][j] && adj[i][j] != 0) {
                        q.push({i, j});
                        visited[i][j] = true;
                        level[i][j] = level[f.first][f.second] + adj[f.first][f.second];
                    }
                }
            }
            cout << "Case " << test << ": ";
            if (!visited[di][dj]) 
                cout << "Impossible\n";
            else
                cout << level[di][dj]+1 << endl;
        }
        else 
            cout << "Case " << test << ": Impossible\n";
    }
    return 0;
}

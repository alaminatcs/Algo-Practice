#include <bits/stdc++.h>
using namespace std;

int n, m, ki, kj, qi, qj;
vector<pair<int, int>> direction = {{-2,-1}, {-2,1}, {2,-1}, {2,1}, {-1,2}, {1,2}, {-1,-2}, {1,-2}};

bool is_valid(int ni, int nj) {
    return ni>=0 && ni<n && nj>=0 && nj<m;
}


void no_of_steps() {
    cin >> n >> m; cin >> ki >> kj; cin >> qi >> qj;
    bool visited[n+5][m+5] = {false}; int level[n+5][m+5] = {0};

    queue<pair<int, int>> q; q.push({ki, kj});
    level[ki][kj] = 0; visited[ki][kj] = true;
    while (!q.empty()) {
        pair<int, int> f = q.front();
        int i = f.first, j = f.second; q.pop();

        for (auto d : direction) {
            int ni = i + d.first, nj = j + d.second;
            if (is_valid(ni, nj) && !visited[ni][nj]) {
                q.push({ni, nj}); visited[ni][nj] = true;
                level[ni][nj] = level[i][j] + 1;
            }
        }
    }
    if (!visited[qi][qj]) cout << "-1\n";
    else cout << level[qi][qj] << "\n";
}

int main() {
    // Write your code here
    int tc; cin >> tc;
    while (tc--) {
        no_of_steps();
    }    
    return 0;
}
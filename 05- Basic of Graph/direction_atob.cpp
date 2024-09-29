#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, e; cin >> n >> e;
    vector<vector<int>> mat(n);

    while (e--) {
        int a, b; cin >> a >> b;
        mat[a].push_back(b);
        mat[a].push_back(a);
        mat[b].push_back(b);
    }

    int q; cin >> q;
    while (q--) {
        int a, b; cin >> a >> b;

        bool rem = false;
        for (int node : mat[a]) {
            if (node == b) {
                rem = true; break;
            }
        }
        if (rem) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}
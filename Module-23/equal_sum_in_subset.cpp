/*
Problem Name: Is equal sum Subset possible(using DP-iterative way).
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n; int ar[n+1];
    for (int i = 0; i < n; i++) cin >> ar[i];

    int s = 0;
    for (int i = 0 ; i < n; i++) s += ar[i];

    if (s%2) cout << "No\n";
    else {
        s /= 2;
        bool dp[n+1][s+1]; dp[0][0] = true;
        for (int i = 1; i <= s; i++) dp[0][i] = false;

        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= s; j++) {
                if (ar[i-1] <= j) {
                    bool op1 = dp[i-1][j-ar[i-1]];
                    bool op2 = dp[i-1][j];
                    dp[i][j] = op1 || op2;
                }
                else dp[i][j] = dp[i-1][j];
            }
        }
        if (dp[n][s]) cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}
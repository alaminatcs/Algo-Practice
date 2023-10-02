/*
Problem Link: https://leetcode.com/problems/coin-change/
*/
#include <bits/stdc++.h>
using namespace std;

const int inf = 1e9+7;

int main() {
    int n; cin >> n; int ar[n+1];
    for (int i = 1; i <= n; i++) cin >> ar[i];
    int k; cin >> k;

    int dp[n+1][k+1]; dp[0][0] = 0;
    for (int i = 1; i <= k; i++) dp[0][i] = inf;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= k; j++) {
            if (ar[i] <= j) {
                int op1 = 1 + dp[i][j-ar[i]];
                int op2 = dp[i-1][j];
                dp[i][j] = min(op1, op2);
            }
            else dp[i][j] = dp[i-1][j];
        }
    }
    cout << "min " << dp[n][k] << " coin need to make " << k << "\n";
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= k; j++) {
            if (dp[i][j] == inf) cout << "x ";
            else cout << dp[i][j] << " ";
        } cout << "\n";
    }
    return 0;
}
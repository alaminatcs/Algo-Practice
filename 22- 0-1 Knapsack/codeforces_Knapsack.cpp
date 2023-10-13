/*
Problem Link: https://codeforces.com/group/MWSDmqGsZm/contest/223339/problem/U
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k; cin >> n >> k; int v[n+1], w[n+1];
    for (int i = 1; i <= n; i++) {
        cin >> w[i] >> v[i];
    }

    int dp[n+1][k+1];
    for (int i = 0; i <= n; i++) dp[i][0] = 0;
    for (int i = 0; i <= k; i++) dp[0][i] = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            if (w[i] <= j) {
                int c1 = v[i] + dp[i-1][j-w[i]];
                int c2 = dp[i-1][j];
                dp[i][j] = max(c1, c2);
            }
            else dp[i][j] = dp[i-1][j];
        }
    }
    cout << dp[n][k];
    return 0;
}
/*
Problem Name: Unbound Knapsack Implementation using DP(iterative way).
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;  int w[n], v[n];
    for (int i = 0; i < n; i++) {
        cin >> w[i] >> v[i]; 
    }
    int k; cin >> k; int dp[n+1][k+1];
    for (int i = 0; i <= n; i++) dp[i][0] = 0;
    for (int i = 0; i <= k; i++) dp[0][i] = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            if (w[i-1] <= j) {
                int op1 = v[i-1] + dp[i][j-w[i-1]];
                int op2 = dp[i-1][j];
                dp[i][j] = max(op1, op2);
            }
            else dp[i][j] = dp[i-1][j];
        }
    }
    cout << dp[n][k] << "\n";
    return 0;
}
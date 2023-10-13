/*
Problem Name: Coin change problem using iterative dp(how many way u can make k tk)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n; int ar[n+1];
    for (int i = 1; i <= n; i++) cin >> ar[i];
    int k; cin >> k;

    int dp[n+1][k+1]; dp[0][0] = 1;
    for (int i = 1; i <= k; i++) dp[0][i] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= k; j++) {
            if (ar[i] <= j) {
                int op1 = dp[i][j-ar[i]];
                int op2 = dp[i-1][j];
                dp[i][j] = op1 + op2;
            }
            else dp[i][j] = dp[i-1][j];
        }
    }
    cout << dp[n][k] << " way u can make " << k << "\n";
    return 0;
}
/*
Problem Name: Rod/Tree cutting using iterative dp.
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n; int ar[n+1];
    for (int i = 1; i <= n; i++) cin >> ar[i];

    int dp[n+1][n+1];
    for (int i = 0; i <= n; i++) dp[i][0] = 0;
    for (int i = 0; i <= n; i++) dp[0][i] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i <= j) {
                int op1 = ar[i] + dp[i][j-i];
                int op2 = dp[i-1][j];
                dp[i][j] = max(op1, op2);
            }
            else dp[i][j] = dp[i-1][j];
        }
    }
    cout << dp[n][n] << "\n";
    return 0;
}
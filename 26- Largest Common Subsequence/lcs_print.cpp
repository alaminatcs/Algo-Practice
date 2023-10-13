/*
Problem Name: Longest Common Subsequence between two string using it(dp).
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    string a, b; cin >> a >> b;
    
    int m = a.size(), n = b.size(); int dp[m+1][n+1];
    for (int i = 0; i <= m; i++) dp[i][0] = 0;
    for (int i = 0; i <= n; i++) dp[0][i] = 0;

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (a[i-1] == b[j-1]) {
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else {
                int op1 = dp[i-1][j];
                int op2 = dp[i][j-1];
                dp[i][j] = max(op1, op2);
            }
        }
    }
    string res = ""; int i = m, j = n;
    while (1) {
        if (i==0 || j==0) break;
        if (a[i-1] == b[j-1]) {
            res += a[i-1]; i--; j--;
        }
        else {
            if (dp[i-1][j] >= dp[i][j-1]) i--;
            else j--;
        }
    }
    reverse(res.begin(), res.end());
    cout << dp[m][n] << ": " << res << "\n";
    return 0;
}
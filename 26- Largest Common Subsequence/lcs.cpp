/*
Problem Name: Longest Common Subsequence between two string using memoization(dp).
*/
#include <bits/stdc++.h>
using namespace std;

int dp[1005][1005];

int lc_subsequence(string a, int m, string b, int n) {
    if (m==0 || n==0) return 0;
    if (dp[m][n] != -1) return dp[m][n];
    if (a[m-1] == b[n-1]) {
        return dp[m][n] = 1 + lc_subsequence(a, m-1, b, n-1);
    }
    else {
        int op1 = lc_subsequence(a, m-1, b, n);
        int op2 = lc_subsequence(a, m, b, n-1);
        return dp[m][n] = max(op1, op2);
    }
}
int main()
{
    string a, b; cin >> a >> b;
    memset(dp, -1, sizeof(dp));
    // for (int i = 0; i <= a.size(); i++) {
    //     for (int j = 0; j <= b.size(); j++) dp[i][j] = -1;
    // }
    cout << lc_subsequence(a, a.size(), b, b.size());
    return 0;
}
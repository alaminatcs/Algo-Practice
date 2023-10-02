/*
Problem Name: Subset sum using DP.
Problem Link: 
*/
#include <bits/stdc++.h>
using namespace std;

int dp[1005][1005];

bool is_subset(int n, int *ar, int s) {
    if (n == 0) {
        if (s == 0) return true;
        else return false;
    }
    if (dp[n][s] != -1) return dp[n][s];
    if (ar[n-1] <= s) {
        bool op1 = is_subset(n-1, ar, s-ar[n-1]);
        bool op2 = is_subset(n-1, ar, s);
        return dp[n][s] = op1 || op2;
    }
    else return dp[n][s] = is_subset(n-1, ar, s);
}

int main() {
    int n; cin >> n; int ar[n];
    for (int i = 0; i < n; i++) cin >> ar[i];

    int s; cin >> s;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= s; j++) dp[i][j] = -1;
    }
    if (is_subset(n, ar, s)) cout << "Yes\n";
    else cout << "No\n";
    return 0;
}
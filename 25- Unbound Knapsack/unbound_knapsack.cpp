/*
Problem Name: Unbound Knapsack Implementation using DP(memoization).
*/
#include <bits/stdc++.h>
using namespace std;

int dp[1000][1000];

int unbound_knapsack(int n, int k, int *w, int *v) {
    if (n==0 || k==0) return 0;
    if (dp[n][k] != -1) return dp[n][k];
    if (w[n-1] <= k) {
        int op1 = v[n-1] + unbound_knapsack(n, k-w[n-1], w, v);
        int op2 = unbound_knapsack(n-1, k, w, v);
        return dp[n][k] = max(op1, op2);
    }
    else return dp[n][k] = unbound_knapsack(n-1, k, w, v);
}

int main() {
    int n; cin >> n;  int w[n], v[n];
    for (int i = 0; i < n; i++) {
        cin >> w[i] >> v[i]; 
    }
    int k; cin >> k;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= k; j++) dp[i][j] = -1;
    }
    int mx_val = unbound_knapsack(n, k, w, v);
    cout << mx_val << "\n";
    return 0;
}
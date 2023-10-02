/*
Problem Name: Rod/Tree cutting using Knapsack.
*/
#include <bits/stdc++.h>
using namespace std;

int dp[1005][1005];

int unbound_knapsack(int n, int w, int *ar) {
    if (n==0 || w==0) return 0;
    if (dp[n][w] != -1) return dp[n][w];
    if (n <= w) {
        int op1 = ar[n] + unbound_knapsack(n, w-n, ar);
        int op2 = unbound_knapsack(n-1, w, ar);
        return dp[n][w] = max(op1, op2);
    }
    else return dp[n][w] = unbound_knapsack(n-1, w, ar);
}

int main() {
    int n; cin >> n; int ar[n+1];
    for (int i = 1; i <= n; i++) cin >> ar[i];

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) dp[i][j] = -1;
    }

    cout << unbound_knapsack(n, n, ar);
    return 0;
}
/*
Problem Name: 0-1 Knapsack Basic implementation using DP.
Problem Details: You have given a bag which can contains at most C kg,
                there are N products into the shop each value V(i), calculate
                the max amount of products you can keep into that's bag so that the
                total amount can be at max.
*/
#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
int dp[1005][1005];

int knapsack(int *v, int *w, int pn, int k) {
    if (pn==0 || k<=0) return 0;
    if (dp[pn][k] != -1) return dp[pn][k];
    if (k >= w[pn-1]) {
        int c1 = knapsack(v, w, pn-1, k-w[pn-1]) + v[pn-1];
        int c2 = knapsack(v, w, pn-1, k);
        return dp[pn][k] = max(c1, c2);
    }
    else return dp[pn][k] = knapsack(v, w, pn-1, k);
}

int main() {
    int n; cin >> n; int v[n], w[n];
    for (int i = 0; i < n; i++) cin >> v[i];
    for (int i = 0; i < n; i++) cin >> w[i];

    int k; cin >> k;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= k; j++) dp[i][j] = -1;
    }
    cout << knapsack(v, w, n, k) << "\n";
    return 0;
}
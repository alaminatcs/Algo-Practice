/*
Problem Name: 0-1 Knapsack Basic implementation using DP.
Problem Details: You have given a bag which can contains at most C kg,
                there are N products into the shop each value V(i), calculate
                the max amount of products you can keep into that's bag so that the
                total amount can be at max.
*/
#include <bits/stdc++.h>
using namespace std;

// int knapsack(int *v, int *w, int pn, int k) {
//     if (pn==0 || k<=0) return 0;
//     if (dp[pn][k] != -1) return dp[pn][k];
//     if (k >= w[pn-1]) {
//         int c1 = knapsack(v, w, pn-1, k-w[pn-1]) + v[pn-1];
//         int c2 = knapsack(v, w, pn-1, k);
//         return dp[pn][k] = max(c1, c2);
//     }
//     else return dp[pn][k] = knapsack(v, w, pn-1, k);

//convert this memoization dp into iterative dp
// }

int main() {
    int n; cin >> n; int v[n+1], w[n+1];
    for (int i = 1; i <= n; i++) cin >> v[i];
    for (int i = 1; i <= n; i++) cin >> w[i];

    int k; cin >> k;
    int dp[n+1][k+1];
    /*
    for (int i = 0; i <=n; i++) {
        for (int j = 0; j <= k; j++) {
            if (i==0 || j==0)  dp[i][j] = 0;
        }
    }
    */
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
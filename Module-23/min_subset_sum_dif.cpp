/*
Problem Name: Find minimum Subset sum difference(using DP-iterative way).
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n; int ar[n+1];
    for (int i = 0; i < n; i++) cin >> ar[i];

    int s = 0;
    for (int i = 0 ; i < n; i++) s += ar[i];

    bool dp[n+1][s+1]; dp[0][0] = true;
    for (int i = 1; i <= s; i++) dp[0][i] = false;

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= s; j++) {
            if (ar[i-1] <= j) {
                bool op1 = dp[i-1][j-ar[i-1]];
                bool op2 = dp[i-1][j];
                dp[i][j] = op1 || op2;
            }
            else dp[i][j] = dp[i-1][j];
        }
    }
    vector<int> subset_sum;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= s; j++) {
            if (dp[i][j]) subset_sum.push_back(j);
        }
    }
    int ans = INT_MAX;
    for (auto var : subset_sum) {
        int sub1 = var, sub2 = s - var;
        ans = min(ans, abs(sub1 - sub2));
    }
    cout << ans << "\n";

    // cout << "all combination:\n";
    // for (int i = 0; i <= n; i++) {
    //     cout << "u can create sum_val(col_no) by using no of " << i << " elements:\n";
    //     for (int j = 0; j <= s; j++) {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << "\n\n";
    // }
    return 0;
}
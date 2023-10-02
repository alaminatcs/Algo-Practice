/*
Problem Name: Frog1
Problem Link: https://atcoder.jp/contests/dp/tasks/dp_a
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n; int ar[n+1];
    for (int i = 1; i <= n; i++) cin >> ar[i];
    int dp[n+1]; dp[1] = 0; dp[2] = abs(ar[2] - ar[1]);
    for (int i = 3; i <= n; i++) {
        int ans1 = dp[i-1] + abs(ar[i] - ar[i-1]);
        int ans2 = dp[i-2] + abs(ar[i] - ar[i-2]);
        dp[i] = min(ans1, ans2);
    }
    cout << dp[n] << "\n";
    return 0;
}
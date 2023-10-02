/*
Problem Name: Is string(a) is a subsequence of another string(b).
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    string a, b; cin >> a >> b;

    int n = a.size(), m = b.size();
/*
    //bruteforce approach -> TC: O(n+m) -- n=sizeof(a), m=sizeof(b)
    bool rem = false;
    for (int i = 0, j = 0; j < m; j++) {
        if (a[i] == b[j]) i++;
        if (i == n) {
            rem = true; break;
        }
    }
    if (rem) cout << "Yes\n";
    else cout << "No\n";
*/
    //LCS approach ->TC: O(n*m) -- n=sizeof(a), m=sizeof(b)
    int dp[n+1][m+1];
    for (int i = 0; i <= n; i++) dp[i][0] = 0; 
    for (int j = 1; j <= m; j++) dp[0][j] = 0;
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i-1] == b[j-1]) {
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    if (dp[n][m] == n) cout << "Yes\n";
    else cout << "No\n";
    return 0;
}
/*
Problem Name: Minimum Insertion to make a Palindrome. 
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    string a; cin >> a;
    string b = a; reverse(b.begin(), b.end());
    int n = a.size(), m = n;

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
    cout << "Min Insert to make Pal: " << n - dp[n][m] << "\n";
    int i = n, j = m; string str = "";
    while (i!=0 && j!=0) {
        if (a[i-1] == b[j-1]) {
            i--; j--;
        }
        else {
            if (dp[i-1][j] >= dp[i][j-1]) {
                str += a[i-1]; i--;
            }
            else {
                str += b[j-1]; j--;
            }
        }
    }
    for (int i = 0; i < str.size()/2; i++) cout << str[i];
    return 0;
}
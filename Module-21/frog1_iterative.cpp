#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+7;

int main() {
  int n; cin >> n; int ar[n];
  for (int i = 0; i < n; i++) {
    cin >> ar[i];
  }
  int dp[n]; dp[0] = 0; dp[1] = abs(ar[1]-ar[0]);
  for (int i = 2; i < n; i++) {
    int ans1 = dp[i-1] + abs(ar[i] - ar[i-1]);
    int ans2 = dp[i-2] + abs(ar[i] - ar[i-2]);
    dp[i] = min(ans1, ans2);
  }
  cout << dp[n-1] << "\n";
  return 0;
}
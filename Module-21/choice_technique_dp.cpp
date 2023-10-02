/*
Problem Name: Frog1
Problem Link: https://atcoder.jp/contests/dp/tasks/dp_a
*/
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 +7; vector<int> memoization(N, -1);

int choice_technique(int *ar, int n) {
    if (n == 1) return 0;
    else if (n == 2) return abs(ar[2] - ar[1]);
    else {
        if (memoization[n] != -1) return memoization[n];
        int ans1 = choice_technique(ar, n-1) + abs(ar[n] - ar[n-1]);
        int ans2 = choice_technique(ar, n-2) + abs(ar[n] - ar[n-2]);
        return memoization[n] = min(ans1, ans2);
    }
}

int main() {
    int n; cin >> n; int ar[n+1];
    for (int i = 1; i <= n; i++) cin >> ar[i];
    cout << choice_technique(ar, n) << "\n";
    return 0;
}
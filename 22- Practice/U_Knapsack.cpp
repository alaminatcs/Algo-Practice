/*
Problem Name: 
Problem Link: https://codeforces.com/group/MWSDmqGsZm/contest/223339/problem/U
*/
#include <bits/stdc++.h>
using namespace std;

int memoization[1005][1005];

int knapsack(int n, int w, int *wt, int *val) {
    if (n==0 || w==0) return 0;
    if (memoization[n][w] != -1) return memoization[n][w];
    if (wt[n-1] <= w) {
        int c1 = knapsack(n-1, w-wt[n-1], wt, val) + val[n-1];
        int c2 = knapsack(n-1, w, wt, val);
        return memoization[n][w] = max(c1, c2);
    }
    else return memoization[n][w] = knapsack(n-1, w, wt, val);
}

int main() {
    int n, w; cin >> n >> w; int wt[n], val[n];
    for (int i = 0; i < n; i++) {
        cin >> wt[i] >> val[i];
    }
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= w; j++) {
            memoization[i][j] = -1;
        }
    }
    cout << knapsack(n, w, wt, val);
    return 0;
}
/*
Problem Name: Subset sum using Recursion.
Problem Link: 
*/
#include <bits/stdc++.h>
using namespace std;

bool is_subset(int n, int *ar, int s) {
    if (n == 0) {
        if (s == 0) return true;
        else return false;
    }
    if (ar[n-1] <= s) {
        bool op1 = is_subset(n-1, ar, s-ar[n-1]);
        bool op2 = is_subset(n-1, ar, s);
        return op1 || op2;
    }
    else return is_subset(n-1, ar, s);
}

int main() {
    int n; cin >> n; int ar[n];
    for (int i = 0; i < n; i++) cin >> ar[i];

    int s; cin >> s;
    if (is_subset(n, ar, s)) cout << "Yes\n";
    else cout << "No\n";
    return 0;
}
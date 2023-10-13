#include <bits/stdc++.h>
#define lln long long
using namespace std;

bool knapsack(lln n, lln *ar, lln x) {
    if (n == 0) {
        if (x == 0) return true;
        else return false;
    }
    bool op1 = knapsack(n-1, ar, x+ar[n-1]);
    bool op2 = knapsack(n-1, ar, x-ar[n-1]);
    cout << n << " " << x << "\n";
    return op1 || op2;
}


int main() {
    lln n, x; cin >> n >> x; lln ar[n];
    for (lln i = 0; i < n; i++) cin >> ar[i];
    
    if (knapsack(n, ar, x)) cout << "YES\n";
    else cout << "NO\n";
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

bool knapsack(int n) {
    if (n==1) return true;
    if (n <= 0) return false;
    if (n%2) return knapsack(n-3);
    else return knapsack(n/2);
}


int main() {
    int tc; cin >> tc;
    while (tc--) {
        int n; cin >> n;
        if (knapsack(n)) cout << "YES\n";
        else cout << "NO\n";
    } 
    return 0;
}
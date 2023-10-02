/*
Problem Name: Fibonacci using iteration method.
*/
#include <bits/stdc++.h>
#define lln long long
using namespace std;

int main() {
    lln n; cin >> n; lln ar[n+1];
    ar[0] = 0; ar[1] = 1;
    for (int i = 2; i <= n; i++) {
        ar[i] = ar[i-1] + ar[i-2];
    }
    cout << ar[n] << "\n";
    return 0;
}
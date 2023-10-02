/*
Problem Name: Fibonacce using Memoization technique.
*/
#include <bits/stdc++.h>
#define lln long long
using namespace std;

const lln N = 1e8+1; lln memorize[N];

void rem_set(lln n) {
    for (lln i = 0; i <= n; i++) {
        memorize[i] = -1;
    }
}

lln fibonacci(lln n) {
    if (n==0 || n==1) return 1;

    if (memorize[n] != -1) return memorize[n];  //memoization

    lln part1 = fibonacci(n-1);
    lln part2 = fibonacci(n-2);
    memorize[n] = part1 + part2;
    return memorize[n];
}

int main() {
    lln n; cin >> n; rem_set(n);
    cout << fibonacci(n) << "\n";
    return 0;
}
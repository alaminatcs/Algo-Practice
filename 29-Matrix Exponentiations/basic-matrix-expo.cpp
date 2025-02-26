#include <bits/stdc++.h>
using namespace std;

#define N 100
typedef unsigned long long ull;
ull mod = 1000000007;
ull res[N][N], base[N][N];

void multiplications(ull r[][N], ull b[][N], int n) {
    ull temp[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            temp[i][j] = 0;
            for (int k = 0; k < n; k++) {
                temp[i][j] += (r[i][k] * b[k][j]);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) r[i][j] = temp[i][j];
    }
}

void power_function(int n, int p) {
    while (p) {
        if (p % 2) {
            multiplications(res, base, n);
            p--;
        }
        else {
            multiplications(base, base, n);
            p /= 2;
        }
    }
}

int main() {
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> base[i][j];

            if (i == j) res[i][i] = 1;
            else res[i][j] = 0;
        }
    }
    int p; cin >> p;
    power_function(n, p);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) cout << res[i][j] << " ";
        cout << "\n";
    }
    return 0;
}
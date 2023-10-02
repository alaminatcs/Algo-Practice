#include <bits/stdc++.h>
using namespace std;

void merge(int *ar, int l, int m, int r) {
    int ls = m-l+1, rs = r-m;
    int lar[ls], rar[rs];
    for (int k = 0, i = l; i <= m; i++) {
        lar[k++] = ar[i];
    }
    for (int k = 0, i = m+1; i <= r; i++) {
        rar[k++] = ar[i];
    }
    int i = 0, j = 0, k = l;
    while (i<ls && j<rs) {
        if (lar[i] <= rar[j]) {
            ar[k++] = lar[i++];
        }
        else {
            ar[k++] = rar[j++];
        }
    }
    while (i < ls) {
        ar[k++] = lar[i++];
    }
    while (j < rs) {
        ar[k++] = rar[j++];
    }
}

void divide(int *ar, int l, int r) {
    if (l < r) {
        int m = (l + r)/2;
        divide(ar, l, m); divide(ar, m+1, r);
        merge(ar, l, m, r);
        // cout << "this\n";
        // for (int i = l; i <= m; i++) cout << ar[i] << " ";
        // cout << "\n";
        // for (int i = m+1; i <= r; i++) cout << ar[i] << " ";
        // cout << "\n";
    }
}

int main() {
    int n; cin >> n; int ar[n];
    for (int i = 0; i < n; i++) cin >> ar[i];
    divide(ar, 0, n-1);
    for (int i = 0; i < n; i++) cout << ar[i] << " ";
    return 0;
}
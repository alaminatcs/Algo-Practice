#include <bits/stdc++.h>
using namespace std;

void merge_them(int *ar, int l, int m, int r) {
    int lsize = m-l+1, rsize = r-m;
    int lar[lsize], rar[rsize];

    for (int i = l; i <= m; i++) {
        lar[i] = ar[i];
    }

    for (int i = m+1, j = 0; i <= r; i++) {
        rar[j] = ar[i]; j++;
    }
    int i = 0, j = 0, k = 0;
    while (i<lsize && j<rsize) {
        if (lar[i] < rar[j]) {
            ar[k++] = lar[i++];
        }
        else {
            ar[k++] = rar[j++];
        }
    }
    while (i < lsize) {
        ar[k++] = lar[i++];
    }
    while (j < rsize) {
        ar[k++] = rar[j++];
    }
    //for (int i = 0; i < lsize; i++) cout << lar[i] << " ";
    //for (int i = 0; i < rsize; i++) cout << rar[i] << " ";
}

int main() {
    int n; cin >> n; int ar[n];
    for (int i = 0; i < n; i++) cin >> ar[i];
    merge_them(ar, 0, n/2-1, n-1);
    for (int i = 0; i < n; i++) cout << ar[i] << " ";
    return 0;
}

/*
input:
7
4 5 6 0 1 2 3

output:
0 1 2 3 4 5 6
*/
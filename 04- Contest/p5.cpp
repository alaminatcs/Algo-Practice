#include <bits/stdc++.h>
using namespace std;

void merge_them(int* ar1, int n, int* ar2, int m) {
    int size = n+m-2,  ar[size];
    int i=0, j=0, k=0;

    while (j<n && k<m) {
        if (ar1[j] >=  ar2[k]) ar[i++] = ar1[j++];
        else ar[i++] = ar2[k++];
    }
    while (j < n-1) ar[i++] = ar1[j++];
    while (k < m-1) ar[i++] = ar2[k++];


    for (int i = 0; i < size; i++) cout << ar[i] << " ";
}

int main() {
    int n; cin >> n; n++; int ar1[n];
    for (int i = 0; i < n-1; i++) cin >> ar1[i];
    ar1[n-1] = INT_MIN;

    int m; cin >> m; m++; int ar2[m];
    for (int i = 0; i < m-1; i++) cin >> ar2[i];
    ar2[m-1] = INT_MIN;

    merge_them(ar1, n, ar2, m);
    return 0;
}
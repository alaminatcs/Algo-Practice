#include <bits/stdc++.h>
using namespace std;

const int n = 1e5+7; int ar[n];

void merge(int l, int r, int mid) {
    int ls = mid-l+1; int left[ls+1];
    for (int i=l, j=0; i <= mid; i++, j++) left[j] = ar[i];
    left[ls] = INT_MIN;

    int rs = r-mid; int right[rs+1];
    for (int i=mid+1, j=0; i <= r; i++, j++) right[j] = ar[i];
    right[rs] = INT_MIN;

    int i = 0, j = 0;
    while (l <= r) {
        if (left[i] >=  right[j]) ar[l++] = left[i++];
        else ar[l++] = right[j++];
    }
}

void merge_sort(int l, int r) {
    if (l >= r) return;
    int mid = (l+r)/2;
    merge_sort(l, mid); merge_sort(mid+1, r);
    merge(l, r, mid);
}

int main() {
    int n; cin >> n;
    for (int i = 0; i < n; i++) cin >> ar[i];
    merge_sort(0, n-1);
    for (int i = 0; i < n; i++) cout << ar[i] << " ";
    return 0;
}
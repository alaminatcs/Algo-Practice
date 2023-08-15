#include <bits/stdc++.h>
using namespace std;

const int n = 1e5+7; int ar[n];

void merge(int l, int r, int mid) {
    int left_size = mid-l+1; int left_ar[left_size+1];
    for (int i=l, j=0; i <= mid; i++, j++) left_ar[j] = ar[i];
    left_ar[left_size] = INT_MIN;

    int right_size = r-mid; int right_ar[right_size+1];
    for (int i=mid+1, j=0; i <= r; i++, j++) right_ar[j] = ar[i];
    right_ar[right_size] = INT_MIN;

    int i = 0, j = 0;
    while (l <= r) {
        if (left_ar[i] >=  right_ar[j]) ar[l++] = left_ar[i++];
        else ar[l++] = right_ar[j++];
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
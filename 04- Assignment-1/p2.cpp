#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n; int ar[n];
    for (int i = 0; i < n; i++) cin >> ar[i];
    int k; cin >> k;

    int rem = 0, left = 0, right = n-1;
    while (left <= right) {
        int mid = (left + right)/2;
        if (ar[mid] == k) {
            rem = mid; break;
        }
        else if (ar[mid] < k) left = mid + 1;
        else right = mid - 1;
    }

    if (rem) cout << rem << "\n";
    else cout << "Not Found\n";
    return 0;
}
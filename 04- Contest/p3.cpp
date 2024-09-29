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
            int l = mid-1, r = mid+1;
            if (l>=0 && ar[l]==k) rem = 1;
            else if(r<=n-1 && ar[r]==k) rem = 1;
            break;
        }
        else if (ar[mid] < k) left = mid + 1;
        else right = mid - 1;
    }

    if (rem) cout << "YES\n";
    else cout << "NO\n";
    return 0;
}
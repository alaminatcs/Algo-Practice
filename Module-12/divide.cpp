#include <bits/stdc++.h>
using namespace std;

void divide_them(int *ar, int l, int r) {
    // for (int i = l; i <= r; i++) cout << ar[i] << " ";
    // cout << "\n";
    if (l < r) {
        int m = (l + r)/2;
        divide_them(ar, l, m);
        divide_them(ar, m+1, r);
    }
}

int main() {
    int n; cin >> n; int ar[n];
    for (int i = 0; i < n; i++) cin >> ar[i];
    divide_them(ar, 0, n-1);
    return 0;
}

/*
input:
7
1 2 3 4 5 6 7

output:
1 2 3 4 5 6 7 
1 2 3 4 
1 2 
1 
2 
3 4 
3 
4 
5 6 7 
5 6 
5 
6 
7 
*/
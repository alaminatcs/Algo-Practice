#include<bits/stdc++.h> 
using namespace std;

int rem, sum;
void subset_gen(int *ar, int *sub, int f, int l, int ci, int ss) { 
	if (ci == ss) { 
		int subm = 0;
        for (int j = 0; j < ss; j++) subm += sub[j]; 
		//cout << subm << " " << sum-subm << endl;
        int rest = sum - subm;
        rem = min(rem , abs(subm-rest)); return; 
	}
    
	for (int i = f; i<=l && l-i+1 >= ss-ci; i++) { 
		sub[ci] = ar[i]; subset_gen(ar, sub, i+1, l, ci+1, ss);
	} 
} 

int main() {
    int tc; cin >> tc;
    while (tc--) {
        int n; cin >> n; int ar[n]; sum =  0;
        for (int i = 0; i < n; i++) {
            cin >> ar[i]; sum += ar[i];
        }

        int sub[n/2]; rem = INT_MAX;
        subset_gen(ar, sub, 0, n-1, 0, n/2);
        cout << rem << "\n";
    }
    return 0;
}
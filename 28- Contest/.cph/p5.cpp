#include <bits/stdc++.h>
using namespace std;

void create(vector<int>& ar, int ss, int i, vector<int>& sub) {
    if (ss == 0) {
        //int sum = 0;
        for (auto var : sub) cout << var << " ";//sum += var;
        cout << "\n"; return;
    }

    if (i >= ar.size()) return;

    // Include the current element in the subset
    sub.push_back(ar[i]);
    create(ar, i+1, ss-1, sub);

    // Exclude the current element from the subset
    sub.pop_back();
    create(ar, i+1, ss, sub);
}

int main() {
    int tc; cin >> tc;
    while (tc--) {
        int n, sum = 0; cin >> n; vector<int> ar;
        for (int i = 0; i < n; i++) {
            int x; cin >> x; sum += x; ar.push_back(x); 
        }
        vector<int> sub;
        create(ar, ar.size()/2, 0, sub);
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int tc; cin >> tc;
     while (tc--) {
        string str; cin >> str; int t = 1, c = 0;
        int i = 0, j = str.size()-1;
        while (i <= j) {
            while (str[i] != '1' && i<=j) {
                i++;
            }
            int l = i, lc = 0;
            while (str[l] == '1' && l<=j) {
                l++; lc++;
            }

            while (str[j] != '1' && j>=i) {
                j--;
            }
            int r = j, rc = 0;
            while (str[r] == '1' && r>=i) {
                r--; rc++;
            }
            if (lc > rc) i = l;
            else j = r;
            if (t%2) c += max(lc, rc);
            t++;
        }
        cout << c << "\n";
     }
    return 0;
}
/*
Problem Name: Complexity analysis of Matrix multiplication.
Problem Link: 
*/
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int f_row, f_col; cin >> f_row >> f_col;
    int a[f_row][f_col];
    for (int i = 0; i < f_row; i++) {
        for (int j = 0; j < f_col; j++) cin >> a[i][j];
    }
    int s_row, s_col; cin >> s_row >> s_col;
    int b[s_row][s_col];
    for (int i = 0; i < s_row; i++) {
        for (int j = 0; j < s_col; j++) cin >> b[i][j];
    }

    //multiplication elements print  
    int res[f_row][s_col];
    for (int i = 0; i < f_row; i++) {
        for (int j = 0; j < s_col; j++) {
            int sum = 0;
            for (int k = 0; k < s_row; k++) {
                sum += a[i][k] * b[k][j];
            }
            cout << sum << " ";
        }
        cout << "\n";   //time complexity: f_row * s_col * s_row
    }
    return 0;
}
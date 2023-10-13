/*
Problem Name: 0-1 Knapsack Basic implementation.
Problem Details: You have given a bag which can contains at most C kg,
                there are N products into the shop each value V(i), calculate
                the max amount of products you can keep into that's bag so that the
                total amount can be at max.
*/
#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
int n, c;

int knapsack(int *v, int *w, int pn, int k) {
    if (pn==0 || k<=0) return 0;
    if (k >= w[pn-1]) {
        int c1 = knapsack(v, w, pn-1, k-w[pn-1]) + v[pn-1];
        int c2 = knapsack(v, w, pn-1, k);
        return max(c1, c2);
    }
    else return knapsack(v, w, pn-1, k);
    
}

int main() {
    cin >> n; int v[n], w[n];
    for (int i = 0; i < n; i++) cin >> v[i];
    for (int i = 0; i < n; i++) cin >> w[i];

    cin >> c;
    cout << knapsack(v, w, n, c) << "\n";
    return 0;
}
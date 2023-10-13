/*
Problem Name: Fibonacce using Basic technique.
*/
#include <bits/stdc++.h>
using namespace std;

int fibonacci(int n) {
    if (n <= 1) return 1;
    //if (n==1 || n==0) return 1;
    // int ans1 = fibonacci(n-1);
    // int ans2 = fibonacci(n-2);
    // return ans1 + ans2;
    return fibonacci(n-1) + fibonacci(n-2);
}
int main() {
    int n; cin >> n;
    cout << fibonacci(n) << "\n";    
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
vector<int> nums;
void merge(int l, int r, int mid) {
    int ls = r-l+1; int left[ls+1];
    for (int i=l, j=0; i <= mid; i++, j++) left[j] = nums[i];
    left[ls] = INT_MAX;
    int rs = r-mid; int right[rs+1];
    for (int i=mid+1, j=0; i <= r; i++, j++) right[j] = nums[i];
    right[rs] = INT_MAX;
    int lp = 0, rp = 0;
    while (l < r) {
        if (left[lp] <= right[rp]) nums[l++] = left[lp++];
        else nums[l++] = right[rp++];
    }
}
void merge_sort(int l, int r) {
    if (l == r) return;
    int mid = (l+r)/2;
    merge_sort(l, mid); merge_sort(mid+1, r);
    merge(l, r, mid);
}

int main() {
    for (int i = 0; i < 4; i++) {
        int x; cin >> x; nums.push_back(x);
    }
    merge_sort(0, nums.size()-1);
    for (auto var : nums) cout << var << " ";
    return 0;
};
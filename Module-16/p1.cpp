#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
class cmp {
public:
    bool operator() (pii a, pii b) {
        if (a.first == b.first) {
            return a.second >= b.second;
        }
        return a.first >= b.first;
    }

};

int main() {
    int e; cin >> e;
    priority_queue<pii, vector<pii>, cmp> pq;
    for (int i = 0; i < e; i++) {
        int a, b; cin >> a >> b; pq.push({a, b});
    }
    while (!pq.empty()) {
        cout << pq.top().first << " ";
        cout << pq.top().second << "\n"; pq.pop();
    }
    return 0;
}
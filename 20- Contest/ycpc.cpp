#include <bits/stdc++.h>
using namespace std;

class Edge {
public:
    int a, b, w;
    Edge(int a, int b, int w) {
        this->a = a; this->b = b; this->w = w;
    }
};

bool cmp(Edge a, Edge b) {
    return a.w < b.w;
}

const int N = 1e5+7;
int parent[N], parent_size[N];

void dsu_set(int n) {
    for (int i = 1; i <= n; i++) {
        parent[i] = -1; parent_size[i] = 1;
    }
}

int dsu_find(int node) {
    while (parent[node] != -1) {
        node = parent[node];
    }
    return node;
}

void dsu_union(int a, int b) {
    int la = dsu_find(a); int lb = dsu_find(b);
    if (la != lb) {
        if (parent_size[la] > parent_size[lb]) {
            parent[lb] = la;
            parent_size[la] += parent_size[lb];
        }
        else {
            parent[la] = lb;
            parent_size[lb] += parent_size[la];
        }
    }
    
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n, e; cin >> n >> e;
    dsu_set(n); vector<Edge> v;
    for (int i = 1; i <= e; i++) {
        int a, b, w; cin >> a >> b >> w;
        v.push_back(Edge(a, b, w));
    }
    sort(v.begin(), v.end(), cmp);

    vector<Edge> res;
    for (Edge x : v) {
        int a = x.a, b = x.b, w = x.w;
        int la = dsu_find(a); int lb = dsu_find(b);
        if (la == lb) continue;
        res.push_back(x); dsu_union(a, b);
    }
    long long sum = 0; int count = 0;
    for (Edge x : res) {
        sum += x.w; count++;
    }
    if (count > n-1) cout << "Not Possible\n";
    else {
        cout << e-count << " " << sum << "\n";
    }
    return 0;
}

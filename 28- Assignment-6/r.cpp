#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+7; bool visited[N];
vector<pair<int, int>> adj[N]; int v, e;

class Edge {
public:
    int a, b, w;
    Edge(int a, int b, int w)
    {
        this->a = a;
        this->b = b;
        this->w = w;
    }
};

class Cmp {
public:
    bool operator()(Edge a, Edge b) {
        return a.w > b.w;
    }
};

void find(int p) {
    priority_queue<Edge, vector<Edge>, Cmp> pq;

    vector<Edge> edgeList; pq.push(Edge(p, p, 0));
    while (!pq.empty()) {
        Edge parent = pq.top(); pq.pop();
        if (!visited[parent.b]) {
            visited[parent.b] = true; edgeList.push_back(parent);
            for (auto ch : adj[parent.b]) {
                if (!visited[ch.first]) {
                    pq.push(Edge(parent.b, ch.first, ch.second));
                }
            }
        }
        
    }
    if (edgeList.size() != v) cout << "Not Possible\n";
    else {
        edgeList.erase(edgeList.begin()); int sum = 0;
        for (Edge val : edgeList) sum +=  val.w;
        cout << edgeList.size() << " " << sum << "\n";
    }
}

int main()
{
    cin >> v >> e;
    for (int i = 1; i <= e; i++) {
        int a, b, w; cin >> a >> b >> w;
        adj[a].push_back({b, w}); adj[b].push_back({a, w});
    }
    find(1);
    return 0;
}
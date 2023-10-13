/*
Problem Name: You will be given an undirected graph as input. Now print “YES” if
there is a cycle and print “NO” if there isn’t any cycle. Consider root as 1.
*/
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+3; vector<int> adj[N];
vector<bool> visited(N, false);

bool isCycleRemains(int parent, int source) {
    visited[parent] = true; bool rem = false;
    for (auto child : adj[parent]) {
        if (child != source) {
            if (visited[child]) return true;
            else rem |= isCycleRemains(child, parent);
        }
    }
    return rem;
}

int main() {
    int vertices, edges; cin >> vertices >> edges;
    for (int i = 1; i <= edges; i++) {
        int parent, child; cin >> parent >> child;
        adj[parent].push_back(child); adj[child].push_back(parent);
    }
    bool status = false;
    for (int i = 1; i <= vertices; i++) {
        if (visited[i] == false) {
            status |= isCycleRemains(i, -1);
        }
    }
    if (status) cout << "YES\n";
    else cout << "NO\n";
    return 0;
}
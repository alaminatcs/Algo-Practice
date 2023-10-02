/*
Problem Name: Cycle detection in graph.
Problem Link: 
*/
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+3; vector<int> adj[N];
vector<bool> visited(N, false);

bool dfs(int source, int parent) {
    visited[source] = true; bool status = false;
    for (auto child : adj[source]) {
        if (parent != child) {
            if (visited[child]) return true;
            else status |= dfs(child, source);
        }
    }
    return status;
}

int main() {
    int vertices, edges; cin >> vertices >> edges;
    for (int i = 1; i <= edges; i++) {
        int parent, child; cin >> parent >> child;
        adj[parent].push_back(child); adj[child].push_back(parent);
    }
    bool isCycleExist = false;
    for (int i = 1; i <= vertices; i++) {
        if (visited[i] == false) {
            isCycleExist |= dfs(i, -1);
        }
    }
    if (isCycleExist) cout << "cycle exist";
    else cout << "cycle not exist";
    return 0;
}
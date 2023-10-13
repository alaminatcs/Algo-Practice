/*
Problem Name: You will be given an undirected graph as input. Now count its
connected components and print it.
*/
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+3; vector<int> adj[N];
vector<bool> visited(N, false);

void dfs(int parent) {
    visited[parent] = true;
    for (auto child : adj[parent]) {
        if (!visited[child]) dfs(child);
    }
}

int main() {
    int vertices, edges; cin >> vertices >> edges;
    for (int i = 1; i <= edges; i++) {
        int parent, child; cin >> parent >> child;
        adj[parent].push_back(child); adj[child].push_back(parent);
    }
    int con_comp = 0;
    for (int i = 1; i <= vertices; i++) {
        if (visited[i] == false) {
            con_comp++; dfs(i);
        }
    }
    cout << con_comp << "\n";
    return 0;
}
/*
Problem Name: No of Connected component in a Graph.
Problem Link: 
*/
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+7; vector<int> adj[N];
vector<bool> visited(N, false);

void dfs(int parent) {
    visited[parent] = true;
    for (auto child : adj[parent]) {
        if (visited[child] == false) dfs(child);
    }
    cout << parent << " ";
}

int main() {
    int vertices, edges; cin >> vertices >> edges;
    for (int i = 1; i <= vertices; i++) {
        int parent, child; cin >> parent >> child;
        adj[parent].push_back(child); adj[child].push_back(parent);
    }
    int no_cc = 0;
    for (int i = 1; i <= vertices; i++) {
        if (visited[i] == false) {
            cout << ++no_cc << " no cc elm: "; dfs(i); cout << "\n";
        }
    }  
    //cout << "No of connected component: " << no_cc << "\n";  
    return 0;
}
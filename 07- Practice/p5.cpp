/*
Problem Name:  You will be given an undirected graph as input. Now count its
connected components and print it. Then print All the nodes in a connected
component. See the sample output for more clarification.
*/
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+3; vector<int> adj[N];
vector<bool> visited(N, false);
vector<int> container[1000];

void dfs(int parent, int con) {
    visited[parent] = true;
    container[con].push_back(parent);
    for (auto child : adj[parent]) {
        if (visited[child] == false) dfs(child, con);
    }
}

int main() {
    int vertices, edges; cin >> vertices >> edges;
    for (int i = 1; i <= edges; i++) {
        int parent, child; cin >> parent >> child;
        adj[parent].push_back(child); adj[child].push_back(parent);
    }
    int con = 0;
    for (int i = 1; i <= vertices; i++) {
        if (visited[i] == false) dfs(i, ++con);
    }
    cout << con << "\n";
    for (int i = 1; i <= con; i++) {
        cout << "Component " << i << " : ";
        for (auto var : container[i]) cout << var << " ";
        cout << "\n";
    }
    return 0;
}
/*
Problem:  You will be given an undirected graph. Print its BFS traversal in reverse
order. Consider root as 1.
Note: In the explanation video there was a mistake, the explanation was for DFS
traversal, but you have to do it using BFS traversal.
*/
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+7; vector<int> adj[N];
bool visited[N]; int level[N];

void bfs(int parent) {
    queue<int> q; q.push(parent);
    stack<int> s; s.push(parent);
    visited[parent] = true; level[parent] = 0;
    while (!q.empty()) {
        parent = q.front(); q.pop();
        for (auto child : adj[parent]) {
            if (visited[child] == false) {
                q.push(child); visited[child] = true;
                level[child] = level[parent] + 1; s.push(child);
            }
        }
    }
    while (!s.empty()) {
        cout << s.top() << " "; s.pop();
    }
}

int main() {
    int vertices, edges; cin >> vertices >> edges;
    for (int i = 1; i <= vertices; i++) {
        int parent, child; cin >> parent >> child;
        adj[parent].push_back(child); adj[child].push_back(parent);
    }
    bfs(1);
    return 0;
}
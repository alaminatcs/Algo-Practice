#include <bits/stdc++.h>
using namespace std;

const int N = 1e3+7; vector<int> adj[N];
set<int> st; vector<int> cunt; bool visited[N] = {false};

void bfs (int parent) {
    queue<int> q; q.push(parent); visited[parent] = true;
    int cnt = 0;
    while (!q.empty()) {
        parent = q.front(); q.pop(); cnt++;
        for (auto child : adj[parent]) {
            if (visited[child] == false) {
                q.push(child); visited[child] = true;
            }
        }
    }
    if(cnt > 1) cunt.push_back(cnt);
}

int main() {
    int vertices, edges; cin >> vertices >> edges;
    for (int i = 1; i <= edges; i++) {
        int parent, child; cin >> parent >> child;
        adj[parent].push_back(child); adj[child].push_back(parent);
        st.insert(parent); st.insert(child);
    }
    
    for (auto i = st.begin(); i != st.end(); i++) {
        if (visited[*i] == false) bfs(*i);
    }
    sort(cunt.begin(), cunt.end());
    for (auto var : cunt) cout << var << " ";
    return 0;
}
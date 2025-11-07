#include <bits/stdc++.h>
using namespace std;

void bfs(int start, vector<vector<int>>& adj, int n) {
  queue<int> q;
  vector<bool> visit(n, false);

  q.push(start);
  visit[start] = true;

  while(!q.empty()){
    int u = q.front();
    q.pop();
    cout << u << " ";

    for(int v : adj[u]){
        if(!visit[v]) {
            visit[v] = true;
            q.push(v);
        }
    }
  }
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int start;
    cin >> start;

    bfs(start, adj, n);
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, m;
  cin >> n >> m;
  vector<int> par(n);
  par[0] = -1;
  vector<vector<int>> graph(n);
  while (m--) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    graph[v].push_back(u);
    graph[u].push_back(v);
  }

  queue<int> q;
  vector<int> vis(n);
  q.push(0);
  vis[0] = 1;

  while (!q.empty()) {
    auto v = q.front();
    q.pop();

    if (v == n - 1) {
      vector<int> path;
      while (v != -1) {
        path.push_back(v);
        v = par[v];
      }
      reverse(path.begin(), path.end());
      cout << path.size() << '\n';
      for (auto v : path) {
        cout << v + 1 << " ";
      }
      cout << '\n';
      return 0;
    }

    for (auto u : graph[v]) {
      if (vis[u]) continue;
      par[u] = v;
      vis[u] = 1;
      q.push(u);
    }
  }
  cout << "IMPOSSIBLE\n";
}
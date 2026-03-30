#include <bits/stdc++.h>
using namespace std;
array<int, 2> memo[(int)1e5 + 1];
array<int, 2> dp(int u, vector<vector<int>>& graph) {
  if (u == graph.size() - 1) return {1, -1};
  if (memo[u][0] != -1) return memo[u];
  memo[u] = {(int)-1e9, -1};
  for (auto v : graph[u])
    memo[u] = max(array<int, 2>{dp(v, graph)[0] + 1, v}, memo[u]);
  return memo[u];
}
int main() {
  cin.tie(0)->sync_with_stdio(0);
  memset(memo, -1, sizeof(memo));
  int n, m;
  cin >> n >> m;
  vector<vector<int>> graph(n);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    graph[--u].push_back(--v);
  }
  array<int, 2> ma = dp(0, graph);
  vector<int> path;
  int par = 0;
  while (par != -1) {
    path.push_back(par);
    par = memo[par][1];
  }
  if (ma[0] < 0) {
    cout << "IMPOSSIBLE\n";
    return 0;
  }
  cout << ma[0] << '\n';
  for (int i = 0; i < path.size(); i++) {
    cout << path[i] + 1 << " ";
  }
  cout << '\n';
}
#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;

#define int long long

signed main() {
  int n, m;
  cin >> n >> m;
  vector<vector<array<int, 2>>> adj(n);
  for (int i = 0; i < m; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    adj[a - 1].push_back({b - 1, c});
  }
  priority_queue<array<int, 2>, vector<array<int, 2>>, greater<array<int, 2>>>
      pq;
  pq.push({0, 0});
  // weight, num % MOD, min, max
  vector<array<int, 4>> curinfo(n);
  for (int i = 0; i < n; i++) {
    curinfo[i] = {(int)1e15, 0, 0, 0};
  }
  curinfo[0] = {0, 1, 0, 0};
  while (!pq.empty()) {
    auto [w, u] = pq.top();
    // cout << w << ' ' << u << endl;
    pq.pop();
    if (w > curinfo[u][0]) continue;
    for (auto [v, vW] : adj[u]) {
      if (w + vW == curinfo[v][0]) {
        curinfo[v][1] = (curinfo[v][1] + curinfo[u][1]) % mod;
        curinfo[v][2] = min(curinfo[v][2], curinfo[u][2] + 1);
        curinfo[v][3] = max(curinfo[v][3], curinfo[u][3] + 1);
      } else if (w + vW < curinfo[v][0]) {
        curinfo[v][0] = w + vW;
        curinfo[v][1] = curinfo[u][1];
        curinfo[v][2] = curinfo[u][2] + 1;
        curinfo[v][3] = curinfo[u][3] + 1;
        pq.push({w + vW, v});
      }
    }
  }
  auto x = curinfo[n - 1];
  cout << x[0] << " " << x[1] << " " << x[2] << " " << x[3] << endl;

#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, m;
  cin >> n >> m;
  vector<vector<array<int, 2>>> gr(n);
  while (m--) {
    int u, v, w;
    cin >> u >> v >> w;
    gr[--u].push_back({--v, w});
  }
  priority_queue<array<ll, 3>, vector<array<ll, 3>>, greater<array<ll, 3>>> pq;
  pq.push({0, 0, 0});
  vector<array<ll, 2>> dist(n, {(ll)1e18, (ll)1e18});
  dist[0][0] = 0;
  while (!pq.empty()) {
    auto [cost, u, f] = pq.top();
    pq.pop();
    if (cost > dist[u][f]) continue;
    for (auto [v, w] : gr[u]) {
      if (cost + w < dist[v][f]) {
        dist[v][f] = cost + w;
        pq.push({cost + w, v, f});
      }
      if (!f && cost + w / 2 < dist[v][1]) {
        dist[v][1] = cost + w / 2;
        pq.push({cost + w / 2, v, 1});
      }
    }
  }
  cout << min(dist[n - 1][0], dist[n - 1][1]) << '\n';
}
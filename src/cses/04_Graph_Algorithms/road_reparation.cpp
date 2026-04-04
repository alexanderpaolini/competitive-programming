#include <bits/stdc++.h>
using namespace std;
#define ll long long
struct dsu {
  vector<int> par, siz;
  dsu(int n) {
    siz = par = vector<int>(n, 1);
    iota(par.begin(), par.end(), 0);
  }
  int find(int a) {
    if (par[a] != a) par[a] = find(par[a]);
    return par[a];
  }
  bool join(int a, int b) {
    a = find(a), b = find(b);
    if (a == b) return false;
    if (siz[a] < siz[b]) swap(a, b);
    par[b] = a, siz[a] += siz[b];
    return true;
  }
};
int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, m;
  cin >> n >> m;
  vector<array<int, 3>> edges;
  while (m--) {
    int a, b, w;
    cin >> a >> b >> w;
    edges.push_back({w, --a, --b});
  }
  sort(edges.begin(), edges.end());
  dsu ds(n);
  ll total = 0;
  int con = 0;
  for (auto& [w, u, v] : edges) {
    if (!ds.join(u, v)) continue;
    total += w;
    con++;
  }
  if (con == n - 1)
    cout << total << '\n';
  else
    cout << "IMPOSSIBLE\n";
}
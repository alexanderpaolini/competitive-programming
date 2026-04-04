#include <bits/stdc++.h>
#define ll long long
using namespace std;
struct DSU {
  vector<int> par, siz;
  DSU(int n) {
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
    par[b] = a;
    siz[a] += siz[b];
    return true;
  }
};
int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, m;
  cin >> n >> m;
  DSU ds(n);
  int con = 0, lg = 1;
  while (m--) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    if (ds.join(u, v)) con++;
    lg = max(lg, ds.siz[ds.find(u)]);
    cout << n - con << " " << lg << '\n';
  }
}
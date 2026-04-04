#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct UF {
  vector<int> par, siz;
  UF(int n) {
    siz = par = vector<int>(n, 1);
    iota(par.begin(), par.end(), 0);
  }
  int find(int a) {
    if (par[a] != a) par[a] = find(par[a]);
    return par[a];
  }
  bool join(int a, int b) {
    a = find(a);
    b = find(b);
    if (a == b) return false;
    if (siz[a] < siz[b]) swap(a, b);
    par[b] = a;
    siz[a] += siz[b];
    return true;
  }
};

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, m, k;
  cin >> n >> m >> k;
  set<pair<int, int>> edj;
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    if (b < a) swap(a, b);
    edj.insert({a, b});
  }
  vector<pair<int, int>> vec;
  for (int i = 0; i < k; i++) {
    int a, b;
    cin >> a >> b;
    if (b < a) swap(a, b);
    vec.push_back({a, b});
    edj.erase({a, b});
  }
  reverse(vec.begin(), vec.end());
  UF dsu(n + 2);
  int conn = n;
  for (auto& [v, u] : edj)
    if (dsu.join(v, u)) conn--;
  vector<int> res;
  for (auto& [v, u] : vec) {
    res.push_back(conn);
    if (dsu.join(v, u)) conn--;
  };
  reverse(res.begin(), res.end());
  for (auto x : res) cout << x << " ";
  cout << '\n';
}

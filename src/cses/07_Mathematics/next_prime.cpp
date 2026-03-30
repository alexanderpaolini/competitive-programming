#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<int> primes;
bool isp(ll x) {
  for (int p : primes) {
    if (x == p) return true;
    if (x % p == 0) return false;
  }
  return true;
}
signed main() {
  vector<int> pnp(1e6 + 1, 0);
  for (int i = 2; i < 1e6 + 1; i++) {
    if (pnp[i]) continue;
    ll x = (ll)i * i;
    while (x < 1e6 + 1) {
      pnp[x]++;
      x += i;
    }
    primes.push_back(i);
  }
  int n;
  cin >> n;
  while (n--) {
    ll x;
    cin >> x;
    x++;
    while (!isp(x)) x++;
    cout << x << endl;
  }
}
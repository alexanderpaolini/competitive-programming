#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int memo[(int)1e6 + 1];
#define ll long long
int expo(ll a, ll b) {
  if (b == 0) return 1;
  if (b == 1) return a % mod;
  if (b % 2 == 1) return (a * expo(a, b - 1)) % mod;
  ll x = expo(a, b / 2);
  return (x * x) % mod;
}
int fac(int n) {
  if (n <= 1) return 1;
  if (memo[n] != -1) return memo[n];
  return memo[n] = ((ll)fac(n - 1) * n) % mod;
}
int main() {
  memset(memo, -1, sizeof(memo));
  cin.tie(0)->sync_with_stdio(0);
  int n;
  cin >> n;
  while (n--) {
    int a, b;
    cin >> a >> b;
    int x = ((ll)fac(b) * fac(a - b)) % mod;
    x = expo(x, mod - 2);
    cout << ((ll)fac(a) * x) % mod << '\n';
  }
}
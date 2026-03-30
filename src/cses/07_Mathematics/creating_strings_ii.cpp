#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int MOD = 1e9 + 7;
int expo(ll a, ll b) {
  if (b == 0) return 1;
  if (b == 1) return a % MOD;
  if (b % 2 == 1) return (a * expo(a, b - 1)) % MOD;
  ll x = expo(a, b / 2);
  return (x * x) % MOD;
}
int inv(ll a) { return expo(a, MOD - 2); }
int memo[(int)1e6 + 1];
int fac(ll n) {
  if (n == 1) return 1;
  if (memo[n] != -1) return memo[n];
  return memo[n] = (n * fac(n - 1)) % MOD;
}
int main() {
  cin.tie(0)->sync_with_stdio(0);
  memset(memo, -1, sizeof(memo));
  string s;
  cin >> s;
  vector<int> freq(26);
  for (auto c : s) freq[c - 'a']++;
  ll res = fac(s.size());
  for (auto x : freq)
    if (x) res = (res * inv(fac(x))) % MOD;
  cout << res << '\n';
}
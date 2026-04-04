#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vl = vector<ll>;
using vd = vector<ld>;
using vii = vector<pii>;
using vll = vector<pll>;
using vvi = vector<vi>;

#define pb push_back
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define rep(i, a, b) for (int i = a; i < (b); ++i)

const ll MODVAL = 1e9 + 7;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);

  int n, x;
  cin >> n >> x;

  vector<int> coins(n, 0);
  vector<ll> dp(1e6 + 1, 0);

  dp[0] = 1;
  rep(i, 0, n) {
    cin >> coins[i];
  }

  for (int c : coins) {
    dp[c]++;
    for (int i = 0; i <= x; i++) {
      if (i - c > 0) {
        dp[i] = (dp[i] + dp[i - c]) % MODVAL;
      }
    }
  }

  cout << dp[x] << endl;

  return 0;
}

// 1 - 0
// 2 - 1
// 3 - 1
// 4 - 1
// 5 - 2
// 6 - 2
// 7 - 2
// 8 - 3
// 9 - 1 + 2 = 3
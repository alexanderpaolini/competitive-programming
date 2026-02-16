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

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int n, x;
    cin >> n >> x;

    vector<int> coins(n);
    vector<int> dp(1e6 + 1, 1e9);
    dp[0] = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> coins[i];
        dp[coins[i]] = 1;
    }

    for (int i = 0; i <= x; i++)
    {
        for (int c : coins)
        {
            if (i - c < 0)
                continue;
            dp[i] = min(dp[i], dp[i - c] + 1);
        }
    }

    cout << (dp[x] >= 1e8 ? -1 : dp[x]) << endl;

    return 0;
}

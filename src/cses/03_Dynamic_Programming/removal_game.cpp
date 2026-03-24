#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<vector<ll>> memo;
vector<int> mov;
const ll ma = -1e18;
ll dp(int l, int r, int move)
{
    // if (l >= memo.size() || r < 0)
    //     return 1e9;
    if (r == l)
        return move == 0 ? mov[r] : 0;
    if (memo[l][r] != ma)
        return memo[l][r];
    ll res;
    if (move == 1)
        res = min(dp(l + 1, r, !move), dp(l, r - 1, !move));
    else
        res = max(dp(l + 1, r, !move) + mov[l], dp(l, r - 1, !move) + mov[r]);
    memo[l][r] = res;
    return res;
}
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin >> n;
    memo = vector<vector<ll>>(n, vector<ll>(n, ma));
    mov = vector<int>(n);
    for (int i = 0; i < n; i++)
        cin >> mov[i];
    cout << dp(0, n - 1, 0) << "\n";
}
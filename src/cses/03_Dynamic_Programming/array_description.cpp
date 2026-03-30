#include <bits/stdc++.h>
using namespace std;
int memo[100001][101];
const int MOD = 1e9 + 7;
int dp(vector<int> &guys, int i, int v, int m)
{
    if (v > m || v <= 0)
        return 0;
    if (guys[i] != 0 && guys[i] != v)
        return 0;
    if (i == 0 && (guys[i] == v || guys[i] == 0))
        return 1;
    if (memo[i][v] != -1)
        return memo[i][v];
    memo[i][v] = ((dp(guys, i - 1, v - 1, m) +
                   dp(guys, i - 1, v, m)) % MOD +
                  dp(guys, i - 1, v + 1, m)) %
                 MOD;
    return memo[i][v];
}
int main()
{
    memset(memo, -1, sizeof(memo));
    int n, m;
    cin >> n >> m;
    vector<int> guys(n);
    for (int i = 0; i < n; i++)
        cin >> guys[i];
    int res = 0;
    for (int i = 1; i <= m; i++)
    {
        res = (res + dp(guys, n - 1, i, m)) % MOD;
    }
    cout << res << '\n';
}
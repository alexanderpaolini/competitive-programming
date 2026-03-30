#include <bits/stdc++.h>
using namespace std;
int dp(vector<vector<int>> &memo, vector<int> &arr, int i, int x)
{
    if (i == arr.size())
        return 0;
    if (memo[i][x] != -1)
        return memo[i][x];
    int res = 1e9;
    for (int j = 1; j <= 6; j++)
    {
        if (j == x)
            continue;
        if (j == 7 - x)
            continue;
        res = min(
            res,
            (j == arr[i] ? 0 : 1) + dp(memo, arr, i + 1, j));
    }
    return memo[i][x] = res;
}
void solve()
{
    int n;
    cin >> n;
    vector<int> d(n);
    for (int i = 0; i < n; i++)
        cin >> d[i];
    vector<vector<int>> memo(n, vector<int>(7, -1));
    int res = 1e9;
    for (int i = 1; i <= 6; i++)
    {
        res = min(
            res,
            (i == d[0] ? 0 : 1) + dp(memo, d, 1, i));
    }
    cout << res << '\n';
}
int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
}
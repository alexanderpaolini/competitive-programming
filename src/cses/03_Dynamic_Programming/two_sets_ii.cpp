#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
int memo[501][500 * (500 + 1) / 2 + 1];
int dp(vector<int> &guys, int i, int sum)
{
    if (i == guys.size())
        return (2 * sum == guys.size() * (guys.size() + 1) / 2);
    if (memo[i][sum] != -1)
        return memo[i][sum];
    return memo[i][sum] = (dp(guys, i + 1, sum + guys[i]) + dp(guys, i + 1, sum)) % MOD;
}
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    memset(memo, -1, sizeof(memo));
    int n;
    cin >> n;
    vector<int> guys(n);
    for (int i = 1; i <= n; i++)
        guys[i - 1] = i;
    cout << dp(guys, 1, 1) << endl;
}

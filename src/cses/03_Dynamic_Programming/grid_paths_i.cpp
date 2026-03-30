#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
int dp(vector<string> &grid, vector<vector<int>> &memo, int i, int j)
{
    if (i < 0 || j < 0)
        return 0;
    if (grid[i][j] == '*')
        return 0;
    if (i == 0 && j == 0)
        return 1;
    if (memo[i][j] != -1)
        return memo[i][j];
    return memo[i][j] = (dp(grid, memo, i - 1, j) + dp(grid, memo, i, j - 1)) % MOD;
}
int main()
{
    int n;
    cin >> n;
    vector<string> x(n);
    for (int i = 0; i < n; i++)
    {
        cin >> x[i];
    }
    vector<vector<int>> memo(n + 1, vector<int>(n + 1, -1));
    cout << dp(x, memo, n - 1, n - 1) << endl;
}
#include <bits/stdc++.h>
using namespace std;
int ma = 1e9;
int solve(vector<vector<int>> &memo, int l, int w)
{
    if (l > w)
        swap(l, w);
    if (l == w)
        return 0;
    if (memo[l][w] != ma)
        return memo[l][w];
    for (int i = 1; i < l; i++)
    {
        memo[l][w] = min(memo[l][w], 1 + solve(memo, i, w) + solve(memo, l - i, w));
    }
    for (int i = 1; i < w; i++)
    {
        memo[l][w] = min(memo[l][w], 1 + solve(memo, l, i) + solve(memo, l, w - i));
    }
    return memo[l][w];
}
int main()
{
    int l, w;
    cin >> l >> w;
    int x = max(l, w) + 1;
    vector<vector<int>> memo(x, vector<int>(x, ma));
    cout << solve(memo, l, w) << endl;
}
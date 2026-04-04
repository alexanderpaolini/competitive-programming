#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < (b); i++)
int memo[501][501][501];
int dp(vector<vector<int>> graph, int a, int b, int k)
{
    if (a == b)
        return 0;
    if (memo[a][b][k] != 1e9)
        return memo[a][b][k];
    memo[a][b][k] = graph[a][b];
    for (int i = 0; i < k; i++)
    {
        memo[a][b][k] = min();
    }
    return memo[a][b][k];
}
int main()
{
    memset(memo, 1e9, sizeof(memo));
    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<int>> gr(n, vector<int>(n, 1e9));
    rep(i, 0, n)
    {
        int a, b, c;
        cin >> a >> b >> c;
        gr[a][b] = c;
        gr[b][a] = c;
    }
    rep(i, 0, m)
    {
        int a, b;
        cin >> a >> b;
        int res = dp(gr, a, b, n);
        if (res == 1e9)
            cout << -1 << endl;
        else
            cout << res << endl;
    }
}
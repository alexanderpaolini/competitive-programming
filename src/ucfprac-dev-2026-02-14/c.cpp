#include <bits/stdc++.h>

using namespace std;

int dfs(vector<vector<pair<int, int>>> &AL, int s, int c)
{
    int res = c;
    for (auto &x : AL[s])
    {
        res = max(res, dfs(AL, x.first, c + x.second));
    }
    return res;
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> AL(m);

    for (int i = 0; i < n; i++)
    {
        int s, t, c;
        cin >> s >> t >> c;
        s--;
        t--;
        AL[s].push_back({t, c});
    }

    int res = -1;
    for (int i = 0; i < n; i++)
    {
        res = max(res, dfs(AL, i, 0));
    }

    cout << res << endl;
}
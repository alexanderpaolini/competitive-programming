#include <bits/stdc++.h>

using namespace std;

using pli = pair<long long, int>;

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    int n, m;
    cin >> n >> m;
    priority_queue<pli, vector<pli>, greater<pli>> q;
    q.emplace(0, 0);
    vector<vector<pair<int, int>>> AL(n);
    vector<long long> dist(n, 1e15);
    dist[0] = 0;
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        AL[a - 1].emplace_back(b - 1, c);
    }
    while (!q.empty())
    {
        auto [cost, u] = q.top();
        q.pop();
        if (cost > dist[u])
            continue;
        for (auto [v, w] : AL[u])
        {
            if (cost + w < dist[v])
            {
                dist[v] = cost + w;
                q.emplace(cost + w, v);
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << dist[i] << " ";
    }
    cout << endl;
}
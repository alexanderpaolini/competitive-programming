#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<pair<int, int>> q;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        q.push_back({a, 1});
        q.push_back({b, -1});
    }
    int mx = 0;
    int cur = 0;
    sort(q.begin(), q.end());
    for (int i = 0; i < 2 * n; i++)
    {
        cur += q[i].second;
        mx = max(mx, cur);
    }
    cout << mx << endl;
}
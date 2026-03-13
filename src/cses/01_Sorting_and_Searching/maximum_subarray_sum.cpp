#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
    int n;
    cin >> n;
    int x;
    cin >> x;
    int cur = x;
    int best = x;
    for (int i = 1; i < n; i++)
    {
        cin >> x;
        cur = max(cur + x, x);
        best = max(cur, best);
    }
    cout << best << endl;
}
#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define ll long long
void solve()
{
    int n;
    cin >> n;
    vector<int> ns(n);
    rep(i, 0, n) cin >> ns[i];
    for (int mask = 1; mask < pow(2, n); mask++)
    {
        ll p = 1;
        for (int i = 0; i < n; i++)
        {
            if ((1 << i) & mask)
                p *= ns[i];
        }
        if (p == 67)
        {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
}
int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
}
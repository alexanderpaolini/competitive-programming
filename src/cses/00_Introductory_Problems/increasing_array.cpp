#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < (b); ++i)
using ll = long long;
int main()
{
    int n;
    cin >> n;
    vector<int> xx(n);
    rep(i, 0, n) cin >> xx[i];
    ll res = 0;
    rep(i, 1, n)
    {
        res += max(0, xx[i - 1] - xx[i]);
        xx[i] = max(xx[i - 1], xx[i]);
    };
    cout << res << endl;
}
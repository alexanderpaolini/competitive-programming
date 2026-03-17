#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < (b); i++)
#define int long long
signed main()
{
    int n, k;
    cin >> n >> k;
    vector<int> kss(k);
    rep(i, 0, k) cin >> kss[i];
    int res = 0;
    for (int mask = 1; mask < (1 << k); mask++)
    {
        long long x = n;
        for (int i = 0; i < k; i++)
        {
            if ((1 << i) & mask)
                x /= kss[i];
        }
        if (__builtin_popcount(mask) % 2 == 1)
            res += x;
        else
            res -= x;
    }
    cout << res << endl;
}
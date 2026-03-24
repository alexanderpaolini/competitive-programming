#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
#define ll long long
ll fme(ll a, ll b)
{
    if (b == 0)
        return 1;
    if (b == 1)
        return a % MOD;
    if (b % 2)
        return ((a % MOD) * (fme(a, b - 1) % MOD)) % MOD;
    ll x = fme(a, b / 2);
    return (x * x) % MOD;
}
signed main()
{
    int n;
    cin >> n;
    cout << fme(2, n) << endl;
}
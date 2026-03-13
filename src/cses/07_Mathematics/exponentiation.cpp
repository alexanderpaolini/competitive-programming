#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < (b); i++)
#define ll long long
const int MOD = 1e9 + 7;
ll exp(ll a, ll b)
{
    if (b == 0)
        return 1;
    if (b == 1)
        return a;
    if (b % 2 == 1)
        return ((a % MOD) * (exp(a, b - 1) % MOD)) % MOD;
    return ((exp(a, b / 2) % MOD) * (exp(a, b / 2) % MOD)) % MOD;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll a, b;
        cin >> a >> b;
        cout << exp(a, b) % MOD << endl;
    }
}
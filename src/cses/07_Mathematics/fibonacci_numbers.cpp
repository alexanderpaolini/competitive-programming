#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int MOD = 1e9 + 7;
int main()
{
    ll n;
    cin >> n;
    ll a = 0;
    ll b = 1;
    ll c;
    while (n--)
    {
        c = (a + b) % MOD;
        a = b;
        b = c;
    }
    cout << c << endl;
}
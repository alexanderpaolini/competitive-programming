#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < (b); i++)
#define vi vector<int>
struct UF
{
    vi e;
    UF(int n) : e(n, -1) {}
    bool sameSet(int a, int b) { return find(a) == find(b); }
    int size(int x) { return -e[find(x)]; }
    int find(int x) { return e[x] < 0 ? x : e[x] = find(e[x]); }
    bool join(int a, int b)
    {
        a = find(a), b = find(b);
        if (a == b)
            return false;
        if (e[a] > e[b])
            swap(a, b);
        e[a] += e[b];
        e[b] = a;
        return true;
    }
};
void solve()
{
    int n;
    cin >> n;
    UF x(n + 1);
    vector<int> ns(n);
    rep(i, 0, n)
    {
        cin >> ns[i];
    }
    for (int i = 1; i <= n / 2; i++)
    {
        x.join(ns[i - 1], ns[2 * i - 1]);
    }
    for (int i = 1; i <= n; i++)
    {
        if (!x.sameSet(ns[i - 1], i))
        {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}
int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
}
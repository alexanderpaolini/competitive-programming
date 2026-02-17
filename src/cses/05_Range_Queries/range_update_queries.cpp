#include <bits/stdc++.h>

#define IDEMPOTENT_VALUE 0

using namespace std;
using ll = long long;

struct node
{
    int lo, hi, mid;
    ll val, delta;
    node *left;
    node *right;
    node(int l, int r)
    {
        lo = l;
        hi = r;
        mid = (lo + hi) / 2;
        val = delta = 0;
        if (lo == hi)
            return;
        left = new node(l, mid);
        right = new node(mid + 1, r);
    }
    void prop()
    {
        left->delta += delta;
        right->delta += delta;
        delta = 0;
    }
    ll value() { return val + (delta * (hi - lo + 1)); }
    ll merge(ll left, ll right) { return left + right; }
    ll query(int l, int r)
    {
        if (l > hi || r < lo)
            return 0;
        if (l <= lo && hi <= r)
            return value();
        prop();
        val = merge(left->value(), right->value());
        return left->query(l, r) + right->query(l, r);
    }
    void update(int l, int r, int v)
    {
        if (l > hi || r < lo)
            return;
        if (l <= lo && hi <= r)
            return void(delta += v);
        prop();
        left->update(l, r, v);
        right->update(l, r, v);
        val = merge(left->value(), right->value());
    }
};

int main()
{
    int n, q;
    cin >> n >> q;
    node seg(0, n);
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        seg.update(i, i, x);
    }
    while (q--)
    {
        int v;
        cin >> v;
        if (v == 1)
        {
            int a, b, u;
            cin >> a >> b >> u;
            seg.update(a - 1, b - 1, u);
        }
        else
        {
            int i;
            cin >> i;
            cout << seg.query(i - 1, i - 1) << endl;
        }
    }
}
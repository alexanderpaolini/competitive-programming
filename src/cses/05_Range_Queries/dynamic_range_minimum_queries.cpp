#include <bits/stdc++.h>

using namespace std;

struct node
{
    int hi, lo, mid;
    long long val;
    node *right, *left;
    node(int l, int r)
    {
        lo = l;
        hi = r;
        mid = (hi + lo) / 2;
        val = 1e9;
        if (l == r)
            return;
        left = new node(l, mid);
        right = new node(mid + 1, r);
    }
    long long query(int l, int r)
    {
        if (l > hi || r < lo)
            return 1e9;
        if (l <= lo && r >= hi)
            return val;
        return min(right->query(l, r), left->query(l, r));
    }
    void update(int k, int v)
    {
        if (hi == lo)
            return void(val = v);
        if (k <= mid)
        {
            left->update(k, v);
        }
        else
        {
            right->update(k, v);
        }
        val = min(left->val, right->val);
    }
};

int main()
{
    int n, q;
    cin >> n >> q;
    node seg(0, n);
    for (int i = 0; i < n; i++)
    {
        int v;
        cin >> v;
        seg.update(i, v);
    }
    while (q--)
    {
        int x;
        cin >> x;
        if (x == 1)
        {
            int k, u;
            cin >> k >> u;
            seg.update(k - 1, u);
        }
        else
        {
            int a, b;
            cin >> a >> b;
            cout << seg.query(a - 1, b - 1) << endl;
        }
    }
}
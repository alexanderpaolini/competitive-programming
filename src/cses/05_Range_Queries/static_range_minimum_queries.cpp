#include <bits/stdc++.h>

#define IDEMPOTENT_VALUE 1e9

using namespace std;

int merge(int left, int right)
{
    return min(left, right);
}

struct node
{
    int lo, hi, mid, val;
    node *left;
    node *right;
    node(int l, int r)
    {
        lo = l;
        hi = r;
        mid = (lo + hi) / 2;
        val = IDEMPOTENT_VALUE;
        if (l == r)
            return;
        left = new node(l, mid);
        right = new node(mid + 1, r);
    }
    int query(int l, int r)
    {
        if (hi < l || r < lo)
            return IDEMPOTENT_VALUE;
        if (l <= lo && hi <= r)
            return val;
        return merge(left->query(l, r), right->query(l, r));
    }
    void update(int i, int n)
    {
        if (lo == hi)
            return void(val = n);
        if (i <= mid)
            left->update(i, n);
        else
            right->update(i, n);
        val = merge(left->val, right->val);
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
        seg.update(i, x);
    }
    int a, b;
    while (q--)
    {
        cin >> a >> b;
        // off by one
        cout << seg.query(a - 1, b - 1) << endl;
    }
}
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> a(n);
    vector<int> b(m);

    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < m; i++)
        cin >> b[i];

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int ai = 0;
    int bi = 0;

    int res = 0;
    while (ai < a.size() && bi < b.size())
    {
        if (a[ai] <= b[bi] + k && a[ai] >= b[bi] - k)
        {
            res++;
            ai++;
            bi++;
            continue;
        }

        if (a[ai] < b[bi] - k)
            ai++;
        else
            bi++;
    }

    cout << res << endl;
}
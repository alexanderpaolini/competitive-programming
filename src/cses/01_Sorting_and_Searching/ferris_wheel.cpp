#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, x;
    cin >> n >> x;
    vector<int> ps(n);
    for (int i = 0; i < n; i++)
    {
        cin >> ps[i];
    }
    sort(ps.begin(), ps.end());
    int L = 0, R = ps.size() - 1;
    int res = 0;
    while (L <= R)
    {
        if (ps[L] + ps[R] <= x)
        {
            L++;
        }
        R--;
        res++;
    }
    cout << res << endl;
}
// 2 3 7 9
//   |
#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < (b); i++)
#define ll long long
int main()
{
    int n;
    cin >> n;
    map<int, int> midx;
    rep(i, 0, n)
    {
        int a;
        cin >> a;
        midx[a] = i;
    };
    int idx = 0;
    int cnt = 1;
    for (int i = 1; i <= n; i++)
    {
        if (midx[i] < idx)
        {
            cnt++;
        }
        idx = midx[i];
    }
    cout << cnt << endl;
}
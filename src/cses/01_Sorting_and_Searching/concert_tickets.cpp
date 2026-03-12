#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    multiset<int> tickets;
    int a;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        tickets.insert(a);
    };
    int p;
    for (int i = 0; i < m; i++)
    {
        cin >> p;
        auto x = tickets.upper_bound(p);
        if (x == tickets.begin())
        {
            cout << -1 << endl;
        }
        else
        {
            cout << *(--x) << endl;
            tickets.erase(x);
        }
    }
}
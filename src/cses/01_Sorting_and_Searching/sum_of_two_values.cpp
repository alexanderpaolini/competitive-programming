#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, x;
    cin >> n >> x;
    map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        if (mp[a])
        {
            cout << mp[a] << " " << i + 1 << endl;
            return 0;
        }
        mp[x - a] = i + 1;
    }
    cout << "IMPOSSIBLE" << endl;
}
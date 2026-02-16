#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> heroes(n), vilians(n), res(n);
    for (int i = 0; i < n; i++)
    {
        cin >> heroes[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> vilians[i];
    }

    for (int i = 0; i < n; i++)
    {
        res[i] = vilians[i] - heroes[i];
    }

    if (res[0] < 0)
    {
        cout << 0 << endl;
        return 0;
    }

    int tobeat = res[0];
    for (int i = 0; i < n; i++)
    {
        if (res[i] > tobeat)
        {
            cout << tobeat + 1 << endl;
            return 0;
        }
        if (res[i] < tobeat)
        {
            cout << tobeat << endl;
            return 0;
        }
        if (i == n - 1)
        {
            cout << tobeat << endl;
            return 0;
        }
    }

    cout << tobeat + 1 << endl;
}
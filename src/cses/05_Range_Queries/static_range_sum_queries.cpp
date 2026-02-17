#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long n, q;
    cin >> n >> q;
    vector<long long> vals(n + 1, 0);
    for (long long i = 1; i <= n; i++)
    {
        cin >> vals[i];
    }
    for (long long i = 1; i <= n; i++)
    {
        vals[i] += vals[i - 1];
    }

    while (q--)
    {
        long long a, b;
        cin >> a >> b;
        cout << vals[b] - vals[a - 1] << endl;
    }
}

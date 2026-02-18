#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long n, k;
    cin >> n >> k;
    long long x, a, b, c;
    cin >> x >> a >> b >> c;
    vector<long long> guys;
    guys.push_back(x);
    for (int i = 1; i < n; i++)
    {
        guys.push_back((a * guys[i - 1] + b) % c);
    }

    long long s = 0;
    long long end = 0;
    for (int i = 0; i < k; i++)
    {
        s ^= guys[i];
    }
    end ^= s;

    for (int i = k; i < n; i++)
    {
        s ^= guys[i];
        s ^= guys[i - k];
        end ^= s;
    }

    cout << end << endl;
}
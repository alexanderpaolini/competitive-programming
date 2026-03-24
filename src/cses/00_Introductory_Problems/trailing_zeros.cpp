#include <bits/stdc++.h>
using namespace std;
int zeros(int n)
{
    int z = 0;
    for (int d = 5; d <= n; d *= 5)
        z += n / d;
    return z;
}
int main()
{
    int n;
    cin >> n;
    cout << zeros(n) << endl;
}
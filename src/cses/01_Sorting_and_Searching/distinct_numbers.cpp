#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    set<int> x;
    while (n--)
    {
        int a;
        cin >> a;
        if (x.count(a) == 0)
            x.insert(a);
    }
    cout << x.size() << endl;
}
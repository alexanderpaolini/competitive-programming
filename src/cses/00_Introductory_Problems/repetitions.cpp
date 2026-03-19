#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin >> s;
    int L = 0;
    int R = 1;
    int mx = 1;
    while (R < s.size())
    {
        if (L > s.size())
            break;
        if (s[L] == s[R])
        {
            R++;
            mx = max(mx, R - L);
        }
        else
        {
            L = R;
            R = L + 1;
        }
    }
    cout << mx << endl;
}
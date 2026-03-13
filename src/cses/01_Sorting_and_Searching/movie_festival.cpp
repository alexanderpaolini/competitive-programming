#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<pair<int, int>> finishstart;
    for (int i = 0; i < n; i++)
    {
        int s, f;
        cin >> s >> f;
        finishstart.push_back({f, s});
    }
    sort(finishstart.begin(), finishstart.end());
    int res = 0;
    int end = 0;
    for (auto [f, s] : finishstart)
    {
        if (s >= end)
        {
            res++;
            end = f;
        }
    }
    cout << res << endl;
}
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> lens(n);
    for (int i = 0; i < n; i++)
        cin >> lens[i];
    sort(lens.begin(), lens.end());
    int median = lens[lens.size() / 2];
    long long res = 0;
    for (int i = 0; i < lens.size(); i++)
    {
        res += abs(lens[i] - median);
    }
    cout << res << endl;
}
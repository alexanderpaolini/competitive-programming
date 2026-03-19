#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> x;
    x.push_back(0);
    x.push_back(1);
    for (int i = 1; i < n; i++)
    {
        int s = x.size();
        for (int j = s - 1; j >= 0; j--)
        {
            x.push_back(x[j] | (1 << (i)));
        }
    }
    for (auto y : x)
    {
        cout << bitset<16>(y).to_string().substr(16 - n) << endl;
    }
}
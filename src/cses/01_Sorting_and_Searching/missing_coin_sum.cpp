#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i, a, b) for (int i = a; i < (b); i++)
int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    rep(i, 0, n) cin >> nums[i];
    sort(nums.begin(), nums.end());
    ll mi = 0;
    for (auto x : nums)
    {
        if (x <= mi + 1)
            mi += x;
        else
            break;
    }
    cout << mi + 1 << endl;
}
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> nums(n + 1);
    // for (int i = 0; i < n - 1; i++)
    // {
    //     int x;
    //     cin >> x;
    //     nums[x] = 1;
    // }    
    // for (int i = 1; i <= n; i++)
    // {
    //     if (nums[i] == 0)
    //     {
    //         cout << i << endl;
    //         return 0;
    //     }
    // }
    int x = 0;
    for (int i = 1; i <= n; i++)
        x ^= i;
    for (int i = 0; i < n - 1; i++)
    {
        int z;
        cin >> z;
        x ^= z;
    }
    cout << x << endl;
}
#include <bits/stdc++.h>
using namespace std;
int mex(set<int> &arr)
{
    int res = 0;
    while (arr.count(res))
        res++;
    return res;
}
int main()
{
    int n;
    cin >> n;
    vector<vector<int>> gr(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        cout << i << " ";
        gr[0][i] = i;
    }
    cout << endl;
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            set<int> curr;
            for (int r = 0; r < i; r++)
                curr.insert(gr[r][j]);
            for (int c = 0; c < j; c++)
                curr.insert(gr[i][c]);
            gr[i][j] = mex(curr);
            cout << gr[i][j] << " ";
        }
        cout << endl;
    }
}
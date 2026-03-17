#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < (b); i++)
bool isvalid(vector<string> &gr, int r, int c, char ch)
{
    if (gr[r][c] == ch)
        return false;
    if (r == 0)
        return (c == 0 || gr[r][c - 1] != ch);
    if (c == 0)
        return (gr[r - 1][c] != ch);
    return (gr[r - 1][c] != ch && gr[r][c - 1] != ch);
}
bool solve(vector<string> &gr, int i)
{
    int r = i / gr[0].size();
    int c = i % gr[0].size();
    if (r >= gr.size())
        return true;
    auto old = gr[r][c];
    for (auto ch : "ABCD")
        if (isvalid(gr, r, c, ch))
        {
            gr[r][c] = ch;
            return solve(gr, i + 1);
        }
    return false;
}
int main()
{
    int r, c;
    cin >> r >> c;
    vector<string> gr(r);
    rep(i, 0, r) cin >> gr[i];
    if (solve(gr, 0))
        rep(i, 0, r) cout << gr[i] << endl;
    else
        cout << "IMPOSSIBLE" << endl;
}
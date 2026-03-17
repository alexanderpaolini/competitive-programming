#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin >> s;
    vector<int> freq(26);
    for (auto c : s)
        freq[c - 'A']++;
    char odd = 0;
    for (int i = 0; i < 26; i++)
    {
        if (freq[i] % 2)
        {
            if (odd)
            {
                cout << "NO SOLUTION" << endl;
                return 0;
            }
            odd = (char)(i + 'A');
        }
    }
    for (int i = 0; i < 26; i++)
    {
        for (int j = 0; j < (freq[i] / 2); j++)
            cout << (char)(i + 'A');
    }
    if (odd)
        cout << odd;
    for (int i = 25; i >= 0; i--)
    {
        for (int j = 0; j < (freq[i] / 2); j++)
            cout << (char)(i + 'A');
    }
    cout << endl;
}
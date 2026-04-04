#include <bits/stdc++.h>
using namespace std;
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin >> n;
    map<int, int> freq;
    queue<int> ord;
    for (int i = 0; i < n - 2; i++)
    {
        int x;
        cin >> x;
        freq[x]++;
        ord.push(x);
    }
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 1; i <= n; i++)
        if (!freq[i])
            pq.push(i);
    while (!pq.empty() && !ord.empty())
    {
        int x = ord.front();
        ord.pop();

        int y = pq.top();
        pq.pop();

        cout << y << " " << x << "\n";
        freq[x]--;
        if (!freq[x])
            pq.push(x);
    }

    if (!pq.empty())
    {
        int t = pq.top();
        pq.pop();
        cout << t << " " << pq.top() << "\n";
    }
}

// 2 6 2 4
// 1 3 5
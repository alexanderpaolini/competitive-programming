#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<int> d(n + 1, -1);
  d[0] = 0;
  for (int i = 1; i <= n; i++) {
    int x = i;
    d[i] = 1e9;
    while (x) {
      d[i] = min(d[i], 1 + d[i - (x % 10)]);
      x /= 10;
    }
  }
  cout << d[n] << endl;
}
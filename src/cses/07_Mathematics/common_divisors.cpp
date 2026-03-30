#include <bits/stdc++.h>
using namespace std;
int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n;
  cin >> n;
  vector<int> contaons(1e6 + 1, 0);
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    contaons[x]++;
  }
  for (int i = 1e6; i > 0; i--) {
    int cnt = 0;
    int f = i;
    while (f < 1e6 + 1) {
      if (contaons[f]) cnt = contaons[f] + cnt;
      f += i;
    }
    if (cnt >= 2) {
      cout << i << '\n';
      return 0;
    }
  }
  cout << 1 << '\n';
}
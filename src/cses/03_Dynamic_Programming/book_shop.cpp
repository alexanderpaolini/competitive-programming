#include <bits/stdc++.h>
using namespace std;
int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, x;
  cin >> n >> x;
  vector<array<int, 2>> guys(n);
  vector<int> dp(1e5 + 1);
  for (int i = 0; i < n; i++) cin >> guys[i][0];
  for (int i = 0; i < n; i++) cin >> guys[i][1];

  for (int i = 0; i < n; i++) {
    auto guy = guys[i];
    for (int j = 0; j < x - guy[0]; j++) {
    }
  }
}
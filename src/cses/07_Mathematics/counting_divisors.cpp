#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < (b); ++i)
int main() {
  int n;
  cin >> n;
  while (n--) {
    int x;
    cin >> x;
    int cnt = 0;
    for (int i = 1; i * i < x; i++)
      if (x % i == 0) cnt = cnt + 2;
    if ((int)sqrt(x) * (int)sqrt(x) == x) cnt++;
    cout << cnt << endl;
  }
}

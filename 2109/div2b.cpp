#include <bits/stdc++.h>
#define int long long
using namespace std;

int calc(int x)
{
  int cnt = 0;
  while (x)
  {
    if (x & 1)
      cnt++;

    x >>= 1;
  }
  return cnt;
}

void slove()
{
  int n, m, a, b;
  cin >> n >> m >> a >> b;

  cout << min(__bit_width(m - 1) + __bit_width(min(a, n - a + 1) - 1), __bit_width(n - 1) + __bit_width(min(b, m - b + 1) - 1)) + 1 << endl;
}

signed main()
{
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  // int t;
  // cin >> t;
  // while (t--)
  // {
  //   slove();
  // }
  cout << calc(2) << " " << __bit_width(2) << endl;
}
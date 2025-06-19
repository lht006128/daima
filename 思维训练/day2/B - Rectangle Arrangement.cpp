#include <bits/stdc++.h>
#define int long long
using namespace std;

void slove()
{
  int n;
  cin >> n;
  int x = -1, y = -1;
  for (int i = 1; i <= n; i++)
  {
    int tx, ty;
    cin >> tx >> ty;
    x = max(x, tx);
    y = max(y, ty);
  }

  cout << (x + y) * 2 << endl;
}

signed main()
{
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int t;
  cin >> t;
  while (t--)
  {
    slove();
  }
}
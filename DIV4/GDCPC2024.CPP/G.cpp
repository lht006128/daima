#include <bits/stdc++.h>
#define int long long
using namespace std;
int a, b;
bool check(int n)
{
  int be = ceil(1.0 * a / b);
  int ok = 0;
  for (int i = be; i * n <= b; i++)
  {
    if (i * n >= a && i * n <= b)
      ok++;
    if (ok == 2)
      return true;
  }
  return false;
}
signed main()
{
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int t;
  cin >> t;
  while (t--)
  {
    cin >> a >> b;
    int l = 1, r = 1000000000000;
    while (l <= r)
    {
      // cout << check(70) << " this\n";
      int mid = (l + r) >> 1;
      if (check(mid))
      {
        l = mid + 1;
      }
      else
        r = mid - 1;
    }
    cout << l - 1 << endl;
  }
}

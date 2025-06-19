#include <bits/stdc++.h>
#define int long long
using namespace std;

void slove()
{
  int n, k;
  cin >> n >> k;
  int ans = 1;

  ans += k;
  for (int i = 1; i <= k; i++)
  {

    if ((n & 1) && n != 1)
    {
      ans += (k - i);
      ans++;
    }
    else
    {
      ans++;
    }
    n >>= 1;
    if (n == 0)
    {
      break;
    }
  }

  cout << ans << endl;
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
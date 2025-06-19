#include <bits/stdc++.h>
using namespace std;
#define int long long

int a[300000];
int b[300000];
void slove()
{
  int n, k;
  int fb = 0; // 0 则b全是缺失的，可能存在多种情况
  int f = 0;  // 存在多个不缺失 但是已经不互补的情况
  int maxa = -1;
  int mina = 1e10;
  int sum = -1; // 互补数字
  cin >> n >> k;

  for (int i = 1; i <= n; i++)
  {
    cin >> a[i];
    maxa = max(a[i], maxa);
    mina = min(a[i], mina);
  }

  for (int i = 1; i <= n; i++)
  {
    cin >> b[i];
    if (b[i] != -1)
    {
      fb = 1;
      if (sum != -1 && sum != b[i] + a[i])
        f = 1;

      sum = b[i] + a[i];
    }
  }

  if (f)
  {
    cout << 0 << endl;
    return;
  }

  if (fb)
  {
    // 只有 1种或者0 种情况
    for (int i = 1; i <= n; i++)
    {
      int tp;
      tp = sum - a[i];
      if (tp < 0 || tp > k)
      {
        cout << 0 << endl;
        return;
      }
    }
    cout << 1 << endl;
    return;
  }
  else
  {
    // 可以自定义的情况 存在多个解答
    int ans = 0;
    if (mina + k < maxa)
    {
      cout << 0 << endl;
      return;
    }
    else
    {
      ans = (mina + k) - maxa + 1;
      cout << ans << endl;
    }
  }
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

  return 0;
}
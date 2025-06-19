#include <bits/stdc++.h>
using namespace std;
#define int long long
map<int, int> mp;

int a[300000];
int b[300000];
int pre[300000]; // 前缀
int sur[300000]; // 后缀

void slove()
{
  int n, m;
  int now = 1;
  int ans = 1e15;
  cin >> n >> m;
  for (int i = 1; i <= n; i++)
  {
    cin >> a[i];
  }
  pre[0] = 0;
  sur[n + 1] = 0;
  for (int i = 1; i <= m; i++)
  {
    cin >> b[i];
  }

  // 计算前缀
  for (int i = 1; i <= n; i++)
  {
    if (now > m)
    {
      pre[i] = pre[i - 1];
    }
    if (a[i] >= b[now])
    {
      pre[i] = pre[i - 1] + 1;
      now++;
    }
    else
    {
      pre[i] = pre[i - 1];
    }
  }
  now = m;
  // 计算后缀.
  for (int i = n; i >= 1; i--)
  {
    if (now < 1)
    {
      sur[i] = sur[i + 1];
    }
    if (a[i] >= b[now])
    {
      sur[i] = sur[i + 1] + 1;
      now--;
    }
    else
    {
      sur[i] = sur[i + 1];
    }
  }

  // for (int i = 1; i <= n; i++)
  // {
  //   cout << pre[i] << " ";
  // }

  // cout << endl;

  // for (int i = 1; i <= n; i++)
  // {
  //   cout << sur[i] << " ";
  // }
  // cout << endl;
  // 当且仅当
  for (int i = 1; i <= n; i++)
  {
    if (pre[i] + sur[i] == m - 1)
    {
      ans = min(ans, b[pre[i] + 1]);
    }
  }

  if (pre[n] >= m)
  {
    cout << 0 << endl;
    return;
  }
  else
  {
    if (ans >= 1e14)
      cout << -1 << endl;
    else
      cout << ans << endl;
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
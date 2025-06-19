#include <bits/stdc++.h>
#define int long long
using namespace std;

int mod = 998244353;

int a[200010];
int b[200010];
int c[200010];
int d[200010];

signed main()
{
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  map<int, int> mp;
  map<int, int> pos;
  int n;
  cin >> n;

  for (int i = 1; i <= n; i++)
  {
    cin >> a[i];
  }

  for (int i = 1; i <= n; i++)
  {
    cin >> b[i];
    mp[a[i]] = b[i];
  }

  int m;
  cin >> m;

  for (int i = 1; i <= m; i++)
  {
    cin >> c[i];
    pos[c[i]] = i;
  }
  int f = 0;
  for (int i = 1; i <= m; i++)
  {
    cin >> d[i];
    if (mp[c[i]] < d[i])
      f = 1;
  }

  if (f)
  {
    cout << 0;
    return 0;
  }

  int ans = 1;

  for (int i = 1; i <= n; i++)
  {
    if (pos[a[i]] == 0)
    {
      ans = ans * 2 % mod;
    }
    else
    {
      if (b[i] - d[pos[a[i]]] > 0)
      {
        ans = ans * 2 % mod;
      }
      // cout << d[pos[a[i]]] << " ";
    }
    // cout << ans << endl;
  }
  cout << ans;
}
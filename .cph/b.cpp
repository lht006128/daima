#include <bits/stdc++.h>
using namespace std;
#define int long long

int b[300010];
int a[300010];
int qian[300010];
int sum[300010];
map<int, int> mp;
int ans = 0;
signed main()
{
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int n, m, k;
  cin >> n >> m >> k;

  for (int i = 1; i <= m; i++)
  {
    int tp;
    cin >> tp;
    b[tp] = 1;
  }

  for (int i = 1; i <= n; i++)
  {
    cin >> a[i];
  }

  for (int i = 1; i <= n; i++)
  {
    sum[i] = (sum[i - 1] + a[i]) % k;

    if (sum[i] % k == 0 && b[i])
    {
      ans++;
    }

    qian[i] = ans;
    if (sum[i] % k != 0 && b[i])
    {
      mp[sum[i] % k]++;
    }
  }
  int tp;
  ans = 0;
  for (int i = 1; i <= n + 1; i++)
  {
    if (b[i])
    {
      mp[sum[i]]--;
      if (mp[sum[i]] < 0)
        mp[sum[i]] = 0;
    }
    ans = max(ans, qian[i - 1] + mp[a[i] % k]);
  }

  cout << ans;
}
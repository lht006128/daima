#include <bits/stdc++.h>

#define endl '\n'
using namespace std;
int dp[5000000];

int vv[600010];
int ww[600010];

signed main()
{
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int n, V;
  cin >> n >> V;
  int cnt = 1; // 拆分计数
  int val, w, s;
  for (int i = 1; i <= n; i++)
  {
    cin >> val >> w >> s;
    // 多重背包转01 背包 优化时间复杂度 ON^2
    // 二进制拆分
    for (int j = 1; j <= s; j <<= 1)
    {
      ww[cnt] = j * w;
      vv[cnt++] = j * val;
      s -= j;
    }
    if (s)
    {
      ww[cnt] = s * w;
      vv[cnt++] = s * val;
    }
  }

  dp[0] = 0;

  for (int i = 1; i < cnt; i++)
  {
    for (int j = V; j >= 0; j--)
    {
      if (j < ww[i])
      {
        continue;
      }
      dp[j] = max(dp[j], dp[j - ww[i]] + vv[i]);
    }
  }
  int ans = 0;
  for (int i = 0; i <= V; i++)
  {
    ans = max(ans, dp[i]);
  }
  cout << ans;
}
#include <bits/stdc++.h>
#define int long long
using namespace std;
int ans = 0;
int dp[12][90][1000];
int num[2030];

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

signed main()
{
  ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);

  int n, k;
  cin >> n >> k;

  for (int i = 0; i <= 2000; i++)
  {
    num[i] = calc(i);
  }
  dp[0][0][0] = 1;
  for (int i = 1; i <= n; i++)
  {
    for (int w = 0; w <= k; w++)
    {
      //   状态的创建  时间复杂度主要在第二个循环内 最多是 1e3;
      for (int j = 0; j < (1 << n); j++)
      {

        if (num[j] > w)
          continue;

        if (((j << 1) & j))
          continue;
        if (((j >> 1) & j))
          continue;

        for (int st = 0; st < (1 << n); st++)
        {
          if (st & j)
            continue;

          if (((st << 1) & st))
            continue;
          if (((st >> 1) & st))
            continue;
          if ((st << 1) & j)
            continue;
          if ((st >> 1) & j)
            continue;

          dp[i][w][j] += dp[i - 1][w - num[j]][st];
        }
      }
    }
  }

  for (int i = 0; i < (1 << n); i++)
  {
    ans += dp[n][k][i];
  }

  cout << ans;
}
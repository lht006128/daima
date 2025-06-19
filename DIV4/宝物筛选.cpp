#include <bits/stdc++.h>

#define endl '\n'
using namespace std;
int dp[101][50000];
int val[1000010];
int w[1000010];
int m[1000010];
signed main()
{
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int n, V;
  cin >> n >> V;

  for (int i = 1; i <= n; i++)
  {
    cin >> val[i] >> w[i] >> m[i];
  }

  dp[0][0] = 0;

  for (int i = 1; i <= n; i++)
  {

    for (int j = 0; j <= V; j++)
    {
      dp[i][j] = dp[i - 1][j];
      for (int k = 0; k <= m[i]; k++)
      {
        if (k * w[i] > j)
          break;
        dp[i][j] = max(dp[i][j], dp[i - 1][j - k * w[i]] + val[i] * k);
      }
    }
  }
  int ans = 0;
  for (int i = 0; i <= V; i++)
  {
    ans = max(ans, dp[n][i]);
  }
  cout << ans;
}
#include <bits/stdc++.h>
#define int long long
using namespace std;
int mod = 1e6 + 7;
int n, m;
int a[110];
int dp[110][110]; // 选前i 个达到 展现m朵花
signed main()
{
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  cin >> n >> m;

  for (int i = 1; i <= n; i++)
  {
    cin >> a[i];
  }
  dp[0][0] = 1;
  for (int i = 1; i <= n; i++)
  {
    for (int j = 0; j <= m; j++)
    {
      for (int k = 0; k <= j && k <= a[i]; k++)
      {
        dp[i][j] += dp[i - 1][j - k];
        // dp[i][j] %= mod;
      }
    }
  }

  // for (int i = 1; i <= n; i++)
  // {
  //   for (int j = 0; j <= m; j++)
  //   {
  //     cout << dp[i][j] << " ";
  //   }
  //   cout << endl;
  // }

  cout << dp[n][m] % mod;
}
#include <bits/stdc++.h>
#define int long long
#define endl '\n'

using namespace std;
int sum;
int arr[2000];
int add[2000];
int getl(int x)
{
  int l = 0;
  while (x)
  {
    x >>= 1;
    l++;
  }
  return l;
}

int calc(int x)
{
  int l = getl(x);
  int tp = 0;
  for (int i = 1; i <= l; i++)
  {
    if (((x >> (l - i)) & 1))
    {
      tp += (1 << (i - 1));
    }
  }
  return tp;
}
int dp[2000][2000][3];
int qianzhui[2000];
signed main()
{
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int n, m;
  cin >> n >> m;

  for (int i = 1; i <= n; i++)
  {
    cin >> arr[i];
    sum += arr[i];
  }

  for (int i = 1; i <= n; i++)
  {
    add[i] = calc(arr[i]) - arr[i];
    qianzhui[i] = qianzhui[i - 1] + add[i];
  }

  int ans = -1;
  for (int i = 1; i <= n; i++)
  {
    for (int k = 1; k <= i - 1; k++)
    {
      for (int j = 1; j <= min(i, m); j++)
      {
        dp[i][j][0] = max(dp[i][j][0], max(dp[k][j][0], dp[k][j][1]));
        dp[i][j][1] = max(dp[i][j][1], max(dp[k][j - 1][0], dp[k][j - 1][1]) + add[i]);
        dp[i][j][2] = max(dp[i][j][2], max(dp[k][j - 1][0], dp[k][j - 1][1]) + qianzhui[i] - qianzhui[k - 1]);

        dp[i][j][1] = max(dp[i][j][1], dp[i - 1][j][1] + add[i]);
        dp[i][j][2] = max(dp[i][j][2], dp[i - 1][j][1] + add[i]);
      }
    }
  }

  for (int i = 1; i <= m; i++)
  {
    ans = max(ans, max(dp[n][i][1], max(dp[n][i][2], dp[n][i][0])));
  }

  // cout << ans << endl;
  cout << ans + sum;
}
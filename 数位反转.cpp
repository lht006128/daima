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
int dp[2000][2000][2];

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
  }

  for (int i = 1; i <= n; i++)
  {

    for (int j = 1; j <= m; j++)
    {
      dp[i][j][0] = max(dp[i - 1][j][1], dp[i - 1][j][0]);
      dp[i][j][1] = max(dp[i - 1][j - 1][0], dp[i - 1][j][1]) + add[i];
    }
  }

  int ans = 0;
  for (int i = 1; i <= m; i++)
  {
    ans = max(dp[n][i][0], dp[n][i][1]);
  }
  cout << ans + sum;
}
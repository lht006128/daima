#include <bits/stdc++.h>
#define int long long
using namespace std;

int arr[100010];
int dp[100010];
signed main()
{
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int n, m;
  cin >> n >> m;

  for (int i = 1; i <= n; i++)
  {
    int tp;
    cin >> tp;
    if (tp % 2 == 0)
    {
      arr[i] = 0;
    }
    else
    {
      arr[i] = 1;
    }
  }

  dp[1] = 1;
  for (int i = 2; i <= n; i++)
  {
    dp[i] = 1;

    if (arr[i] == 1 && arr[i - 1] == 0)
    {
      dp[i] += dp[i - 1];
    }
    else if (arr[i] == 0 && arr[i - 1] == 1)
    {
      dp[i] += dp[i - 1];
    }
  }
  int maxl = -1;
  for (int i = 1; i <= n; i++)
  {
    maxl = max(maxl, dp[i]);
  }

  if (maxl > m)
  {
    cout << 0;
  }
  else
  {
    cout << (m - maxl + 2) / 2;
  }
}